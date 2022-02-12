/*
  ==================================================================================================================

    MidiChannel.cpp
    Created: 9 Feb 2022 9:09:40pm
    Author:  Nihilish

  ==================================================================================================================
*/

#include "MidiChannel.h"

/// <summary>
/// IInitializes a new MidiChannel instance.
/// </summary>
/// <param name="channelNumber">The channel number.</param>
MidiChannel::MidiChannel(int channelNumber) :
    MidiChannel(channelNumber, 0.0)
{
}

/// <summary>
/// Initializes a new MidiChannel instance.
/// </summary>
/// <param name="channelNumber">The channel number.</param>
/// <param name="distribution">The channel distribution.</param>
MidiChannel::MidiChannel(int channelNumber, double distribution) :
    m_ChannelNumber(channelNumber),
    m_Distribution(distribution)
{
}

MidiChannel::~MidiChannel()
{
}

/// <summary>
/// Gets the channel's distribution.
/// </summary>
/// <returns>The channel's distribution. 0.5 = 50%.</returns>
double MidiChannel::getDistribution() const
{
    return m_Distribution;
}

/// <summary>
/// Gets the channel number.
/// </summary>
/// <returns>The channel number.</returns>
int MidiChannel::getChannelNumber() const
{
    return m_ChannelNumber;
}

/// <summary>
/// Sets the channel's distribution.
/// </summary>
/// <param name="distribution">The new distribution. 0.5 = 50%.</param>
void MidiChannel::setDistribution(double distribution)
{
    m_Distribution = distribution;
}
