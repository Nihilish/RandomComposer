/*
  ==================================================================================================================

    KeyPickerComponent.h
    Created: 30 Jan 2022 5:09:44pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Scale.h"

//==================================================================================================================

/// <summary>
/// This component houses the key selector knob.
/// </summary>
class KeyPickerComponent : public juce::Component,
                           public juce::Slider::Listener
{
public:
    KeyPickerComponent();
    ~KeyPickerComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // COMPONENTS
    //==============================================================================================================
    juce::Slider m_KeySlider;

    void sliderValueChanged(juce::Slider* slider) override;

    Scale* m_Scale;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(KeyPickerComponent)
};
