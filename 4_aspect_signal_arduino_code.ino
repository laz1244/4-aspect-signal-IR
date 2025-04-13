//******************************************************************
//*                                                                *
//*   CREATED BY ZAK BAKER/LAZ1244     COPYRIGHT ZAK BAKER 2024    *
//*                                                                *
//******************************************************************

#include <DIYables_IRcontroller.h> // DIYables_IRcontroller library
#define IR_RECEIVER_PIN 12 // The Arduino pin connected to IR controller

const int relaygreen = 10;       // the number of the green relay pin
const int relayred = 8;         // the number of the red relay pin
const int relaypreyellow = 11;   // the number of the pre-yellow relay pin
const int relayyellow = 9;      // the number of the yellow relay pin
int on = 0;

DIYables_IRcontroller_17 irController(IR_RECEIVER_PIN, 200); // debounce time is 200ms

void setup() {
  Serial.begin(9600);
  irController.begin();

  // Set pin modes
  pinMode(relayred, OUTPUT);
  pinMode(relaygreen, OUTPUT);
  pinMode(relayyellow, OUTPUT);
  pinMode(relaypreyellow, OUTPUT);
}


void loop() {

  Key17 key = irController.getKey();
  if (key != Key17::NONE) {
    switch (key) {
      case Key17::KEY_1:
        Serial.println("1");
        // Control LEDs and relays for KEY_1
        digitalWrite(relayred, HIGH);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      case Key17::KEY_4:
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      case Key17::KEY_7:
        Serial.println("7");
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, LOW);
        delay(200);
        break;

      case Key17::KEY_STAR:
        Serial.println("*");
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

      case Key17::KEY_SHARP:
        Serial.println("#");
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(200);
        break;

        case Key17::KEY_3:
        Serial.println("3");
        while (on<5) {
          digitalWrite(relayyellow, HIGH);
          digitalWrite(relaygreen, HIGH);
          digitalWrite(relaypreyellow, HIGH);
          digitalWrite(relayred, LOW);
          delay(500);
          digitalWrite(relayyellow, LOW);
          delay(900);
          digitalWrite(relayyellow, HIGH);
          delay(500);
          on = on + 1;
        }
        digitalWrite(relayyellow, LOW);
        on = 0;
        break;

        case Key17::KEY_6:
        Serial.println("6");
        while (on<5) {
          digitalWrite(relayyellow, HIGH);
          digitalWrite(relaygreen, HIGH);
          digitalWrite(relaypreyellow, HIGH);
          digitalWrite(relayred, LOW);
          delay(500);
          digitalWrite(relaypreyellow, LOW);
          digitalWrite(relayyellow, LOW);
          delay(900);
          digitalWrite(relayyellow, HIGH);
          digitalWrite(relaypreyellow, HIGH);
          delay(500);
          on = on + 1;
        }
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, LOW);
        on = 0;
        break;

      case Key17::KEY_9:
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        digitalWrite(relayred, LOW);
        delay(2000);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        digitalWrite(relayred, HIGH);
        delay(2000);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, HIGH);
        digitalWrite(relayred, LOW);
        delay(2000);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, LOW);
        digitalWrite(relayred, LOW);
        delay(2000);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        digitalWrite(relayred, LOW);
        delay(500);
        break;

      case Key17::KEY_0:
        Serial.println("6");
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(400);
        digitalWrite(relayred, HIGH);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, LOW);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, LOW);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, HIGH);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(400);
        digitalWrite(relayred, HIGH);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, LOW);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, LOW);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, LOW);
        digitalWrite(relayyellow, LOW);
        digitalWrite(relaypreyellow, HIGH);
        delay(400);
        digitalWrite(relayred, LOW);
        digitalWrite(relaygreen, HIGH);
        digitalWrite(relayyellow, HIGH);
        digitalWrite(relaypreyellow, HIGH);
        break;

      default:
        Serial.println("WARNING: undefined key:");
        break;
    }
  }
}

