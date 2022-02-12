/*
  ==================================================================================================================

    TempoComponent.cpp
    Created: 31 Jan 2022 6:12:34pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "TempoComponent.h"
#include "PluginEditor.h"
#include "Defaults.h"

//==================================================================================================================
TempoComponent::TempoComponent()  :
    m_Metronome(nullptr)
{
    m_TempoSlider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxRight, true, 75, 20);
    m_TempoSlider.setNumDecimalPlacesToDisplay(0);
    m_TempoSlider.setRange(40, 300, 1.0);
    m_TempoSlider.setValue(app::Defaults::defaultTempo);
    m_TempoSlider.setTextValueSuffix(" BPM");
    m_TempoSlider.addListener(this);
    addAndMakeVisible(m_TempoSlider);

    m_SyncButton.setClickingTogglesState(true);
    m_SyncButton.setWantsKeyboardFocus(false);
    m_SyncButton.onClick = [this] { toggleSync(); };
    addAndMakeVisible(m_SyncButton);
}

TempoComponent::~TempoComponent()
{
}

void TempoComponent::paint(juce::Graphics& g)
{

}

void TempoComponent::resized()
{
    auto area = getLocalBounds();
    int sliderWidth = area.getWidth() * 0.75;
    m_TempoSlider.setBounds(area.removeFromLeft(sliderWidth));
    area.removeFromLeft(BUTTON_MARGIN);
    m_SyncButton.setBounds(area);

}

void TempoComponent::sliderValueChanged(juce::Slider* slider)
{
    if (m_Metronome == nullptr)
        m_Metronome = findParentComponentOfClass<RandomComposerAudioProcessorEditor>()->getMetronome();

    m_Metronome->setBPM(slider->getValue());
}

/// <summary>
/// Toggles tempo sync
/// </summary>
void TempoComponent::toggleSync()
{
    m_TempoSlider.setEnabled(!m_SyncButton.getToggleState());
}