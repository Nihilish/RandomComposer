/*
  ==================================================================================================================

    Metronome.cpp
    Created: 3 Feb 2022 10:00:25pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include "Metronome.h"

#include "Colours.h"
#include "Defaults.h"
#include "RandomComposerDefaultLookAndFeel.h"

Metronome::Metronome() :
    m_BPM(app::Defaults::defaultTempo),
    m_NoteLength(NoteLength::QUARTER),
    m_IntervalInMs(0)
{
    setTimeInterval();
}

Metronome::~Metronome()
{
}

/// <summary>
/// Sets the metronome's BPM.
/// </summary>
/// <param name="BPM">The new BPM.</param>
void Metronome::setBPM(int BPM)
{
    int oldBPM = m_BPM;
    m_BPM = BPM;
    setTimeInterval();

    // Restart the timer when the tempo changes.
    if (oldBPM != m_BPM)
    {
        stop();
        start();
    }
}

/// <summary>
/// Sets the metronome's callback.
/// </summary>
/// <param name="callback">The callback.</param>
void Metronome::setCallback(std::function<void()> callback)
{
    m_Callback = callback;
}

/// <summary>
/// Set the metronome's note length.
/// </summary>
/// <param name="noteLength">The new note length.</param>
void Metronome::setNoteLength(NoteLength noteLength)
{
    m_NoteLength = noteLength;
    setTimeInterval();
}

/// <summary>
/// Sets the timer's time interval depending on the BPM and the note length.
/// </summary>
void Metronome::setTimeInterval()
{
    double multiplier = 1.0;
    switch (m_NoteLength)
    {
    case NoteLength::WHOLE:
        multiplier = 4.0;
        break;
    case NoteLength::HALF:
        multiplier = 2.0;
        break;
    case NoteLength::QUARTER:
        break;
    case NoteLength::EIGHTH:
        multiplier = 0.5;
        break;
    case NoteLength::SIXTEENTH:
        multiplier = 0.25;
        break;
    case NoteLength::THIRTY_SECOND:
        multiplier = 0.125;
        break;
    default:
        break;
    }

    m_IntervalInMs = round((60000.0 / m_BPM) * multiplier);
}

/// <summary>
/// Starts the metronome.
/// </summary>
void Metronome::start()
{
    if (m_IntervalInMs == 0 || isTimerRunning())
        return;

    startTimer(m_IntervalInMs);
}

/// <summary>
/// Stops the metronome.
/// </summary>
void Metronome::stop()
{
    if (!isTimerRunning())
        return;

    stopTimer();
}

void Metronome::timerCallback()
{
    std::invoke(m_Callback);
}