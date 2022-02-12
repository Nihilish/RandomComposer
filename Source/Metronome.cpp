/*
  ==============================================================================

    Metronome.cpp
    Created: 3 Feb 2022 10:00:25pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include "Metronome.h"

#include "RandomComposerDefaultLookAndFeel.h"
#include "Colours.h"
#include "Defaults.h"

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

void Metronome::timerCallback()
{
    std::invoke(m_Callback);
}

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

void Metronome::start()
{
    if (m_IntervalInMs == 0 || isTimerRunning())
        return;

    startTimer(m_IntervalInMs);
}

void Metronome::stop()
{
    if (!isTimerRunning())
        return;

    stopTimer();
}

void Metronome::setCallback(std::function<void()> callback)
{
    m_Callback = callback;
}

void Metronome::setNoteLength(NoteLength noteLength)
{
    m_NoteLength = noteLength;
    setTimeInterval();
}

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

