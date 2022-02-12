/*
  ==================================================================================================================

    MidiChannelDistributionComponent.h
    Created: 31 Jan 2022 7:01:01pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PercentageSliderComponent.h"

/// <summary>
/// This channel nests three lockable sliders that set the distribution of the
/// notes among 3 MIDI Channels (ch. 1, ch. 2 and ch. 3). The sum of the 3 sliders
/// must always be 100%.
/// </summary>
class MidiChannelDistributionComponent : public juce::Component,
    public juce::Slider::Listener
{
public:
    MidiChannelDistributionComponent();
    ~MidiChannelDistributionComponent() override;

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Component
    void paint(juce::Graphics&) override;
    void resized() override;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void lock(PercentageSliderComponent& slider);
    std::vector<MidiChannel*>* getMidiChannels() const;

private:
    // COMPONENTS
    //==============================================================================================================
    PercentageSliderComponent m_Channel1, m_Channel2, m_Channel3;

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Slider::Listener
    void sliderValueChanged(juce::Slider* slider) override;

    // MEMBER VARIABLES
    //==============================================================================================================
    std::vector<PercentageSliderComponent*> m_RegisteredPercentageSliders;
    std::vector<MidiChannel*>* m_MidiChannels;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(MidiChannelDistributionComponent)
};
