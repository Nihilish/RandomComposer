/*
  ==================================================================================================================

    ToggleImageButton.h
    Created: 31 Jan 2022 7:31:42pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>

//==================================================================================================================

/// <summary>
/// This component is a button that uses images for its toggled and untoggled
/// state. No hover or click visual feedback.
/// </summary>
class ToggleImageButton : public juce::Button
{
public:
    ToggleImageButton(juce::Component& parentComponent);
    ~ToggleImageButton() override;

    void paintButton(juce::Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    void resized() override;
    void setImages(const juce::Image& untoggledImage, const juce::Image& toggledImage);

private:
    // COMPONENTS
    //==============================================================================================================
    juce::Component& m_ParentComponent;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void onImageToggleButtonClicked();

    // MEMBER VARIABLES
    //==============================================================================================================
    juce::Image m_UntoggledImage, m_ToggledImage;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ToggleImageButton)
};
