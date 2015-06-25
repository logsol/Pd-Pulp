JuceLibPd
==============

###- JUCE Installation:

follow JUCE setup tutorial:

http://www.juce.com/learn/tutorials-code-examples/create-basic-audio-midi-plugin-part-1-setting-up


###- LibPD Installation

download and install libPD:

https://github.com/libpd/libpd


###- Download our demo project

In JUCE - go sure that you enter the correct paths in JUCE's Project Settings and Export target settings

In Xcode go sure that you link to the correct libPD library (32/64 Bit) and that  the path to the pd demo patch is correct

Very helpful for testing: In Xcode edit you "Run Debug" scheme and enter your DAW you are testing with as Executable.
