/*
  ==================================================================================================================

    ContainerComponent.h
    Created: 29 Jan 2022 7:28:11pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "ControlsComponent.h"

/// <summary>
/// This class is the top-level component (after the main component) and houses
/// the entire GUI.
/// </summary>
class ContainerComponent : public juce::Component
{
public:
    ContainerComponent();
    ~ContainerComponent() override;

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Component
    void paint(juce::Graphics&) override;
    void resized() override;

private:
    // COMPONENTS
    //==============================================================================================================
    ControlsComponent m_ControlsContainer;

    // MEMBER VARIABLES
    //==============================================================================================================
    juce::Image m_Character;

    // CONSTANTS
    //==============================================================================================================
    const int CONTROLS_AREA_MARGIN = 45;
    const int CONTROLS_AREA_WIDTH = 672;
    const int HEADER_HEIGHT = 118;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ContainerComponent)
};
