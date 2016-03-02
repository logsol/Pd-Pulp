/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.2.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#ifndef __JUCE_HEADER_9002020A4DD09B20__
#define __JUCE_HEADER_9002020A4DD09B20__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "PluginEditor.h"
//[/Headers]

#include "SendSlider.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainComponent  : public PureDataAudioProcessorEditor,
                       public Timer,
                       public ButtonListener
{
public:
    //==============================================================================
    MainComponent (PureDataAudioProcessor& processor);
    ~MainComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void timerCallback();
    PureDataAudioProcessor* p;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<SendSlider> sendSlider1;
    ScopedPointer<SendSlider> sendSlider2;
    ScopedPointer<SendSlider> sendSlider5;
    ScopedPointer<SendSlider> sendSlider6;
    ScopedPointer<SendSlider> sendSlider7;
    ScopedPointer<SendSlider> sendSlider3;
    ScopedPointer<SendSlider> sendSlider4;
    ScopedPointer<SendSlider> sendSlider8;
    ScopedPointer<SendSlider> sendSlider9;
    ScopedPointer<SendSlider> sendSlider10;
    ScopedPointer<TextButton> findButton;
    ScopedPointer<Label> pathField;
    ScopedPointer<TextButton> reloadButton;
    ScopedPointer<TextButton> editButton;
    ScopedPointer<Label> statusField;
    ScopedPointer<Label> title;
    ScopedPointer<Label> slogan;
    ScopedPointer<Label> version;
    ScopedPointer<HyperlinkButton> libraryLink;
    ScopedPointer<HyperlinkButton> libraryLink2;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_9002020A4DD09B20__
