/* KHIPU DE 5 CUERDAS MAPEO 
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// the MIDI continuous controller for each analog input

// potenciometros 
const int controllerA0 = 10; // 10 = pot general
const int controllerA1 = 1; // 11 = CUERDA 1 
const int controllerA4 = 4; // 14 = CUERDA 7 
const int controllerA5 = 5; // 15 = CUERDA 9 
const int controllerA7 = 7; // 17 = CUERDA 6 
const int controllerA8 = 8; // 18 = CUERDA 4 


//cuerdas
const int controllerA14 = 14; // 14 = CUERDA 1  
const int controllerA17 = 17; // 17 = CUERDA 7 
const int controllerA18 = 18; // 18 = CUERDA 9 
const int controllerA20 = 20; // 20 = CUERDA 6 
const int controllerA21 = 21; // 21 = CUERDA 4


// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.

 // 5 = 5 ms debounce time
Bounce button2 = Bounce(2, 5);  // which is appropriate for good
Bounce button3 = Bounce(3, 5);  // quality mechanical pushbuttons
Bounce button5 = Bounce(5, 5);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 5);  // to rapid touch, you can  // increase this time.
Bounce button9 = Bounce(9, 5);
Bounce button10 = Bounce(10, 5);


void setup() {
 
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ 2.0 LED, may need 1k resistor pullup
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  
}

// store previously sent values, to detect changes

int previousA0 = -1;
int previousA1 = -1;
int previousA4 = -1;
int previousA5 = -1;
int previousA7 = -1;
int previousA8 = -1;


int previousA14 = -1;
int previousA17 = -1;
int previousA18 = -1;
int previousA20 = -1;
int previousA21 = -1;

elapsedMillis msec = 0;

void loop() {
  // only check the analog inputs 50 times per second,
  // to prevent a flood of MIDI messages
 // if (msec >= 20) {
 if (msec >= 60) {
    msec = 0;
    
    //int n0 = analogRead(A0) / 8;

    
    //POTENCIOMETROS CUERDAS
    
    int p0 = analogRead(A0) / 8;
    int p1 = analogRead(A1) / 8;
    int p4 = analogRead(A4) / 8;
    int p5 = analogRead(A5) / 8;
    int p7 = analogRead(A7) / 8;
    int p8 = analogRead(A8) / 8;
   

        //CUERDAS
   int n14 = map(analogRead(A14), 10, 65, 0, 127);
    int n17 = map(analogRead(A17), 18, 65, 0, 127);
    int n18 = map(analogRead(A18), 17, 65, 0, 127);
    int n20 = map(analogRead(A20), 15, 65, 0, 127);
    int n21 = map(analogRead(A21), 13, 67, 0, 127);
    
    
    // only transmit MIDI messages if analog input changed
    
  //potenciometros 
  if (p0 != previousA0) {
      usbMIDI.sendControlChange(controllerA0, p0, channel);
      previousA0 = p0;
      }
    if (p1 != previousA1) {
      usbMIDI.sendControlChange(controllerA1, p1, channel);
      previousA1 = p1;
    }
   
    if (p4 != previousA4) {
      usbMIDI.sendControlChange(controllerA4, p4, channel);
      previousA4 = p4;
    }
    if (p5 != previousA5) {
      usbMIDI.sendControlChange(controllerA5, p5, channel);
      previousA5 = p5;
    }
    if (p7 != previousA7) {
      usbMIDI.sendControlChange(controllerA7, p7, channel);
      previousA7 = p7;
    }
    
    if (p8 != previousA8) {
      usbMIDI.sendControlChange(controllerA8, p8, channel);
      previousA8 = p8;
    }

   
    //cuerdas
    if (n14 != previousA14) {
      usbMIDI.sendControlChange(controllerA14, n14, channel);
      previousA14 = n14;
    }
   
   if (n17 != previousA17) {
      usbMIDI.sendControlChange(controllerA17, n17, channel);
      previousA17 = n17;
      }
      
   if (n18 != previousA18) {
      usbMIDI.sendControlChange(controllerA18, n18, channel);
      previousA18 = n18;
    }
    
    if (n20 != previousA20 ) {
      usbMIDI.sendControlChange(controllerA20 , n20 , channel);
      previousA20  = n20 ;
    }
    if (n21 != previousA21) {
      usbMIDI.sendControlChange(controllerA21, n21, channel);
      previousA21 = n21;
    }
    
  }


  
  button2.update();
  button3.update();
  button5.update();
  button6.update();
  button9.update();
  button10.update();


  // Check each button for "falling" edge.
  // Send a MIDI Note On message when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
 
 
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOn(61, 99, channel);  // 62 = D4
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOn(62, 99, channel);  // 63 = D#4
  }

  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOn(64, 99, channel);  // 65 = F4
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOn(65, 99, channel);  // 66 = F#4
  }
  
  if (button9.fallingEdge()) {
    usbMIDI.sendNoteOn(68, 99, channel);  // 69 = A5
  }
  if (button10.fallingEdge()) {
    usbMIDI.sendNoteOn(69, 99, channel);  // 70 = A#5
  }


  // Check each button for "rising" edge
  // Send a MIDI Note Off message when each button releases
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)

  
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOff(61, 0, channel);  // 62 = D4
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOff(62, 0, channel);  // 63 = D#4
  }
 
  if (button5.risingEdge()) {
    usbMIDI.sendNoteOff(64, 0, channel);  // 65 = F4
  }
  if (button6.risingEdge()) {
    usbMIDI.sendNoteOff(65, 0, channel);  // 66 = F#4
  }
 
  if (button9.risingEdge()) {
    usbMIDI.sendNoteOff(68, 0, channel);  // 69 = A5
  }
  if (button10.risingEdge()) {
    usbMIDI.sendNoteOff(69, 0, channel);  // 70 = A#5
  }


  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
 } 
 }
