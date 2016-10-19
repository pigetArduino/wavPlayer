wavPlayer
----------
[Version française / French version](https://github.com/pigetArduino/wavPlayer/blob/master/readme.fr.md)

Primitive wav file player   
Only read : Wav Unsigned 8-bit PCM file   
Track will stopped if saturation   
![wavPlayer](https://github.com/pigetArduino/wavPlayer/blob/master/doc/wavPlayer.jpg)   

# Project link
http://wavplayer.madnerd.org

# Instructions
If you want to make a real mp3 player , use a DFPlayer Mini instead   
This is just a proof of concept.   

* Download wavPlayer.madnerd.org
* Copy wavPlayer inside Arduino SketchBook (Documents/Arduino)
* In tools , select : Arduino Pro Mini / 3V 8Mhz
* Upload code with FTDI cable

# Components:
* Micro sd card 2go : 4€
* Batteries holder 4AAA on/off : 1€ 
* Arduino mini pro 3.3V : 1,50€
* Audio jack dip : 2€  
* Total : 8.50€

#  Tools:
 * ftdi 3V/5V programmer

# Software needed:
  * Arduino (Programmation): http://arduino.madnerd.org


Estimate cost : 8.50€ (batteries not included) 

# Create wav file
* Open MP3 with Audacity
* File/Export Audio
* Save as type: Other uncompressed files
* Header: Wav (Microsoft)
* Encoding : Unsigned 8_bit PCM
* Save to 0.wav

# Wiring:
![Wiring GPS](https://github.com/pigetArduino/wavPlayer/blob/master/doc/sdcard_wiring.png)
##  SD card 
```
1 --> X
2 --> 12
3 --> GND
4 --> 13
5 --> VCC
6 --> GND
7 --> 11
8 --> 10 (Chip select)
```
## Headphone / Speaker
```
Left/Right ---> 6
```

## Buttons
```
prev button --> 7
next button --> 8
```

