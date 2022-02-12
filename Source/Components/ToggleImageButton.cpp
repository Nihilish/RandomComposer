/*
  ==================================================================================================================

    ToggleImageButton.cpp
    Created: 31 Jan 2022 7:31:42pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include <JuceHeader.h>
#include "ToggleImageButton.h"
#include "MidiChannelDistributionComponent.h"

/// <summary>
/// Initializes a new instance of ToggleImageButton.
/// </summary>
/// <param name="parentComponent">
/// The component within which resides the method this component should call on click.
/// </param>
ToggleImageButton::ToggleImageButton(juce::Component& parentComponent) : juce::Button(""),
m_ParentComponent(parentComponent)
{
    setWantsKeyboardFocus(false);
    onClick = [this] {onImageToggleButtonClicked(); };
}

ToggleImageButton::~ToggleImageButton()
{
}

/// <summary>
/// Called when the button is clicked.
/// </summary>
void ToggleImageButton::onImageToggleButtonClicked()
{
    ((MidiChannelDistributionComponent&)m_ParentComponent).lock(*(PercentageSliderComponent*)getParentComponent());
}

void ToggleImageButton::paintButton(juce::Graphics& g,
                                    bool            shouldDrawButtonAsHighlighted,
                                    bool            shouldDrawButtonAsDown)
{
    g.drawImageWithin(getToggleState() ? m_ToggledImage : m_UntoggledImage,
        getLocalBounds().getX(),
        getLocalBounds().getY(),
        getLocalBounds().getWidth(),
        getLocalBounds().getHeight(),
        juce::RectanglePlacement::centred);
}

void ToggleImageButton::resized()
{
}

/// <summary>
/// Sets up the images for both states.
/// </summary>
/// <param name="untoggledImage">The image for the untoggled state.</param>
/// <param name="toggledImage">The image for the toggled state.</param>
void ToggleImageButton::setImages(const juce::Image& untoggledImage, const juce::Image& toggledImage)
{
    m_UntoggledImage = untoggledImage;
    m_ToggledImage = toggledImage;
}