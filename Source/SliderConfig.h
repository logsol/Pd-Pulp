/*
  ==============================================================================

    SliderConfigMessage.h
    Created: 22 Aug 2015 3:06:59pm
    Author:  Karl

  ==============================================================================
*/

#ifndef SLIDERCONFIGMESSAGE_H_INCLUDED
#define SLIDERCONFIGMESSAGE_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

class SliderConfig {
    
public:

    String name;
    float defaultValue = 0.5;
    float max = 1;
    float min = 0;
    float stepSize;
    bool lockLabel = false;
    bool dirty = false;
};



#endif  // SLIDERCONFIGMESSAGE_H_INCLUDED
