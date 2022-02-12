/*
  ==================================================================================================================

    RandomComposerAudioProcessorEditor.h
    Created: 03 Feb 2022 9:09:55pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ContainerComponent.h"
#include "RandomComposerDefaultLookAndFeel.h"
#include "Metronome.h"

class RandomComposerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    RandomComposerAudioProcessorEditor (RandomComposerAudioProcessor&);
    ~RandomComposerAudioProcessorEditor() override;

    // OVERRIDES
    //==============================================================================================================
    // FROM: juce::Component
    void paint (juce::Graphics&) override;
    void resized() override;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    Metronome* getMetronome();
    Scale* getScale();

private:
    // MEMBER VARIABLES
    //==============================================================================================================
    RandomComposerAudioProcessor& audioProcessor;
    ContainerComponent m_AppContainer;
    RandomComposerDefaultLookAndFeel m_DefaultLookAndFeel;
    Metronome m_Metronome;
    Scale m_Scale;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RandomComposerAudioProcessorEditor)
};
