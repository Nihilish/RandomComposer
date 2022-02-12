/*
  ==============================================================================================================

    ContainerComponent.cpp
    Created: 29 Jan 2022 7:28:11pm
    Author:  Nihilish

  ==============================================================================================================
*/

#include <JuceHeader.h>
#include "Colours.h"
#include "ContainerComponent.h"

//==============================================================================================================
ContainerComponent::ContainerComponent()
{
    m_Character = juce::ImageFileFormat::loadFrom(BinaryData::beethoven_png, BinaryData::beethoven_pngSize);
    addAndMakeVisible(m_ControlsContainer);
}

ContainerComponent::~ContainerComponent()
{
}

void ContainerComponent::paint(juce::Graphics& g)
{
    g.fillAll(app::Colours::backgroundColour);

    g.drawImage(m_Character,
        getLocalBounds().toFloat(),
        juce::RectanglePlacement::xLeft |
        juce::RectanglePlacement::yBottom |
        juce::RectanglePlacement::doNotResize);
}

void ContainerComponent::resized()
{
    auto area = getLocalBounds();

    // Header 
    juce::Rectangle<int> headerArea = area.removeFromTop(HEADER_HEIGHT);

    // Controls
    juce::Rectangle<int> controlsArea = area;
    controlsArea.removeFromLeft(CONTROLS_AREA_WIDTH);
    controlsArea.removeFromRight(CONTROLS_AREA_MARGIN);
    controlsArea.removeFromBottom(CONTROLS_AREA_MARGIN);
    m_ControlsContainer.setBounds(controlsArea);
}
