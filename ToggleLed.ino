/*
	LED CONTROLLED FROM BUTTON or FROM TRANSISTOR
*/

// set pin numbers:
const int pinSwitch = 2;     // the number of the pushbutton pin
const int transistorPin = 3; // the transistor pin
const int pinLed =  13;      // the number of the LED pin

bool incomingByte = false;
boolean oldSwitchState = LOW;
boolean newSwitchState = LOW;
boolean LEDstatus = LOW;
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
 
void setup() {
  // initialize the LED pin as an output:
  pinMode(pinLed, OUTPUT);
  pinMode(transistorPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(pinSwitch, INPUT);
  
  Serial.begin(9600);
}
 
void loop() {
  // read the state of the pushbutton value:
  newSwitchState  = digitalRead(pinSwitch);
 
  // read from serial and control led
  // read the state of the pushbutton value:
  newSwitchState  = digitalRead(pinSwitch);
 
  // read from serial and control led
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    // turn LED on:
    digitalWrite(transistorPin, HIGH);
    delay(5000);
  }else{
    incomingByte = Serial.read();
    // turn LED off:
  	digitalWrite(transistorPin, LOW);
  }

  
  
  
  // read the status from the switchpin
  newSwitchState = digitalRead(pinSwitch);
  //if the switch is pressed or unpressed 
  //compare with the previous state
  if ( newSwitchState != oldSwitchState )
  {
    // has the button switch been closed?
    if ( newSwitchState == HIGH )
    {
      //check if what the status is of the LED.
      if ( LEDstatus == LOW ) {
        digitalWrite(pinLed, HIGH);
        LEDstatus = HIGH;
      }
      // if the LED is on and the switch is pressed again
      else                    {
        digitalWrite(pinLed, LOW);
        LEDstatus = LOW;
      }
    }
    // save the state of the switch so It can be compared
    oldSwitchState = newSwitchState;
  }
}