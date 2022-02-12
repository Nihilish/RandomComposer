/*
  ==================================================================================================================

    RandomComposerAudioProcessorEditor.cpp
    Created: 03 Feb 2022 9:09:55pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include "Defaults.h"
#include "Functions.h"

RandomComposerAudioProcessorEditor::RandomComposerAudioProcessorEditor (RandomComposerAudioProcessor& p)
    : AudioProcessorEditor (&p), 
    audioProcessor (p),
    m_Metronome()
{
    setSize(1200, 800);
    setLookAndFeel(&m_DefaultLookAndFeel);
    addAndMakeVisible(m_AppContainer);

    p.setMusicGenerator(new MusicGenerator(m_Scale, *app::getChildComponentOfClass<MidiChannelDistributionComponent>(this)->getMidiChannels()));

    m_Metronome.setCallback([this, &p] { p.playNote(); });
}

RandomComposerAudioProcessorEditor::~RandomComposerAudioProcessorEditor()
{
    setLookAndFeel(nullptr);
}

Metronome* RandomComposerAudioProcessorEditor::getMetronome()
{
    return &m_Metronome;
}

Scale* RandomComposerAudioProcessorEditor::getScale()
{
    return &m_Scale;
}

void RandomComposerAudioProcessorEditor::paint (juce::Graphics& g)
{
}

void RandomComposerAudioProcessorEditor::resized()
{
    m_AppContainer.setBounds(getLocalBounds());
}
