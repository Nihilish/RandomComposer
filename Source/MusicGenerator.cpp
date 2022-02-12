#include "MusicGenerator.h"
#include "Scale.h"

MusicGenerator::MusicGenerator(Scale& scale, std::vector<MidiChannel*>& midiChannels) :
	m_LastDegrees(3),
	m_Scale(scale),
	m_MidiChannels(midiChannels)
{
}

MusicGenerator::~MusicGenerator()
{
}

juce::MidiMessage MusicGenerator::getNote(MusicGeneratorMode mode)
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

int MusicGenerator::simpleAI()
{
	juce::Random random;

	int rangeMax(m_Scale.getMode() == ScaleMode::CHROMATIC ? 13 : 8);

	return random.nextInt(juce::Range<int>(1, rangeMax));
}

int MusicGenerator::advancedAI()
{
	return 0;
}

bool MusicGenerator::lastDegreesContainChord()
{
	std::vector<int> lastDegrees = m_LastDegrees.get();
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
