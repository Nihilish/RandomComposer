/*
  ==================================================================================================================

	MidiChannel.h
	Created: 7 Feb 2022 9:27:34am
	Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CappedQueue.h"
#include "MidiChannel.h"
#include "Scale.h"

/// <summary>
/// The different modes for the music generator. Pertains to the AI's logic.
/// </summary>
enum class MusicGeneratorMode
{
	// Completely (pseudo)random.
	SIMPLE,
	// Uses an advanced AI for controlled (pseudo)randomness.
	ADVANCED
};

/// <summary>
/// Handles note generation using two different algorithms (simple and advanced).
/// </summary>
class MusicGenerator
{
public:
	MusicGenerator(Scale& scale, std::vector<MidiChannel*>& midiChannel);
	~MusicGenerator();

	// MEMBER FUNCTIONS
	//==============================================================================================================
	juce::MidiMessage getNote(MusicGeneratorMode mode) const;

private:

	// MEMBER FUNCTIONS
	//==============================================================================================================
	int simpleAI() const;
	int advancedAI() const;
	bool lastDegreesContainChord() const;

	// MEMBER VARIABLES
	//==============================================================================================================
	CappedQueue<int> m_LastDegrees;
	std::vector<MidiChannel*>& m_MidiChannels;
	Scale& m_Scale;
};

