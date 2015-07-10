/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.1

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MainComponent::MainComponent (PureDataAudioProcessor& processor)
    : PureDataAudioProcessorEditor(processor)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (reloadButton = new TextButton ("new button"));
    reloadButton->setButtonText (TRANS("Reload"));
    reloadButton->addListener (this);
    reloadButton->setColour (TextButton::buttonColourId, Colour (0xffadadad));
    reloadButton->setColour (TextButton::buttonOnColourId, Colour (0xff727272));

    addAndMakeVisible (sendSlider1 = new SendSlider (1, processor));
    addAndMakeVisible (sendSlider2 = new SendSlider (2, processor));
    addAndMakeVisible (sendSlider5 = new SendSlider (3, processor));
    addAndMakeVisible (sendSlider6 = new SendSlider (4, processor));
    addAndMakeVisible (sendSlider7 = new SendSlider (5, processor));
    addAndMakeVisible (sendSlider3 = new SendSlider (6, processor));
    addAndMakeVisible (sendSlider4 = new SendSlider (7, processor));
    addAndMakeVisible (sendSlider8 = new SendSlider (8, processor));
    addAndMakeVisible (sendSlider9 = new SendSlider (9, processor));
    addAndMakeVisible (sendSlider10 = new SendSlider (10, processor));
    addAndMakeVisible (findButton = new TextButton ("new button"));
    findButton->setButtonText (TRANS("Find patch..."));
    findButton->addListener (this);
    findButton->setColour (TextButton::buttonColourId, Colour (0xffadadad));
    findButton->setColour (TextButton::buttonOnColourId, Colour (0xff727272));

    addAndMakeVisible (pathField = new Label ("new label",
                                              TRANS("...")));
    pathField->setFont (Font (15.00f, Font::plain));
    pathField->setJustificationType (Justification::centred);
    pathField->setEditable (false, false, false);
    pathField->setColour (Label::textColourId, Colour (0xffbcbcbc));
    pathField->setColour (TextEditor::textColourId, Colours::black);
    pathField->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (pathField2 = new Label ("new label",
                                               TRANS("GANF")));
    pathField2->setFont (Font (39.20f, Font::italic));
    pathField2->setJustificationType (Justification::centredRight);
    pathField2->setEditable (false, false, false);
    pathField2->setColour (Label::textColourId, Colour (0xffbcbcbc));
    pathField2->setColour (TextEditor::textColourId, Colours::black);
    pathField2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (500, 370);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainComponent::~MainComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    reloadButton = nullptr;
    sendSlider1 = nullptr;
    sendSlider2 = nullptr;
    sendSlider5 = nullptr;
    sendSlider6 = nullptr;
    sendSlider7 = nullptr;
    sendSlider3 = nullptr;
    sendSlider4 = nullptr;
    sendSlider8 = nullptr;
    sendSlider9 = nullptr;
    sendSlider10 = nullptr;
    findButton = nullptr;
    pathField = nullptr;
    pathField2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff303030));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    reloadButton->setBounds (390, 72, 82, 24);
    sendSlider1->setBounds (9, 114, 98, 120);
    sendSlider2->setBounds (101, 114, 98, 120);
    sendSlider5->setBounds (197, 114, 98, 120);
    sendSlider6->setBounds (293, 114, 98, 120);
    sendSlider7->setBounds (389, 114, 98, 120);
    sendSlider3->setBounds (9, 242, 98, 120);
    sendSlider4->setBounds (101, 242, 98, 120);
    sendSlider8->setBounds (197, 242, 98, 120);
    sendSlider9->setBounds (293, 242, 98, 120);
    sendSlider10->setBounds (389, 242, 98, 120);
    findButton->setBounds (24, 72, 104, 24);
    pathField->setBounds (136, 72, 248, 24);
    pathField2->setBounds (336, 16, 144, 40);
    //[UserResized] Add your own custom resize handling here..

    //[/UserResized]
}

void MainComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == reloadButton)
    {
        //[UserButtonCode_reloadButton] -- add your button handler code here..
        //[/UserButtonCode_reloadButton]
    }
    else if (buttonThatWasClicked == findButton)
    {
        //[UserButtonCode_findButton] -- add your button handler code here..
        FileChooser fc ("Choose a file to open...",
                        File::getCurrentWorkingDirectory(),
                        "*",
                        true);

        if (fc.browseForFileToOpen())
        {
            pathField->setText(fc.getResult().getFullPathName(), dontSendNotification);
        }
        //[/UserButtonCode_findButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainComponent" componentName=""
                 parentClasses="public PureDataAudioProcessorEditor" constructorParams="PureDataAudioProcessor&amp; processor"
                 variableInitialisers="PureDataAudioProcessorEditor(processor)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="500" initialHeight="370">
  <BACKGROUND backgroundColour="ff303030"/>
  <TEXTBUTTON name="new button" id="46837e8b39cdf5ab" memberName="reloadButton"
              virtualName="" explicitFocusOrder="0" pos="390 72 82 24" bgColOff="ffadadad"
              bgColOn="ff727272" buttonText="Reload" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <JUCERCOMP name="" id="bc71a9946298412f" memberName="sendSlider1" virtualName=""
             explicitFocusOrder="0" pos="9 114 98 120" sourceFile="SendSlider.cpp"
             constructorParams="1, processor"/>
  <JUCERCOMP name="" id="2cbea2ce044e5daa" memberName="sendSlider2" virtualName=""
             explicitFocusOrder="0" pos="101 114 98 120" sourceFile="SendSlider.cpp"
             constructorParams="2, processor"/>
  <JUCERCOMP name="" id="e8e479a7b178aed7" memberName="sendSlider5" virtualName=""
             explicitFocusOrder="0" pos="197 114 98 120" sourceFile="SendSlider.cpp"
             constructorParams="3, processor"/>
  <JUCERCOMP name="" id="8371429f476dadb8" memberName="sendSlider6" virtualName=""
             explicitFocusOrder="0" pos="293 114 98 120" sourceFile="SendSlider.cpp"
             constructorParams="4, processor"/>
  <JUCERCOMP name="" id="6a6f5c3c175c8eea" memberName="sendSlider7" virtualName=""
             explicitFocusOrder="0" pos="389 114 98 120" sourceFile="SendSlider.cpp"
             constructorParams="5, processor"/>
  <JUCERCOMP name="" id="b743230df56fafcb" memberName="sendSlider3" virtualName=""
             explicitFocusOrder="0" pos="9 242 98 120" sourceFile="SendSlider.cpp"
             constructorParams="6, processor"/>
  <JUCERCOMP name="" id="488c56ced9555a30" memberName="sendSlider4" virtualName=""
             explicitFocusOrder="0" pos="101 242 98 120" sourceFile="SendSlider.cpp"
             constructorParams="7, processor"/>
  <JUCERCOMP name="" id="9f9f04d1bb5763fc" memberName="sendSlider8" virtualName=""
             explicitFocusOrder="0" pos="197 242 98 120" sourceFile="SendSlider.cpp"
             constructorParams="8, processor"/>
  <JUCERCOMP name="" id="c4f70e09d260381f" memberName="sendSlider9" virtualName=""
             explicitFocusOrder="0" pos="293 242 98 120" sourceFile="SendSlider.cpp"
             constructorParams="9, processor"/>
  <JUCERCOMP name="" id="4fe4af228a7dcf41" memberName="sendSlider10" virtualName=""
             explicitFocusOrder="0" pos="389 242 98 120" sourceFile="SendSlider.cpp"
             constructorParams="10, processor"/>
  <TEXTBUTTON name="new button" id="1e5168d1e5fff12c" memberName="findButton"
              virtualName="" explicitFocusOrder="0" pos="24 72 104 24" bgColOff="ffadadad"
              bgColOn="ff727272" buttonText="Find patch..." connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="90c1e98cfe7db5e9" memberName="pathField"
         virtualName="" explicitFocusOrder="0" pos="136 72 248 24" textCol="ffbcbcbc"
         edTextCol="ff000000" edBkgCol="0" labelText="..." editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="97c666a4f6ed7edd" memberName="pathField2"
         virtualName="" explicitFocusOrder="0" pos="336 16 144 40" textCol="ffbcbcbc"
         edTextCol="ff000000" edBkgCol="0" labelText="GANF" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="39.200000000000002842" bold="0" italic="1" justification="34"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
