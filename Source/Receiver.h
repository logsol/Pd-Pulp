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

class Receiver : public pd::PdReceiver, public ActionBroadcaster {
    
public:

    Receiver(Array<FloatParameter*>* pList);
    virtual ~Receiver();
    
    void receiveMessage(const std::string& dest, const std::string& msg, const pd::List& list);
    const String paramIdentifier = "pdpulp_p";
    
private:
    Array<FloatParameter*>* parameterList;
};


#endif  // RECEIVER_H_INCLUDED

