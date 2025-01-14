/* KIPU
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// the MIDI continuous controller for each analog input

// CUERDAS
const int controllerA14 = 14; // 11 = CUERDA 1 
const int controllerA15 = 15; // 11 = CUERDA 1 
const int controllerA16 = 16; // 11 = CUERDA 1 
//const int controllerA17 = 17; // 11 = CUERDA 1 
const int controllerA18 = 18; // 11 = CUERDA 1 
const int controllerA19 = 19; // 11 = CUERDA 1 
const int controllerA20 = 20; // 11 = CUERDA 1 
const int controllerA21 = 21; // 11 = CUERDA 1 
const int controllerA22 = 22; // 11 = CUERDA 1 
void setup() {
  Serial.begin(38400);
}

// store previously sent values, to detect changes

int previousA14 = -1;
int previousA15 = -1;
int previousA16 = -1;
//int previousA17 = -1;
int previousA18 = -1;
int previousA19 = -1;
int previousA20 = -1;
int previousA21 = -1;
int previousA22 = -1;

elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
 // if (msec >= 20) {
 if (msec >= 60) {
    msec = 0;
    
    //int n0 = analogRead(A0) / 8;
    //CUERDAS
   int n14 = map(analogRead(A14), 10, 75, 0, 127);
   Serial.println(n14);
   int n15 = map(analogRead(A15), 11, 70, 0, 127);
   Serial.println(n15);
    int n16 = map(analogRead(A16), 15, 80, 0, 127);
   Serial.println(n16);
    /*int n17 = map(analogRead(A17), 18, 70, 0, 127);
   Serial.println(n17);*/
int n18 = map(analogRead(A18), 17, 65, 20, 127);
   Serial.println(n18);
   int n19 = map(analogRead(A19), 14, 68, 0, 127);
   Serial.println(n19);

    int n20 = map(analogRead(A20), 15, 65, 0, 127);
   Serial.println(n20);
    int n21 = map(analogRead(A21), 13, 67, 0, 127);
   Serial.println(n21);

   int n22 = map(analogRead(A22), 18, 70, 0, 127);
   Serial.println(n22);
    // only transmit MIDI messages if analog input changed
    
    if (n14 != previousA14) {
      usbMIDI.sendControlChange(controllerA14, n14, channel);
      previousA14 = n14;
    }
    if (n15 != previousA15) {
      usbMIDI.sendControlChange(controllerA15, n15, channel);
      previousA15 = n15;
    }
    if (n16 != previousA16) {
      usbMIDI.sendControlChange(controllerA16, n16, channel);
      previousA16 = n16;
    }
       
       
       delay(100);
/* if (n17 != previousA17) {
      usbMIDI.sendControlChange(controllerA17, n17, channel);
      previousA17 = n17;
  }*/

  if (n18 != previousA18) {
      usbMIDI.sendControlChange(controllerA18, n18, channel);
      previousA18 = n18;
    }

  if (n19 != previousA19) {
      usbMIDI.sendControlChange(controllerA19, n19, channel);
      previousA19 = n19;
    }
if (n20 != previousA20) {
      usbMIDI.sendControlChange(controllerA20, n20, channel);
      previousA20 = n20;
    }
 if (n21 != previousA21) {
      usbMIDI.sendControlChange(controllerA21, n21, channel);
      previousA21 = n21;
    } 

          
    if (n22 != previousA22) {
      usbMIDI.sendControlChange(controllerA22, n22, channel);
      previousA22 = n22;
    }
    

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
 } 
}
}
