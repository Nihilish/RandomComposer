/*
  ==================================================================================================================

    MidiChannel.h
    Created: 9 Feb 2022 9:09:40pm
    Author:  Nihilish

  ==================================================================================================================
*/

#pragma once

/// <summary>
/// Represents a MIDI channel with its own distribution and number.
/// </summary>
class MidiChannel
{
public:
    MidiChannel(int channelNumber);
    MidiChannel(int channelNumber, double distribution);
    ~MidiChannel();

    // MEMBER FUNCTIONS
    //==============================================================================================================
    int getChannelNumber() const;
    double getDistribution() const;
    void setDistribution(double distribution);

private:
    // MEMBER FUNCTIONS
    //==============================================================================================================
    int m_ChannelNumber;
    double m_Distribution;
};
