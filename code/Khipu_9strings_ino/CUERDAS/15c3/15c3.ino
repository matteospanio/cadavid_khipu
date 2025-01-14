/* KIPU
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// the MIDI continuous controller for each analog input

// CUERDAS
const int controllerA15 = 15; // 11 = CUERDA 1 

void setup() {
  Serial.begin(38400);
}

// store previously sent values, to detect changes

int previousA15 = -1;


elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
 // if (msec >= 20) {
 if (msec >= 60) {
    msec = 0;
    
    //int n0 = analogRead(A0) / 8;
    //CUERDAS
   int n15 = map(analogRead(A15), 7, 80, 0, 127);
   Serial.println(n15);
   //delay(250);

    
    // only transmit MIDI messages if analog input changed
    
    if (n15 != previousA15) {
      usbMIDI.sendControlChange(controllerA15, n15, channel);
      previousA15 = n15;
    }
    
    
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
 } 
}
