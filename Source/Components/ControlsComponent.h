/*
  ==================================================================================================================

    ControlsComponent.h
    Created: 29 Jan 2022 7:28:34pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ModesComponent.h"
#include "KeyPickerComponent.h"
#include "TempoComponent.h"
#include "MidiChannelDistributionComponent.h"

//==================================================================================================================

/// <summary>
/// This class nests all the controls available to the user.
/// </summary>
class ControlsComponent : public juce::Component
{
public:
    ControlsComponent();
    ~ControlsComponent() override;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // COMPONENTS
    //==============================================================================================================
    KeyPickerComponent m_KeyPickerContainer;
    juce::Label m_KeyText{ {}, "KEY" };
    MidiChannelDistributionComponent m_MidiChannelDistributionContainer;
    juce::Label m_MidiChannelText{ {}, "MIDI CHANNELS DISTRIBUTION" };
    ModesComponent m_ModesContainer;
    juce::Label m_ModesText{ {}, "MODE" };
    TempoComponent m_TempoContainer;
    juce::Label m_TempoText{ {}, "TEMPO" };
    juce::TextButton m_OnOffButton{ "BYPASSED" };

    // MEMBER VARIABLES
    //==============================================================================================================
    bool m_IsRunning = false;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void onOnOffClick();
    void formatLabel(juce::Label& label);

    // CONSTANTS
    //==============================================================================================================
    const int LABEL_FONT_SIZE = 30;
    const int ROW_MARGIN = 10;
    const int TOP_BOTTOM_MARGIN = 20;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ControlsComponent)
};
