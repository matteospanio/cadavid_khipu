/* KIPU
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// the MIDI continuous controller for each analog input

// CUERDAS
const int controllerA18 = 18; // 11 = CUERDA 1 

void setup() {
  Serial.begin(38400);
}

// store previously sent values, to detect changes

int previousA18 = -1;


elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
 // if (msec >= 18) {
 if (msec >= 60) {
    msec = 0;
    
    //int n0 = analogRead(A0) / 8;
    //CUERDAS
   int n18 = map(analogRead(A18), 17, 65, 20, 127);
   Serial.println(n18);
   //delay(250);

    
    // only transmit MIDI messages if analog input changed
    
    if (n18 != previousA18) {
      usbMIDI.sendControlChange(controllerA18, n18, channel);
      previousA18 = n18;
    }
    
    
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24189-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
 } 
}
