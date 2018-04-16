/*
wavPlayer
Madnerd.org

Primitive wav file player
Only read : Wav Unsigned 8-bit PCM file
Track will stopped if saturation

If you want to make a real mp3 player , use a DFPlayer Mini instead
This is just a proof of concept.

Components
- Micro SD card adapter
- Headphone input
- 2 buttons
- Arduino mini pro 3v

* Open MP3 with Audacity
* File/Export Audio
* Save as type: Other uncompressed files
* Header: Wav (Microsoft)
* Encoding : Unsigned 8_bit PCM
* Save to 0.wav

Wiring:
SD card 
1 --> X
2 --> 12
3 --> GND
4 --> 13
5 --> VCC
6 --> GND
7 --> 11
8 --> 10 (Chip select)

Audio: 6
Button Previous track: 7
Button Next track:8

Source: https://web.archive.org/web/20170430150220/http://garagelab.com/profiles/blogs/tutorial-playing-music-with-garagino-or-arduino-wav-player

*/
#include <SPI.h>
#include <SD.h>

File myFile;
const int b_prev = 8;
const int b_next = 7;
int file = 0;
bool playing = true;
String string_filename;
char* filename;
int check_buttons = 0;

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  pinMode(6, OUTPUT);
  TCCR0B = 0x01; // Sets the PWM frequency to 64KHz in pins 5 and 6.
  //while (!Serial) {
  //  ; // wait for serial port to connect. Needed for native USB port only
  //}


  Serial.print("Initializing SD card...");
  while (!SD.begin(10)) {
    Serial.println("initialization failed!");
  }

  Serial.println("initialization done.");

  //Enable buttons
  pinMode(b_prev, INPUT_PULLUP);
  pinMode(b_next, INPUT_PULLUP);

}

void loop() {
  //Convert string to char
  string_filename = String(file) + ".wav";
  unsigned int bufSize = string_filename.length() + 1; //String length + null terminator
  filename = new char[bufSize];
  string_filename.toCharArray(filename, bufSize);

  if (SD.exists(filename)) {
    Serial.println(string_filename);
    myFile = SD.open(filename, FILE_READ);
  }
  else {
    Serial.println(string_filename + "doesn't exists");
    file = 0;
  }


  unsigned char data; // Declares a variable to store data from the file.
  for (int count = 0; count < 128; count++) { // Jumps the header of the .wav file to access the data (after 128 readings). This number may also change for each file.
    data = myFile.read();  // Reads byte-by-byte until the end of the header.
  }
  Serial.println("Start");
  playing = true;
  check_buttons = 0;
  while (data != 255) {
    data = myFile.read();
    analogWrite(6, data); //Sends the data to pin 6 (pin connected to the speaker)
   // Waits for certain interval (in microseconds) for the next sample (according to the sample of the .wav file)
   // This time waiting makes the samples being nearer the 8KHz frequency of the file.
   // delayMicroseconds(10); 
   
    checkButtons();

    if (!playing) {
      break;
    }
  }


  //Serial.println("Stop");
  myFile.close();
  Serial.println("Replay");
  // nothing happens after setup finishes.
  delay(1000);

}

void checkButtons() {
  check_buttons++;
  //We reduce check because our arduino is really time sensitive when reading wav files.
  if (check_buttons == 1000) {
    check_buttons = 0;
    if (!digitalRead(b_prev)) {
      Serial.println("Button previous");
      file--;
      playing = false;
      delay(1000);
    }

    if (!digitalRead(b_next)) {
      Serial.println("Button next");
      file++;
      playing = false;
      delay(1000);
    }
  }
}


