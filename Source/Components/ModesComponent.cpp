/*
  ==================================================================================================================

    ModesComponent.cpp
    Created: 29 Jan 2022 7:29:58pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "ModesComponent.h"
#include "PluginEditor.h"

//==================================================================================================================
ModesComponent::ModesComponent() :
    m_Scale(nullptr)
{
    m_MajorButton.setRadioGroupId(MODE_RADIO_GROUP);
    m_MajorButton.setWantsKeyboardFocus(false);
    m_MajorButton.setClickingTogglesState(true);
    m_MajorButton.setToggleState(true, juce::NotificationType::dontSendNotification);
    m_MajorButton.addListener(this);
    addAndMakeVisible(m_MajorButton);

    m_MinorButton.setRadioGroupId(MODE_RADIO_GROUP);
    m_MinorButton.setWantsKeyboardFocus(false);
    m_MinorButton.setClickingTogglesState(true);
    m_MinorButton.addListener(this);
    addAndMakeVisible(m_MinorButton);

    m_ChromaticButton.setRadioGroupId(MODE_RADIO_GROUP);
    m_ChromaticButton.setWantsKeyboardFocus(false);
    m_ChromaticButton.setClickingTogglesState(true);
    m_ChromaticButton.addListener(this);
    addAndMakeVisible(m_ChromaticButton);
}

ModesComponent::~ModesComponent()
{
}

void ModesComponent::paint(juce::Graphics& g)
{
}

void ModesComponent::resized()
{
    auto area = getLocalBounds();
    int buttonWidth = (area.getWidth() - (BUTTON_MARGIN * 2)) / 3;

    m_MajorButton.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(BUTTON_MARGIN);

    m_MinorButton.setBounds(area.removeFromLeft(buttonWidth));
    area.removeFromLeft(BUTTON_MARGIN);

    m_ChromaticButton.setBounds(area);
}

void ModesComponent::buttonStateChanged(juce::Button* button)
{
    if (!button->getToggleState())
        return;
    
    if (m_Scale == nullptr)
        m_Scale = findParentComponentOfClass<RandomComposerAudioProcessorEditor>()->getScale();

    if (button == &m_MajorButton)
        m_Scale->setMode(ScaleMode::MAJOR);

    else if (button == &m_MinorButton)
        m_Scale->setMode(ScaleMode::MINOR);

    else
        m_Scale->setMode(ScaleMode::CHROMATIC);

}

void ModesComponent::buttonClicked(juce::Button* button)
{
    // Do nothing
}
