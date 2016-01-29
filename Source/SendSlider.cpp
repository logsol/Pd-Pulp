/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "PluginProcessor.h"
//[/Headers]

#include "SendSlider.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SendSlider::SendSlider (int index, PureDataAudioProcessor& processor)
    : index(index),
      processor(processor)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (slider = new Slider ("slider"));
    slider->setRange (0, 1, 0);
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    slider->setColour (Slider::thumbColourId, Colour (0xff5c5c5c));
    slider->setColour (Slider::rotarySliderFillColourId, Colour (0x7fdddddd));
    slider->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66e6e6e6));
    slider->setColour (Slider::textBoxTextColourId, Colour (0xffc1c1c1));
    slider->setColour (Slider::textBoxBackgroundColourId, Colour (0x1effffff));
    slider->setColour (Slider::textBoxHighlightColourId, Colour (0x4ba6a6a6));
    slider->setColour (Slider::textBoxOutlineColourId, Colour (0x00808080));
    slider->addListener (this);

    addAndMakeVisible (label = new Label ("label",
                                          TRANS("Label")));
    label->setTooltip (TRANS("Click to set the name of the corresponding Pure Data receive port."));
    label->setFont (Font (15.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (true, true, false);
    label->setColour (Label::backgroundColourId, Colour (0x00404040));
    label->setColour (Label::textColourId, Colour (0xffc4c4c4));
    label->setColour (TextEditor::textColourId, Colour (0xffe9e9e9));
    label->setColour (TextEditor::backgroundColourId, Colour (0x00343434));
    label->setColour (TextEditor::highlightColourId, Colour (0x61ffffff));
    label->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (100, 130);


    //[Constructor] You can add your own custom stuff here..
    PureDataAudioProcessor& p = (PureDataAudioProcessor&) processor;
    String labelText(p.getParameterName(index-1));
    label->setText(labelText, dontSendNotification);

    SliderConfig* sc = processor.getParameterList().getUnchecked(index-1)->getSliderConfig();
    slider->setDoubleClickReturnValue(true, sc->defaultValue);
    slider->setRange(sc->min, sc->max, sc->stepSize);
    slider->setValue(sc->defaultValue);

    startTimer(25);
    //[/Constructor]
}

SendSlider::~SendSlider()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    slider = nullptr;
    label = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SendSlider::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SendSlider::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    slider->setBounds (14, 35, 71, 80);
    label->setBounds (-4, 5, 104, 24);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SendSlider::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
        processor.setParameterNotifyingHost(index-1, sliderThatWasMoved->getValue());
        //[/UserSliderCode_slider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SendSlider::labelTextChanged (Label* labelThatHasChanged)
{
    //[UserlabelTextChanged_Pre]
    //[/UserlabelTextChanged_Pre]

    if (labelThatHasChanged == label)
    {
        //[UserLabelCode_label] -- add your label text handling code here..
        PureDataAudioProcessor& p = (PureDataAudioProcessor&) processor;
        p.setParameterName(index-1, labelThatHasChanged->getTextValue().toString());
        //[/UserLabelCode_label]
    }

    //[UserlabelTextChanged_Post]
    //[/UserlabelTextChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SendSlider::timerCallback()
{
    slider->setValue(processor.getParameter(index-1), NotificationType::dontSendNotification);

    SliderConfig* sc = processor.getParameterList().getUnchecked(index-1)->getSliderConfig();
    
    if (sc->dirty) {
        slider->setRange(sc->min, sc->max, sc->stepSize);
        slider->setName(sc->name);
        slider->setValue(sc->defaultValue, NotificationType::dontSendNotification);
        slider->setDoubleClickReturnValue(true, sc->defaultValue);
        label->setText(sc->name, NotificationType::dontSendNotification);
        processor.setParameterName(index-1, sc->name);
        
        sc->dirty = false;
    }
}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SendSlider" componentName=""
                 parentClasses="public Component, public Timer" constructorParams="int index, PureDataAudioProcessor&amp; processor"
                 variableInitialisers="index(index),&#10;processor(processor)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="100" initialHeight="130">
  <BACKGROUND backgroundColour="ffffff"/>
  <SLIDER name="slider" id="a814494a82a416fe" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="14 35 71 80" thumbcol="ff5c5c5c"
          rotarysliderfill="7fdddddd" rotaryslideroutline="66e6e6e6" textboxtext="ffc1c1c1"
          textboxbkgd="1effffff" textboxhighlight="4ba6a6a6" textboxoutline="808080"
          min="0" max="1" int="0" style="RotaryVerticalDrag" textBoxPos="TextBoxBelow"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="label" id="6f4900c890043ea2" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="-4 5 104 24" tooltip="Click to set the name of the corresponding Pure Data receive port."
         bkgCol="404040" textCol="ffc4c4c4" edTextCol="ffe9e9e9" edBkgCol="343434"
         hiliteCol="61ffffff" labelText="Label" editableSingleClick="1"
         editableDoubleClick="1" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
