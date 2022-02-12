#pragma once

#include "CappedQueue.h"

#include <JuceHeader.h>
#include "Scale.h"
#include "MidiChannel.h"

enum class MusicGeneratorMode
{
	SIMPLE,
	ADVANCED
};

class MusicGenerator
{
public:
	MusicGenerator(Scale& scale, std::vector<MidiChannel*>& midiChannel);
	~MusicGenerator();

	juce::MidiMessage getNote(MusicGeneratorMode mode);

private:
	CappedQueue<int> m_LastDegrees;

	int simpleAI();
	int advancedAI();
	bool lastDegreesContainChord();

	Scale& m_Scale;
	std::vector<MidiChannel*>& m_MidiChannels;
};

