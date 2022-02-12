/*
  ==================================================================================================================

    RandomComposerDefaultLookAndFeel.h
    Created: 30 Jan 2022 4:04:55pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>

/// <summary>
/// This class overrides the default look and feel.
/// </summary>
class RandomComposerDefaultLookAndFeel : public juce::LookAndFeel_V4
{
public:
    RandomComposerDefaultLookAndFeel();
    ~RandomComposerDefaultLookAndFeel();
    juce::Font getTextButtonFont(juce::TextButton&, int buttonHeight) override;
};
