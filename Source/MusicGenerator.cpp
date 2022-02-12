/*
  ==================================================================================================================

	MidiChannel.cpp
	Created: 7 Feb 2022 9:27:34am
	Author:  Nihilish

  ==================================================================================================================
*/

#include "MusicGenerator.h"

MusicGenerator::MusicGenerator(Scale& scale, std::vector<MidiChannel*>& midiChannels) :
	m_LastDegrees(3),
	m_Scale(scale),
	m_MidiChannels(midiChannels)
{
}

MusicGenerator::~MusicGenerator()
{
}

/// <summary>
/// Gets a note depending on the mode specified.
/// </summary>
/// <param name="mode">The mode (simple or advanced)</param>
/// <returns>A MidiMessage containing a noteOn.</returns>
juce::MidiMessage MusicGenerator::getNote(MusicGeneratorMode mode) const
{
	int degree;

	switch (mode)
	{
	case MusicGeneratorMode::SIMPLE:
		degree = simpleAI();
		break;
	case MusicGeneratorMode::ADVANCED:
		degree = advancedAI();
		break;
	default:
		degree = 1;
		break;
	}

	int channel = 1;

	// Determine on which channel to play the note.
	if (m_MidiChannels.size() == 3)
	{
		juce::Random random;
		float randomDistribution = random.nextDouble();
		if (randomDistribution < m_MidiChannels[0]->getDistribution())
			channel = m_MidiChannels[0]->getChannelNumber();
		else if (randomDistribution < m_MidiChannels[0]->getDistribution() + m_MidiChannels[1]->getDistribution())
			channel = m_MidiChannels[1]->getChannelNumber();
		else
			channel = m_MidiChannels[2]->getChannelNumber();
	}

	return(juce::MidiMessage::noteOn(channel, m_Scale.getNoteFromDegree(degree), (juce::uint8) 100));
}

/// <summary>
/// Simple (pseudo)random AI.
/// </summary>
/// <returns></returns>
int MusicGenerator::simpleAI() const
{
	juce::Random random;

	int rangeMax(m_Scale.getMode() == ScaleMode::CHROMATIC ? 13 : 8);

	return random.nextInt(juce::Range<int>(1, rangeMax));
}

/// <summary>
/// Enhanced (pseudo)random AI. @TODO: Work in progress.
/// </summary>
/// <returns></returns>
int MusicGenerator::advancedAI() const
{
	return 0;
}

/// <summary>
/// Determines whether the 3 last degrees played form a chord.
/// </summary>
/// <returns></returns>
bool MusicGenerator::lastDegreesContainChord() const
{
	std::vector<int> lastDegrees = m_LastDegrees.getVector();
	// Remove permutations by sorting.
	std::sort(lastDegrees.begin(), lastDegrees.end());

	if (lastDegrees == std::vector<int>{1, 3, 5} || // I
		lastDegrees == std::vector<int>{2, 4, 6} || // II
		lastDegrees == std::vector<int>{3, 5, 7} || // III
		lastDegrees == std::vector<int>{1, 4, 6} || // IV
		lastDegrees == std::vector<int>{2, 5, 7} || // V
		lastDegrees == std::vector<int>{1, 3, 6} || // VI
		lastDegrees == std::vector<int>{2, 4, 7})   // VII
		return true;

	else return false;
}
