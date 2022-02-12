/*
  ==============================================================================

    MidiChannel.cpp
    Created: 9 Feb 2022 9:09:40pm
    Author:  simon_i7fbffu

  ==============================================================================
*/

#include "MidiChannel.h"

MidiChannel::MidiChannel(int channelNumber) :
    MidiChannel(channelNumber, 0.0)
{
}

MidiChannel::MidiChannel(int channelNumber, double distribution) :
    m_ChannelNumber(channelNumber),
    m_Distribution(distribution)
{
}

MidiChannel::~MidiChannel()
{
}

double MidiChannel::getDistribution()
{
    return m_Distribution;
}

int MidiChannel::getChannelNumber()
{
    return m_ChannelNumber;
}

void MidiChannel::setDistribution(double distribution)
{
    m_Distribution = distribution;
}
