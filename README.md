

Pd Pulp
==============

This is an audio plugin that enables you to run pd patches inside your DAW. You can use the automation feature of your DAW to control up to 10 parameters of the loaded pd patch.

<a href="https://www.youtube.com/watch?v=TsPwRh1xSps" title="Watch demo video" target="_blank">
  <img width="418" alt="screen shot 2015-08-07 at 09 45 22" src="https://cloud.githubusercontent.com/assets/692826/9131118/17ce75ba-3ce9-11e5-9419-1867a28902fc.png">
</a>

###Download
Download the latest version of the plugin from: [Releases](https://github.com/logsol/pd-pulp/releases)

###About

Run pure-data inside VST host applications. An open source plugin created by Karl Pannek and Oliver Greschke, with awesome help from Fabian Renn and Sven Braun.

###How to control a pd patch
In order to receive parameter changes from the host, two things have to be done:
- The selected pd patch must have one or more *receive objects* for example [r Cutoff] added
- The corresponding name (e.g. Cutoff) must be entered in one of the 10 Knob Lables by clicking on them and entering the name

Be aware that " " spaces are not allowed for naming here.

###The "only 1 instance" issue
It is currently not possible to run multiple instances of the plugin in a DAW. This is due to the fact that pure data is written in such a way that currently makes it impossible to run multiple instances. The situation is explained in this [video](https://www.youtube.com/watch?v=1IUEQW0-L5M) 

###What about Windows?
We hope to be able to provide the plugin for other operating systems soon. To stay updated its best to follow our [Facebook page](https://www.facebook.com/pdpulp).

###Bugs & Contributions
You can report bugs on [Github issues](https://github.com/logsol/Pd-Pulp/issues) or if you don't have a Github account, just comment on [Facebook](https://www.facebook.com/pdpulp). Also code contributions are welcome. If you would like to contribute but need some help getting started, let us know!
