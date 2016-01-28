/*
  ==============================================================================

    Receiver.cpp
    Created: 21 Aug 2015 3:45:37pm
    Author:  Karl

  ==============================================================================
*/

#include "Receiver.h"
#include "PluginProcessor.h"

Receiver::Receiver(Array<FloatParameter*>* pList, PureDataAudioProcessor* processor) : parameterList(pList), processor(processor)
{
}

Receiver::~Receiver()
{
}

void Receiver::setErrorMessage(std::string msg)
{
    processor->patchLoadError = true;
    processor->status = msg;
}

void Receiver::receiveMessage(const std::string& dest, const std::string& msg, const pd::List& list)
{
    // Note: only pdpulp_p1 through pdpulp_p10 messages have been subscribed to
    
    String id = dest;
    id = id.replace(paramIdentifier, "");
    int index = std::stoi(id.toStdString());
    index--; // remap param number
    
    FloatParameter* p = parameterList->getUnchecked(index);
    SliderConfig* s = p->getSliderConfig();
    
    bool isDirty = false;
    
    if (msg.length() > 0) {
        s->name = msg;
        isDirty = true;
    }
    
    SliderConfig defaults;
    
    float def = defaults.defaultValue,
    max = defaults.max,
    min = defaults.min,
    step = defaults.stepSize;
    
    for (int i=0; i<list.len(); i++) {
        if (list.isFloat(i)) {
            float v = list.getFloat(i);
            switch (i) {
                    
                case 0:
                    def = v;
                    isDirty = true;
                    break;
                    
                case 1:
                    max = v;
                    isDirty = true;
                    break;
                    
                case 2:
                    min = v;
                    isDirty = true;
                    break;
                    
                case 3:
                    step = v;
                    isDirty = true;
                    break;
            }
        }
    }
    
    // validate
    if (!(min < max)) {
        setErrorMessage("Param Error: min value must be higher than max value (" + dest + ", " + msg + ")");
        return;
    }
    
    if (!(def < max) && !(def > min)) {
        setErrorMessage("Param Error: default value must be between min and max value (" + dest + ", " + msg + ")");
        return;
    }

    s->stepSize = step;
    s->defaultValue = def;
    s->min = min;
    s->max = max;
    s->dirty = isDirty;
}