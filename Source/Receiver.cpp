/*
  ==============================================================================

    Receiver.cpp
    Created: 21 Aug 2015 3:45:37pm
    Author:  Karl

  ==============================================================================
*/

#include "Receiver.h"

Receiver::Receiver(Array<FloatParameter*>* pList) : parameterList(pList)
{
}

Receiver::~Receiver()
{
}

void Receiver::receiveMessage(const std::string& dest, const std::string& msg, const pd::List& list)
{
    String id = dest;
    if (!id.startsWith(paramIdentifier)) {
        return;
    }
    id = id.replace(paramIdentifier, "");
    int index = std::stoi(id.toStdString());
    
    if (index == 0 || !isPositiveAndBelow (index, parameterList->size())) {
        return;
    }
    
    sendActionMessage(id + " " + list.toString());
    
    /*
    String id = dest;
    if (!id.startsWith(paramIdentifier)) {
        return;
    }
    id = id.replace(paramIdentifier, "");
    int index = std::stoi(id.toStdString());
    
    if (index == 0 || !isPositiveAndBelow (index, parameterList->size())) {
        return;
    }

    SliderConfig s = parameterList->getUnchecked(index)->getSliderConfig();
    s.name = msg;
    s.max = .99;
    s.min = .99;
    s.defaultValue = .99;
    s.dirty = true;
    
    String l = list.toString();
    l = l.replace(" ", "");
    std::cout << "-> message received : " << dest << " - " << msg << " - " << list.toString() << std::endl;
    
    if (l.equalsIgnoreCase("0.2")) {
        std::cout << "dirty: " << index << ": " << s.dirty << std::endl;
    }
     */
}