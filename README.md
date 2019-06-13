# RoboCup2018
Code for our Lego NXT and arduino hybrid robot. The code is written for the RoboCup Rescue Line Entry 2018 Rules

Our code from 2017: https://github.com/carlobrok/RoboCup2017

***Attention***: The code is ***terribly written*** and was mainly developed in 2016 and 2017.
This repo is just a demonstration of our work and should be thoroughly reworked when reused.

## Programmierung

Der Code wurde in nxc geschrieben, das ist eine Textbasierte Programmiersprache für die LEGO Mindstorms NXT Roboter.
Als Compiler haben wir den **nbc**-compiler für Linux genutzt.
Weitere Information zur Installation und Anwendung sind unter http://gbg-nolte.de/ im Bereich *alles zum NXT* vorhanden.

Command zum Compilieren und Hochladen unter Linux: 
```shell
sudo nbc -S=USB -d programm.nxc
```
Die Dokumentation der Programmiersprache nxc: http://bricxcc.sourceforge.net/nbc/nxcdoc/nxcapi/
