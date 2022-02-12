/*
  ==================================================================================================================

    RandomComposerAudioProcessor.h
    Created: 03 Feb 2022 9:09:55pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "MusicGenerator.h"

class RandomComposerAudioProcessor  : public juce::AudioProcessor
{
public:
    //==============================================================================================================
    RandomComposerAudioProcessor();
    ~RandomComposerAudioProcessor() override;

    //==============================================================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

    //==============================================================================================================
    juce::AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================================================
    const juce::String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const juce::String getProgramName (int index) override;
    void changeProgramName (int index, const juce::String& newName) override;

    //==============================================================================================================
    void getStateInformation (juce::MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    // MEMBER FUNCTIONS
    //==============================================================================================================
    void playNote();
    void setMusicGenerator(MusicGenerator* musicGenerator);

private:
    // MEMBER VARIABLES
    //==============================================================================================================
    MusicGenerator* m_MusicGenerator;
    juce::MidiBuffer m_TestBuffer;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (RandomComposerAudioProcessor)
};
