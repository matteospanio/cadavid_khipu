/* KIPU
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// the MIDI continuous controller for each analog input

// CUERDAS
const int controllerA20 = 20; // 11 = CUERDA 1 

void setup() {
  Serial.begin(38400);
}

// store previously sent values, to detect changes

int previousA20 = -1;


elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
 // if (msec >= 20) {
 if (msec >= 60) {
    msec = 0;
    
    //int n0 = analogRead(A0) / 8;
    //CUERDAS
   int n20 = map(analogRead(A20), 12, 80, 0, 127);
   Serial.println(n20);
   //delay(250);

    
    // only transmit MIDI messages if analog input changed
    
    if (n20 != previousA20) {
      usbMIDI.sendControlChange(controllerA20, n20, channel);
      previousA20 = n20;
    }
    
    
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
 } 
}
