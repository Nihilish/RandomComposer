/*
  ==================================================================================================================

    RandomComposerDefaultLookAndFeel.cpp
    Created: 30 Jan 2022 4:04:55pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include "RandomComposerDefaultLookAndFeel.h"
#include "Colours.h"

RandomComposerDefaultLookAndFeel::RandomComposerDefaultLookAndFeel()
{
    setColour(juce::TextButton::buttonColourId, app::Colours::darkerTeal);
    setColour(juce::TextButton::buttonOnColourId, app::Colours::pinkAccent);
    setColour(juce::ComboBox::outlineColourId, juce::Colours::transparentWhite);

    setColour(juce::Slider::thumbColourId, app::Colours::pinkAccent);
    setColour(juce::Slider::rotarySliderFillColourId, app::Colours::backgroundColour);
    setColour(juce::Slider::rotarySliderOutlineColourId, app::Colours::backgroundColour);
    setColour(juce::Slider::trackColourId, app::Colours::backgroundColour);
    setColour(juce::Slider::backgroundColourId, app::Colours::backgroundColour);
}

RandomComposerDefaultLookAndFeel::~RandomComposerDefaultLookAndFeel()
{
}

juce::Font RandomComposerDefaultLookAndFeel::getTextButtonFont(juce::TextButton&, int buttonHeight)
{
    return juce::Font(24);
}
