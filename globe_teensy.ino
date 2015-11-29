
#include <Bounce.h>

const int channel = 1;
const int cc = 42;

Bounce button0 = Bounce(0, 5);
Bounce button1 = Bounce(2, 5);
Bounce button2 = Bounce(4, 5);
Bounce button3 = Bounce(6, 5);
Bounce button4 = Bounce(8, 5);
Bounce button5 = Bounce(10, 5);
Bounce button6 = Bounce(12, 5);
Bounce button7 = Bounce(14, 5);


// the setup() method runs once, when the sketch starts

void setup() {
  //PINS
  pinMode(0, INPUT_PULLUP);
  pinMode(1, OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, OUTPUT);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  pinMode(14, INPUT_PULLUP);
  pinMode(15, OUTPUT);
  
  usbMIDI.setHandleNoteOff(OnNoteOff); //FOR OUTGOING DATA
  usbMIDI.setHandleNoteOn(OnNoteOn);   //FOR OUTGOING DATA
}

void loop() {
  usbMIDI.read(); // USB MIDI receive
  
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();

  
  if (button0.fallingEdge()) {
    usbMIDI.sendControlChange(99, cc, channel);  //FOR INCOMING DATA
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendControlChange(98, cc, channel);  //FOR INCOMING DATA
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendControlChange(97, cc, channel);  //FOR INCOMING DATA
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendControlChange(95, cc, channel);  //FOR INCOMING DATA
  }
  if (button4.fallingEdge()) {
    usbMIDI.sendControlChange(88, cc, channel);  //FOR INCOMING DATA
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendControlChange(93, cc, channel);  //FOR INCOMING DATA
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendControlChange(90, cc, channel);  //FOR INCOMING DATA
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendControlChange(96, cc, channel);  //FOR INCOMING DATA
  }
}

//ADDING LED ON BLINK LOOP
void OnNoteOn(byte channel, byte note, byte velocity) {
 
  if (note==60) {
    digitalWrite(1, HIGH);   // set the LED on
  }
  if (note==61) {
    digitalWrite(3, HIGH);   // set the LED on
  }
  if (note==62) {
    digitalWrite(5, HIGH);   // set the LED on
  }
  if (note==64) {
    digitalWrite(7, HIGH);   // set the LED on
  }
  if (note==71) {
    digitalWrite(9, HIGH);   // set the LED on
  }
  if (note==66) {
    digitalWrite(11, HIGH);   // set the LED on
  }
  if (note==69) {
    digitalWrite(13, HIGH);   // set the LED on
  }
  if (note==63) {
    digitalWrite(15, HIGH);   // set the LED on
  }
  
}

void OnNoteOff(byte channel, byte note, byte velocity) {
  
  if (note==60) {
    digitalWrite(1, LOW);   // set the LED off
  }
  if (note==61) {
    digitalWrite(3, LOW);   // set the LED off
  }
  if (note==62) {
    digitalWrite(5, LOW);   // set the LED off
  }
  if (note==64) {
    digitalWrite(7, LOW);   // set the LED off
  }
  if (note==71) {
    digitalWrite(9, LOW);   // set the LED off
  }
  if (note==66) {
    digitalWrite(11, LOW);   // set the LED off
  }
  if (note==69) {
    digitalWrite(13, LOW);   // set the LED off
  }
  if (note==63) {
    digitalWrite(15, LOW);   // set the LED off
  }
  
}

