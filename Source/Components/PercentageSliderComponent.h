/*
  ==================================================================================================================

    PercentageSliderComponent.h
    Created: 31 Jan 2022 7:00:25pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ToggleImageButton.h"
#include "MidiChannel.h"

/// <summary>
/// This component includes a slider and a lock button to lock in the slider's value.
/// </summary>
class PercentageSliderComponent : public juce::Component
{
public:
    PercentageSliderComponent(juce::Component& parentComponent, MidiChannel* midiChannel);
    ~PercentageSliderComponent() override;

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Component
    void paint(juce::Graphics&) override;
    void resized() override;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void addSliderListener(juce::Slider::Listener* listener);
    bool getIsSliderLocked() const;
    MidiChannel* getMidiChannel() const;
    juce::Slider* getSlider();
    int getSliderValue() const;
    void setIsSliderLocked(bool value);
    void setSliderValue(int value);
private:
    // COMPONENTS
    //==============================================================================================================
    juce::Slider m_PercentSlider;
    ToggleImageButton m_LockButton;

    // MEMBER VARIABLES
    //==============================================================================================================
    juce::Slider::Listener* m_SliderListener;
    MidiChannel* m_MidiChannel;

    // CONSTANTS
    //==============================================================================================================
    const int BUTTON_MARGIN = 9;
    const int COMPONENT_HEIGHT = 20;
    const int TEXTBOX_WIDTH = 40;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PercentageSliderComponent)
};
