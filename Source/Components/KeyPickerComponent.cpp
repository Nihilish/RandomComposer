/*
  ==================================================================================================================

    KeyPickerComponent.cpp
    Created: 30 Jan 2022 5:09:44pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "KeyPickerComponent.h"
#include "PluginEditor.h"
#include "Colours.h"
#include "Defaults.h"

KeyPickerComponent::KeyPickerComponent() :
    m_Scale(nullptr)
{
    // Adjust slider style
    m_KeySlider.setSliderStyle(juce::Slider::Rotary);
    getLookAndFeel().setColour(juce::Slider::textBoxOutlineColourId, juce::Colours::transparentWhite);
    getLookAndFeel().setColour(juce::Slider::textBoxTextColourId, app::Colours::pinkAccent);
    m_KeySlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, true, 50, 30);

    m_KeySlider.textFromValueFunction = [](double value)
    {
        switch ((int)value)
        {
        case 0:
            return "C";
        case 1:
            return "C#";
        case 2:
            return "D";
        case 3:
            return "D#";
        case 4:
            return "E";
        case 5:
            return "F";
        case 6:
            return "F#";
        case 7:
            return "G";
        case 8:
            return "G#";
        case 9:
            return "A";
        case 10:
            return "A#";
        case 11:
            return "B";
        default:
            return "C";
        }
    };

    // Adjust slider parameters
    m_KeySlider.setRange(0, 11, 1.0);
    m_KeySlider.setValue(app::Defaults::defaultKey);
    m_KeySlider.setNumDecimalPlacesToDisplay(0);
    m_KeySlider.addListener(this);

    addAndMakeVisible(m_KeySlider);
}

KeyPickerComponent::~KeyPickerComponent()
{
}

void KeyPickerComponent::paint(juce::Graphics& g)
{

}

void KeyPickerComponent::resized()
{
    juce::Rectangle<int> sliderArea = juce::Rectangle<int>(100, 100);
    sliderArea.setCentre(getLocalBounds().getCentre());
    sliderArea.setY(getLocalBounds().getY());
    m_KeySlider.setBounds(sliderArea);
}

void KeyPickerComponent::sliderValueChanged(juce::Slider* slider)
{
    if (m_Scale == nullptr)
        m_Scale = findParentComponentOfClass<RandomComposerAudioProcessorEditor>()->getScale();
    
    m_Scale->setKey(static_cast<Key>((int)slider->getValue()));
}
