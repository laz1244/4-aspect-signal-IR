//******************************************************************
//*                                                                *
//*   CREATED BY ZAK BAKER/LAZ1244     COPYRIGHT ZAK BAKER 2024    *
//*                                                                *
//******************************************************************

#include <DIYables_IRcontroller.h> // DIYables_IRcontroller library
#define IR_RECEIVER_PIN 12 // The Arduino pin connected to IR controller

const int buttonPin = 13;  // the number of the pushbutton pin
const int green = 5;       // the number of the green LED pin
const int red = 2;         // the number of the red LED pin
const int preyellow = 4;   // the number of the pre-yellow LED pin
const int yellow = 3;      // the number of the yellow LED pin
const int relaygreen = 10;       // the number of the green relay pin
const int relayred = 8;         // the number of the red relay pin
const int relaypreyellow = 11;   // the number of the pre-yellow relay pin
const int relayyellow = 9;      // the number of the yellow relay pin

DIYables_IRcontroller_17 irController(IR_RECEIVER_PIN, 200); // debounce time is 200ms

void setup() {
  Serial.begin(9600);
  irController.begin();

  // Set pin modes
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(preyellow, OUTPUT);
  pinMode(relayred, OUTPUT);
  pinMode(relaygreen, OUTPUT);
  pinMode(relayyellow, OUTPUT);
  pinMode(relaypreyellow, OUTPUT);
  pinMode(buttonPin, INPUT); // If you plan to use the button
}

void loop() {
  Key17 key = irController.getKey();
  if (key != Key17::NONE) {
    switch (key) {
      case Key17::KEY_1:
        Serial.println("1");
        // Control LEDs and relays for KEY_1
        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(preyellow, LOW);
        digitalWrite(relayred, HIGH);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      case Key17::KEY_4:
        Serial.println("4");
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(yellow, HIGH);
        digitalWrite(preyellow, LOW);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      case Key17::KEY_7:
        Serial.println("7");
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(yellow, HIGH);
        digitalWrite(preyellow, HIGH);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, LOW);
        delay(200);
        break;

      case Key17::KEY_STAR:
        Serial.println("*");
        digitalWrite(red, LOW);
        digitalWrite(green, HIGH);
        digitalWrite(yellow, LOW);
        digitalWrite(preyellow, LOW);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      case Key17::KEY_SHARP:
        Serial.println("#");
        digitalWrite(red, LOW);
        digitalWrite(green, LOW);
        digitalWrite(yellow, LOW);
        digitalWrite(preyellow, LOW);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      default:
        Serial.println("WARNING: undefined key:");
        break;
    }
  }
}