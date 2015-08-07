

JuceLibPd 
==============

This is an audio plugin that enables you to run pd patches inside your DAW. You can use the automation feature of your DAW to control up to 10 parameters of the loaded pd patch.

<a href="https://www.youtube.com/watch?v=TsPwRh1xSps" title="Watch demo video" target="_blank">
  <img width="418" alt="screen shot 2015-08-07 at 09 45 22" src="https://cloud.githubusercontent.com/assets/692826/9131118/17ce75ba-3ce9-11e5-9419-1867a28902fc.png">
</a>

The plugin is based on a barebone juce project that utilizes libpd to be able to use pure data as the sound engine for juce audio plugins.

What follows is a description to get the project to compile on your machine. We will also provide downloadable ready-made plugin binaries once we're ready though. 

Although this howto focuses on OSX specific development, you should be able to create Windows and Linux plugins as well. Clone this project, open the introjucer, add a new VisualStudio or Linux Makefile target by right clicking on JucePureData.

###JUCE Installation:
Make sure your setup is ready to produce VST and/or AudioUnit plugins. If it's not, follow the instructions at the [JUCE plugin setup tutorial](http://www.juce.com/learn/tutorials-code-examples/create-basic-audio-midi-plugin-part-1-setting-up).

###LibPD Installation
[LibPD](https://github.com/libpd/libpd) is already included. However, if want to produce 64bit plugins, you need to compile it for the correct architecture and place the libpd-osx.a file in the projects Source folder.

###Setting up the Project
####Introjucer Instructions

Xcode (MacOSX) -> Debug/Release

 - Adapt Header Search Paths to where libpd lies
 - Adapt Extra Library Search to Source path of current project

Note: If you want to use relative header search paths here, you need to describe it from where the xcode project file is, not the jucer file, as conventionally.

![search-paths-screenshot](https://cloud.githubusercontent.com/assets/692826/8396624/9670e48e-1dae-11e5-9f6c-b87509c16db3.png)


######Change module paths

 - click on Modules (red icon)
 - double click juce_audio_basics
 - enter correct module path
 - click on Modules (red icon) again
 - select juce_audio_basics
 - click Set path for all modules…
 - select "copy the paths from the module ‘juce_audio_basics’ to all other modules”

Click on Save Project and Open in Xcode…

######VST creation
Note, that you need to set the path of the vst sdk by clicking on the target Xcode (MacOSX) and enter the path. If the vst path field is missing, it means, that one or more audio plugin specific modules have not been added. Click on modules and add all audio modules.

######Patchfile
After you successfully compiled it, you should get a Juce Assertion failure, because the patch file cant be loaded - here you need to enter the correct path to the patch file. Since this is a runtime variable, it has to be an absolute path.

######Debugging
In Xcode edit you "Run Debug" scheme and enter your DAW you are testing with as Executable. You can also use Juce PluginHost app from the juce examples folder.   Remember that the DAW software might not find your plugin if it's compiled for an unsuitable architecture.
