/*
  ==================================================================================================================

    Metronome.h
    Created: 3 Feb 2022 10:00:25pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>

/// <summary>
/// Defines possible time values.
/// </summary>
enum class NoteLength
{
    // Whole note
    WHOLE,
    // Half note
    HALF,
    // Quarter note
    QUARTER,
    // Eighth note
    EIGHTH,
    // Sixteenth note
    SIXTEENTH,
    // Thirty-second note
    THIRTY_SECOND,
};

/// <summary>
/// This class is a timer that allows defining a BPM and a note length instead of
/// a simple time interval.
/// </summary>
class Metronome : public juce::Timer
{
public:
    Metronome();
    ~Metronome();

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Timer
    void timerCallback() override;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void setBPM(int BPM);
    void setCallback(std::function<void()> callback);
    void setNoteLength(NoteLength noteLength);
    void start();
    void stop();

private:
    // MEMBER FUNCTIONS
    //==============================================================================================================
    void setTimeInterval();

    // MEMBER VARIABLES
    //==============================================================================================================
    int m_BPM;
    std::function<void()> m_Callback;
    int m_IntervalInMs;
    NoteLength m_NoteLength;
};

