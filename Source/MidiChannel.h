/*
  ==============================================================================

    MidiChannel.h
    Created: 9 Feb 2022 9:09:40pm
    Author:  simon_i7fbffu

  ==============================================================================
*/

#pragma once

class MidiChannel
{
public:
    MidiChannel(int channelNumber);
    MidiChannel(int channelNumber, double distribution);
    ~MidiChannel();

    void setDistribution(double distribution);
    double getDistribution();
    int getChannelNumber();
private:
    int m_ChannelNumber;
    double m_Distribution;
};
