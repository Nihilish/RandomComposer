/*
  ==============================================================================

    Metronome.h
    Created: 3 Feb 2022 10:00:25pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>

enum class NoteLength
{
    WHOLE,
    HALF,
    QUARTER,
    EIGHTH,
    SIXTEENTH,
    THIRTY_SECOND,
};

/// <summary>
/// This class overrides the default look and feel.
/// </summary>
class Metronome : public juce::Timer
{
public:
    Metronome();
    ~Metronome();

    void timerCallback() override;

    void setBPM(int BPM);
    void setNoteLength(NoteLength noteLength);
    void setCallback(std::function<void()> callback);
    void stop();
    void start();

private:
    int m_IntervalInMs;
    int m_BPM;
    NoteLength m_NoteLength;
    std::function<void()> m_Callback;

    void setTimeInterval();
};

