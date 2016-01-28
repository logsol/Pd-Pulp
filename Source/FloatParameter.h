/*
  ==============================================================================

    FloatParameter.h
    Created: 3 Jul 2015 3:53:57pm
    Author:  Karl

  ==============================================================================
*/

#ifndef FLOATPARAMETER_H_INCLUDED
#define FLOATPARAMETER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "SliderConfig.h"

class FloatParameter : public AudioProcessorParameter
{
public:
    
    FloatParameter (float defaultParameterValue, const String& paramName)
    : defaultValue (defaultParameterValue),
    value (defaultParameterValue),
    name (paramName)
    {
    }
    
    float getValue() const override
    {
        return value;
    }
    
    void setValue (float newValue) override
    {
        value = newValue;
    }
    
    float getDefaultValue() const override
    {
        return defaultValue;
    }
    
    String getName (int maximumStringLength) const override
    {
        return name;
    }
    
    void setName (String n)
    {
        name = n;
    }
    
    String getLabel() const override
    {
        return String();
    }
    
    float getValueForText (const String& text) const override
    {
        return text.getFloatValue();
    }
    
    SliderConfig* getSliderConfig ()
    {
        return &sliderConfig;
    }
    
private:
    float defaultValue, value;
    String name;
    SliderConfig sliderConfig;
};


#endif  // FLOATPARAMETER_H_INCLUDED
