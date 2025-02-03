/* KIPU
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// the MIDI continuous controller for each analog input

// CUERDAS
const int controllerA1 = 11; // 11 = CUERDA 1 
const int controllerA2 = 12; // 91 = CUERDA 2 
const int controllerA3 = 13; // 93 = CUERDA 3 
const int controllerA4 = 4; // 10 = CUERDA 4 
const int controllerA5 = 15; // 11 = CUERDA 5 
const int controllerA6 = 16; // 91 = CUERDA 6 
const int controllerA7 = 17; // 93 = CUERDA 7 
const int controllerA8 = 18; // 10 = CUERDA 8 
const int controllerA9 = 19; // 11 = CUERDA 9 

//POTENCIOMETROS
const int controllerA15 = 21; // 91 = POT CUERDA 1 
const int controllerA16 = 22; // 93 = POT CUERDA 2 
const int controllerA17 = 23; // 10 = POT CUERDA 3 
const int controllerA19 = 24; // 11 = POT CUERDA 4 
const int controllerA12 = 25; // 91 = POT CUERDA 5 
const int controllerA14= 26; // 93 = POT CUERDA 6 
const int controllerA13 = 27; // 10 = POT CUERDA 7
const int controllerA11 = 28; // 11 = POT CUERDA 8 
const int controllerA10 = 29; // 91 = POT CUERDA 9


void setup() {
}

// store previously sent values, to detect changes

int previousA1 = -1;
int previousA2 = -1;
int previousA3 = -1;
int previousA4 = -1;
int previousA5 = -1;
int previousA6 = -1;
int previousA7 = -1;
int previousA8 = -1;
int previousA9 = -1;
int previousA15 = -1;
int previousA16 = -1;
int previousA17 = -1;
int previousA19 = -1;
int previousA12 = -1;
int previousA14 = -1;
int previousA13 = -1;
int previousA11 = -1;
int previousA10 = -1;

elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
 // if (msec >= 20) {
 if (msec >= 60) {
    msec = 0;
    
    //int n0 = analogRead(A0) / 8;
    //CUERDAS
   int n1 = map(analogRead(A1), 2, 759, 0, 127);
    int n2 = map(analogRead(A2), 2, 770, 0, 127);
    int n3 = map(analogRead(A3), 2, 770, 0, 127);
    int n4 = map(analogRead(A4), 2, 768, 0, 127);
    int n5 = map(analogRead(A5), 2, 762, 0, 127);
    int n6 = map(analogRead(A6), 2, 744, 0, 127);
    int n7 = map(analogRead(A7), 2, 786, 0, 127);
    int n8 = map(analogRead(A8), 2, 914, 0, 127);
    int n9 = map(analogRead(A9), 2, 754, 0, 127);
    
    //POTENCIOMETROS CUERDAS
    
    int n15 = analogRead(A15) / 8;
    int n16 = analogRead(A16) / 8;
    int n17 = analogRead(A17) / 8;
    int n19 = analogRead(A19) / 8;
    int n12 = analogRead(A12) / 8;
    int n14 = analogRead(A14) / 8;
    int n13 = analogRead(A13) / 8;
    int n11 = analogRead(A11) / 8;
    int n10 = analogRead(A10) / 8;
    
    // only transmit MIDI messages if analog input changed
    
    if (n1 != previousA1) {
      usbMIDI.sendControlChange(controllerA1, n1, channel);
      previousA1 = n1;
    }
    if (n2 != previousA2) {
      usbMIDI.sendControlChange(controllerA2, n2, channel);
      previousA2 = n2;
    }
    if (n3 != previousA3) {
      usbMIDI.sendControlChange(controllerA3, n3, channel);
      previousA3 = n3;
    }
    if (n4 != previousA4) {
      usbMIDI.sendControlChange(controllerA4, n4, channel);
      previousA4 = n4;
    }
    if (n5 != previousA5) {
      usbMIDI.sendControlChange(controllerA5, n5, channel);
      previousA5 = n5;
    }
    if (n6 != previousA6) {
      usbMIDI.sendControlChange(controllerA6, n6, channel);
      previousA6 = n6;
    }
    if (n7 != previousA7) {
      usbMIDI.sendControlChange(controllerA7, n7, channel);
      previousA7 = n7;
    }
    if (n8 != previousA8) {
      usbMIDI.sendControlChange(controllerA8, n8, channel);
      previousA8 = n8;
    }
    if (n9 != previousA9) {
      usbMIDI.sendControlChange(controllerA9, n9, channel);
      previousA9 = n9;
    }
    //POT
    if (n15 != previousA15) {
      usbMIDI.sendControlChange(controllerA15, n15, channel);
      previousA15 = n15;
    }
    if (n16 != previousA16 ) {
      usbMIDI.sendControlChange(controllerA16 , n16 , channel);
      previousA16  = n16 ;
    }
   if (n17 != previousA17) {
      usbMIDI.sendControlChange(controllerA17, n17, channel);
      previousA17 = n17;
    }
    if (n19 != previousA19) {
      usbMIDI.sendControlChange(controllerA19, n19, channel);
      previousA19 = n19;
    }
    if (n12 != previousA12) {
      usbMIDI.sendControlChange(controllerA12, n12, channel);
      previousA12 = n12;
    }
    if (n14 != previousA14) {
      usbMIDI.sendControlChange(controllerA14, n14, channel);
      previousA14 = n14;
    }
    if (n13 != previousA13 ) {
      usbMIDI.sendControlChange(controllerA13 , n13 , channel);
      previousA13  = n13 ;
    }
    if (n11 != previousA11) {
      usbMIDI.sendControlChange(controllerA11, n11, channel);
      previousA11 = n11;
    }
    if (n10 != previousA10) {
      usbMIDI.sendControlChange(controllerA10, n10, channel);
      previousA10 = n10;
    }
    
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
 } 
}
