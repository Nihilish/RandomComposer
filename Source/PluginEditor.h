/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "ContainerComponent.h"
#include "RandomComposerDefaultLookAndFeel.h"
#include "Metronome.h"

//==============================================================================
/**
*/
class RandomComposerAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    RandomComposerAudioProcessorEditor (RandomComposerAudioProcessor&);
    ~RandomComposerAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    Metronome* getMetronome();
    Scale* getScale();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    RandomComposerAudioProcessor& audioProcessor;
    ContainerComponent m_AppContainer;
    RandomComposerDefaultLookAndFeel m_DefaultLookAndFeel;
    Metronome m_Metronome;
    Scale m_Scale;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RandomComposerAudioProcessorEditor)
};
