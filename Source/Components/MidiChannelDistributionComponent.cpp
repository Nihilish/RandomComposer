/*
  ==================================================================================================================

    MidiChannelDistributionComponent.cpp
    Created: 31 Jan 2022 7:01:01pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "MidiChannelDistributionComponent.h"

MidiChannelDistributionComponent::MidiChannelDistributionComponent() :
    m_RegisteredPercentageSliders(),
    m_MidiChannels(),
    m_Channel1(*this, new MidiChannel(1, 100.0)),
    m_Channel2(*this, new MidiChannel(2)),
    m_Channel3(*this, new MidiChannel(3))
{
    addAndMakeVisible(m_Channel1);
    addAndMakeVisible(m_Channel2);
    addAndMakeVisible(m_Channel3);

    m_RegisteredPercentageSliders.push_back(&m_Channel1);
    m_RegisteredPercentageSliders.push_back(&m_Channel2);
    m_RegisteredPercentageSliders.push_back(&m_Channel3);

    m_MidiChannels = new std::vector<MidiChannel*>();

    m_MidiChannels->push_back(m_Channel1.getMidiChannel());
    m_MidiChannels->push_back(m_Channel2.getMidiChannel());
    m_MidiChannels->push_back(m_Channel3.getMidiChannel());

    m_Channel1.addSliderListener(this);
    m_Channel2.addSliderListener(this);
    m_Channel3.addSliderListener(this);
}

MidiChannelDistributionComponent::~MidiChannelDistributionComponent()
{
}

/// <summary>
/// Locks a channel. Ensures at most 1 channel is locked at any given time.
/// </summary>
/// <param name="slider">The slider to lock.</param>
void MidiChannelDistributionComponent::lock(PercentageSliderComponent& slider)
{
    if (slider.getIsSliderLocked())
    {
        slider.setIsSliderLocked(false);
        return;
    }

    for (auto* iteratedSlider : m_RegisteredPercentageSliders)
    {
        if (iteratedSlider == &slider)
        {
            slider.setIsSliderLocked(true);
        }
        else if (iteratedSlider->getIsSliderLocked())
            iteratedSlider->setIsSliderLocked(false);
    }
}

void MidiChannelDistributionComponent::paint(juce::Graphics& g)
{
}

void MidiChannelDistributionComponent::resized()
{
    auto area = getLocalBounds();
    int channelHeight = area.getHeight() / 3;

    m_Channel1.setBounds(area.removeFromTop(channelHeight));
    m_Channel2.setBounds(area.removeFromTop(channelHeight));
    m_Channel3.setBounds(area.removeFromTop(channelHeight));
}

std::vector<MidiChannel*>* MidiChannelDistributionComponent::getMidiChannels() const
{
    return m_MidiChannels;
}

/// <summary>
/// Ensures all three sliders' values do not exceed 100%.
/// </summary>
/// <param name="slider">The slider whose value has changed.</param>
void MidiChannelDistributionComponent::sliderValueChanged(juce::Slider* slider)
{
    bool isSliderLocked = false;

    PercentageSliderComponent* changedSlider = nullptr;
    PercentageSliderComponent* otherSlider = nullptr;

    // Check if a slider is locked. changedSlider and otherSlider are never nullptr.
    for (auto* iteratedSlider : m_RegisteredPercentageSliders)
    {
        if (iteratedSlider->getIsSliderLocked())
        {
            isSliderLocked = true;
        }

        else if (iteratedSlider->getSlider() == slider)
            changedSlider = iteratedSlider;

        else
            otherSlider = iteratedSlider;
    }

    if (isSliderLocked)
    {
        int valueTo100 = 100 - m_Channel1.getSliderValue() - m_Channel2.getSliderValue() - m_Channel3.getSliderValue();

        if ((otherSlider->getSliderValue() > 0 && valueTo100 < 0) || (otherSlider->getSliderValue() < 100 && valueTo100 > 0))
        {
            int difference = 0;
            // If the value to 100 is greater than the remaining percentage in the other slider, we must take away
            // the difference from the changed slider.
            if (valueTo100 < 0 && abs(valueTo100) > otherSlider->getSliderValue())
            {
                difference = valueTo100 + otherSlider->getSliderValue();
                valueTo100 -= difference;
            }
            otherSlider->setSliderValue(otherSlider->getSliderValue() + valueTo100);
            changedSlider->setSliderValue(changedSlider->getSliderValue() + difference);
        }
        else
            changedSlider->setSliderValue(changedSlider->getSliderValue() + valueTo100);
    }

    else
    {
        int valueTo100 = 100 - changedSlider->getSliderValue();
        int i = 0;
        int newValues[2] = { ceil(valueTo100 / 2.0) , floor(valueTo100 / 2.0) };

        for (auto* iteratedSlider : m_RegisteredPercentageSliders)
        {
            if (iteratedSlider->getSlider() == slider)
                continue;
            else
                iteratedSlider->setSliderValue(newValues[i++]);
        }
    }

    changedSlider->setSliderValue(changedSlider->getSliderValue());
}