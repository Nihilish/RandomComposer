/*
  ==================================================================================================================

    ControlsComponent.cpp
    Created: 29 Jan 2022 7:28:34pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "PluginEditor.h"
#include "ControlsComponent.h"
#include "Colours.h"

ControlsComponent::ControlsComponent()
{
    formatLabel(m_ModesText);
    formatLabel(m_KeyText);
    formatLabel(m_TempoText);
    formatLabel(m_MidiChannelText);

    m_OnOffButton.setClickingTogglesState(true);
    m_OnOffButton.setWantsKeyboardFocus(false);
    m_OnOffButton.onClick = [this] { onOnOffClick();};

    addAndMakeVisible(m_ModesText);
    addAndMakeVisible(m_ModesContainer);

    addAndMakeVisible(m_KeyText);
    addAndMakeVisible(m_KeyPickerContainer);

    addAndMakeVisible(m_TempoText);
    addAndMakeVisible(m_TempoContainer);

    addAndMakeVisible(m_MidiChannelText);
    addAndMakeVisible(m_MidiChannelDistributionContainer);

    addAndMakeVisible(m_OnOffButton);
}

ControlsComponent::~ControlsComponent()
{
}

/// <summary>
/// Formats titles in the controls area.
/// </summary>
/// <param name="label">The label to format.</param>
void ControlsComponent::formatLabel(juce::Label& label)
{
    label.setJustificationType(juce::Justification::centred);
    label.setFont(juce::Font(LABEL_FONT_SIZE, juce::Font::bold));
    label.setColour(juce::Label::textColourId, app::Colours::backgroundColour);
}

/// <summary>
/// Called when clicking the enabled/bypassed button. Starts and stops the output.
/// </summary>
void ControlsComponent::onOnOffClick()
{
    m_IsRunning = !m_IsRunning;
    m_OnOffButton.setButtonText(m_IsRunning ? "ENABLED" : "BYPASSED");
    if (!m_OnOffButton.getToggleState())
        findParentComponentOfClass<RandomComposerAudioProcessorEditor>()->getMetronome()->stop();

    else
        findParentComponentOfClass<RandomComposerAudioProcessorEditor>()->getMetronome()->start();
}

void ControlsComponent::paint(juce::Graphics& g)
{
    g.setColour(app::Colours::lighterTeal);

    g.fillRoundedRectangle(getLocalBounds().toFloat(), 5.0);
}

void ControlsComponent::resized()
{
    auto area = getLocalBounds();
    area.removeFromTop(TOP_BOTTOM_MARGIN);

    m_ModesText.setBounds(area.removeFromTop(LABEL_FONT_SIZE));

    area.removeFromTop(ROW_MARGIN);

    juce::Rectangle<int> modesArea = juce::Rectangle<int>(400, 55);
    modesArea.setCentre(area.getCentreX(), area.getY());
    modesArea.setY(area.getY());
    m_ModesContainer.setBounds(modesArea);
    area.removeFromTop(modesArea.getHeight());

    area.removeFromTop(ROW_MARGIN);

    m_KeyText.setBounds(area.removeFromTop(LABEL_FONT_SIZE));

    area.removeFromTop(ROW_MARGIN);

    juce::Rectangle<int> keyArea = juce::Rectangle<int>(277, 132);
    keyArea.setCentre(area.getCentreX(), area.getY());
    keyArea.setY(area.getY());
    m_KeyPickerContainer.setBounds(keyArea);
    area.removeFromTop(keyArea.getHeight());

    area.removeFromTop(ROW_MARGIN);

    m_TempoText.setBounds(area.removeFromTop(LABEL_FONT_SIZE));

    area.removeFromTop(ROW_MARGIN);

    juce::Rectangle<int> tempoArea = juce::Rectangle<int>(350, 55);
    tempoArea.setCentre(area.getCentreX(), area.getY());
    tempoArea.setY(area.getY());
    m_TempoContainer.setBounds(tempoArea);
    area.removeFromTop(tempoArea.getHeight());

    area.removeFromTop(ROW_MARGIN);

    m_MidiChannelText.setBounds(area.removeFromTop(LABEL_FONT_SIZE));

    area.removeFromTop(ROW_MARGIN);

    juce::Rectangle<int> testArea = juce::Rectangle<int>(350, 100);
    testArea.setCentre(area.getCentreX(), area.getY());
    testArea.setY(area.getY());
    m_MidiChannelDistributionContainer.setBounds(testArea);
    area.removeFromTop(testArea.getHeight());

    area.removeFromTop(ROW_MARGIN);
    juce::Point<int> centre = area.getCentre();
    area.setWidth(150);
    area.removeFromBottom(TOP_BOTTOM_MARGIN);
    area.setCentre(centre);
    m_OnOffButton.setBounds(area);
}