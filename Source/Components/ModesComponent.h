/*
  ==================================================================================================================

    ModesComponent.h
    Created: 29 Jan 2022 7:29:58pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "Scale.h"

/// <summary>
/// This component houses the 3 buttons to choose from the available modes
/// (major, minor or chromatic).
/// </summary>
class ModesComponent : public juce::Component,
                       public juce::Button::Listener
{
public:
    ModesComponent();
    ~ModesComponent() override;

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Component
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // COMPONENTS
    //==============================================================================================================
    juce::TextButton m_MajorButton{ "major" };
    juce::TextButton m_MinorButton{ "minor" };
    juce::TextButton m_ChromaticButton{ "chromatic" };

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void buttonStateChanged(juce::Button* button);
    void buttonClicked(juce::Button* button);

    // CONSTANTS
    //==============================================================================================================
    const int MODE_RADIO_GROUP = 1;
    const int BUTTON_MARGIN = 9;

    Scale* m_Scale;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ModesComponent)
};
