/*
  ==============================================================================

    Receiver.h
    Created: 21 Aug 2015 3:45:37pm
    Author:  Karl

  ==============================================================================
*/

#ifndef RECEIVER_H_INCLUDED
#define RECEIVER_H_INCLUDED

#include <iostream>
#include "PdReceiver.hpp"
#include "PdTypes.hpp"
#include "../JuceLibraryCode/JuceHeader.h"
#include "FloatParameter.h"

//resolve circular dependency
class PureDataAudioProcessor;



class Receiver : public pd::PdReceiver {
    
public:

    Receiver(Array<FloatParameter*>* pList, PureDataAudioProcessor* processor);
    virtual ~Receiver();
    
    void receiveMessage(const std::string& dest, const std::string& msg, const pd::List& list);
    const String paramIdentifier = "pdpulp_p";
    
private:
    Array<FloatParameter*>* parameterList;
    PureDataAudioProcessor* processor;
    
    void setErrorMessage(std::string msg);
};


#endif  // RECEIVER_H_INCLUDED

