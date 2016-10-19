wavPlayer
----------
[Original](https://github.com/pigetArduino/wavPlayer/blob/master/readme.md)

Lecteur de fichier wav primitif
Lit uniquement des : Wav Unsigned 8-bit PCM file   
Le son s'arrête s'il est saturé
![wavPlayer](https://github.com/pigetArduino/wavPlayer/blob/master/doc/wavPlayer.jpg)   

# Lien vers le projet
http://wavPlayer.madnerd.org

Si vous voulez créer un vrai lecteur mp3, utiliser un DFPlayer mini   
C'est juste un proof of concept.    

# Composants:
* Micro sd card 2go : 4€
* Batteries holder 4AAA on/off : 1€ 
* Arduino mini pro 3.3V : 1,50€
* Audio jack dip : 2€  

Total : 8.50€   

#  Outils:
 * ftdi 3V/5V programmer

# Logiciels:
  * Arduino (Programmation): http://arduino.madnerd.org

# Create wav file
* Open MP3 with Audacity
* File/Export Audio
* Save as type: Other uncompressed files
* Header: Wav (Microsoft)
* Encoding : Unsigned 8_bit PCM
* Save to 0.wav

# Branchement:
![Wiring sd](https://github.com/pigetArduino/wavPlayer/blob/master/doc/sdcard_wiring.png)
##  Carte SD
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
## Entrée audio / Speaker
```
Left/Right ---> 6
```

## Boutons
```
Bouton précédent --> 7
Bouton suivant--> 8
```

