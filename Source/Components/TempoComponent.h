/*
  ==================================================================================================================

    TempoComponent.h
    Created: 31 Jan 2022 6:12:34pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Metronome.h"

//==================================================================================================================

/// <summary>
/// This component nests a tempo slider with a tempo sync button.
/// </summary>
class TempoComponent : public juce::Component,
                       public juce::Slider::Listener
{
public:
    TempoComponent();
    ~TempoComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // COMPONENTS
    //==============================================================================================================
    juce::TextButton m_SyncButton{ "sync" };
    juce::Slider m_TempoSlider;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void toggleSync();
    void sliderValueChanged(juce::Slider *slider);

    // MEMBER VARIABLES
    //==============================================================================================================
    Metronome* m_Metronome;

    // CONSTANTS
    //==============================================================================================================
    const int BUTTON_MARGIN = 9;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(TempoComponent)
};
