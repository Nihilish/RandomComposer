/*
  ==================================================================================================================

    PercentageSliderComponent.cpp
    Created: 31 Jan 2022 7:00:25pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "PercentageSliderComponent.h"

/// <summary>
/// Initializes a new PercentageSliderComponent instance.
/// </summary>
/// <param name="parentComponent">A reference to this component's parent component.</param>
PercentageSliderComponent::PercentageSliderComponent(juce::Component& parentComponent, MidiChannel* midiChannel) :
    m_LockButton(parentComponent),
    m_SliderListener(),
    m_MidiChannel(midiChannel)
{
    m_PercentSlider.setRange(0.0, 100.0, 1.0);
    m_PercentSlider.setNumDecimalPlacesToDisplay(0);
    m_PercentSlider.setTextValueSuffix("%");
    m_PercentSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxRight, false, TEXTBOX_WIDTH, COMPONENT_HEIGHT);
    if (midiChannel->getDistribution() * 100 > 0)
        m_PercentSlider.setValue(midiChannel->getDistribution() * 100, juce::NotificationType::sendNotification);

    m_LockButton.setImages(juce::ImageFileFormat::loadFrom(BinaryData::lockUnlocked_png, BinaryData::lockUnlocked_pngSize),
        juce::ImageFileFormat::loadFrom(BinaryData::lockLocked_png, BinaryData::lockLocked_pngSize));

    addAndMakeVisible(m_PercentSlider);
    addAndMakeVisible(m_LockButton);
}

PercentageSliderComponent::~PercentageSliderComponent()
{
}

/// <summary>
/// Adds a listener to the slider.
/// </summary>
/// <param name="listener">The listener to add to the slider.</param>
void PercentageSliderComponent::addSliderListener(juce::Slider::Listener* listener)
{
    m_SliderListener = listener;
    m_PercentSlider.addListener(m_SliderListener);
}

/// <summary>
/// Gets whether the slider is locked.
/// </summary>
/// <returns>True if the slider is locked, false otherwise.</returns>
bool PercentageSliderComponent::getIsSliderLocked() const
{
    return !m_PercentSlider.isEnabled();
}

/// <summary>
/// Gets the slider component.
/// </summary>
/// <returns>The slider component.</returns>
juce::Slider* PercentageSliderComponent::getSlider()
{
    return &m_PercentSlider;
}

/// <summary>
/// Gets the current slider value.
/// </summary>
/// <returns>The slider's value.</returns>
int PercentageSliderComponent::getSliderValue() const
{
    return m_PercentSlider.getValue();
}

void PercentageSliderComponent::resized()
{
    auto area = getLocalBounds();
    int sliderWidth = area.getWidth() - COMPONENT_HEIGHT - TEXTBOX_WIDTH - BUTTON_MARGIN;
    m_PercentSlider.setBounds(area.removeFromLeft(sliderWidth));

    juce::Rectangle<int> lockButtonRectangle = area;
    lockButtonRectangle.setHeight(COMPONENT_HEIGHT);
    lockButtonRectangle.setWidth(COMPONENT_HEIGHT);
    lockButtonRectangle.setCentre(area.getCentre());
    lockButtonRectangle.setX(area.getX());

    m_LockButton.setBounds(lockButtonRectangle);
}

void PercentageSliderComponent::paint(juce::Graphics& g)
{
}

MidiChannel* PercentageSliderComponent::getMidiChannel() const
{
    return m_MidiChannel;
}

/// <summary>
/// Locks the slider.
/// </summary>
/// <param name="value">True if the slider should be locked, false otherwise.</param>
void PercentageSliderComponent::setIsSliderLocked(bool value)
{
    m_PercentSlider.setEnabled(!value);
    m_LockButton.setToggleState(value, juce::NotificationType::dontSendNotification);
}

/// <summary>
/// Sets the slider's value.
/// </summary>
/// <param name="value">The new slider value.</param>
/// <remarks>Note that this change does not trigger the listener to avoid an infinite loop.</remarks>
void PercentageSliderComponent::setSliderValue(int value)
{
    m_PercentSlider.removeListener(m_SliderListener);
    m_PercentSlider.setValue(value, juce::NotificationType::dontSendNotification);
    m_MidiChannel->setDistribution(value / 100.0);
    m_PercentSlider.addListener(m_SliderListener);
}