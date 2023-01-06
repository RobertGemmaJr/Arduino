#include <Servo.h>
#include <ezButton.h>



// Servo position for hand fully open/closed
const Servo HAND_SERVO;
const byte HAND_CLOSED_POS = 0;
const byte HAND_OPEN_POS = 170;

// Servo position for door fully open/closed
const Servo DOOR_SERVO;
const byte DOOR_CLOSED_POS = 0;
const byte DOOR_OPEN_POS = 45;

// Toggle Switch is on digital 3
const ezButton toggleSwitch(3);


void setup() {
  Serial.begin(9600);
  Serial.println();

  // Attach servos on PWM 9 and 10
  HAND_SERVO.attach(9);
  DOOR_SERVO.attach(10);

  // Set 50ms debounce delay
  toggleSwitch.setDebounceTime(50);

  // TODO: If initial reading is open do basic move?
  DOOR_SERVO.write(DOOR_CLOSED_POS);
  HAND_SERVO.write(HAND_CLOSED_POS);

  // TEMP - Debug
  basic_move(1000); // TEMP
  
  if (toggleSwitch.isPressed())
    Serial.println("The switch: OFF -> ON");
  if (toggleSwitch.isReleased())
    Serial.println("The switch: ON -> OFF");
  Serial.println(toggleSwitch.getState() == LOW);

  // Door open works fine for now, would need to match gears for flap opening to work properly
}

void loop() {
//   toggleSwitch.loop();
//   int switchState = toggleSwitch.getState();

//   // TEMP - Debug
//   if (toggleSwitch.isPressed())
//     Serial.println("The switch: OFF -> ON");

//   if (toggleSwitch.isReleased())
//     Serial.println("The switch: ON -> OFF");

//   if(switchState == LOW) basic_move(1000);
}

// MOVES

void basic_move(unsigned short moveTime) {
  unsigned long startTime = millis();

  // Move hand
  for (unsigned long t = 0; t < moveTime; t = millis() - startTime) {
    byte angle = map(t, 0, moveTime, HAND_CLOSED_POS, HAND_OPEN_POS);
    HAND_SERVO.write(angle);
  }

  // Hide hand
  startTime = millis();
  for (unsigned long t = 0; t < moveTime; t = millis() - startTime) {
    byte angle = map(t, 0, moveTime, HAND_OPEN_POS, HAND_CLOSED_POS);
    HAND_SERVO.write(angle);
  }
}



/* ORIGINAL CODE*/


// if (testMove != 0) selectedMove = testMove;

// if the switch is on, then move door and hand to switch it off...
// if (digitalRead(SWITCH_PIN) == HIGH) {
// Debugging
// switch_off();

// TODO: Convert to switch statement
// switch (selectedMove)
// {
//     case > 10:
//     // when all moves are played, repeat the moves from beginning
//         selectedMove = 0
//     case 0
//     default:
//         break;
// }

// if (selectedMove == 0) { switch_off(); }
// else if (selectedMove == 1) { switch_off(); }
// else if (selectedMove == 2) { step_by_step(); }
// else if (selectedMove == 3) { crazy_door(); }
// else if (selectedMove == 4) { crazy_slow(); }
// else if (selectedMove == 5) { m7anika7anika(); }
// else if (selectedMove == 6) { m3alla2(); }
// else if (selectedMove == 7) { switch_off(); }
// else if (selectedMove == 8) { matrix(); }
// else if (selectedMove == 9) { sneak(); }
// else if (selectedMove == 10) { zee7(); }

// TODO: Mod by 10
// Switch to next move if not in test mode
// if (testMove == 0) {
//     selectedMove++;
//     //when all moves are played, repeat the moves from beginning
//     if (selectedMove > 10) { selectedMove = 0; }
// }
// }

// Library of moves
/*
// basic move
void switch_off() {
  // Moving door
  for (int pos = 80; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // Moving hand
  for (int pos = 0; pos < 129; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding hand
  for (int pos = 129; pos >= 0; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 155; pos >= 80; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

// move 3: open and wait, then move hand and wait, then switch of and hide
void step_by_step() {
  // Moving door
  for (int pos = 80; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  delay(800);
  // Moving hand
  for (int pos = 0; pos < 100; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  delay(1000);
  for (int pos = 100; pos < 129; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding hand
  for (int pos = 129; pos >= 0; pos -= 5) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 155; pos >= 80; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

// move 4: open door then close it many times, wait, then quickly reoprn a nd switch off and hide.
void crazy_door() {

  // Moving door
  for (int pos = 80; pos < 125; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 125; pos >= 80; pos -= 5) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  // Moving door
  for (int pos = 80; pos < 110; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 110; pos >= 80; pos -= 15) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  delay(700);
  // Moving door
  for (int pos = 80; pos < 125; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  delay(700);
  // hiding door
  for (int pos = 125; pos >= 80; pos -= 5) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  //----of switch of----//
  // Moving door
  for (int pos = 80; pos < 155; pos += 8) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // Moving hand
  for (int pos = 0; pos < 129; pos += 3) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding hand
  for (int pos = 129; pos >= 0; pos -= 3) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 155; pos >= 80; pos -= 15) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

// move 5: open door, then move hand very slowly forward and back to hiding very slowly, then quickly close door
void crazy_slow() {

  // Moving door
  for (int pos = 80; pos < 155; pos += 1) {
    DOOR_SERVO.write(pos);
    delay(30);
  }

  // Moving hand
  for (int pos = 0; pos < 129; pos += 1) {
    HAND_SERVO.write(pos);
    delay(30);
  }

  // hiding hand
  for (int pos = 129; pos >= 0; pos -= 1) {
    HAND_SERVO.write(pos);
    delay(30);
  }

  // hiding door
  for (int pos = 155; pos >= 125; pos -= 1) {
    DOOR_SERVO.write(pos);
    delay(30);
  }
  delay(100);
  for (int pos = 125; pos >= 80; pos -= 4) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

// move 6:

void m7anika7anika() {

  // Moving door
  for (int pos = 80; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // Moving hand
  for (int pos = 0; pos < 70; pos += 1) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  delay(800);

  // hiding door
  for (int pos = 155; pos >= 130; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 130; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  // hiding door
  for (int pos = 155; pos >= 130; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  // hiding door
  for (int pos = 130; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  HAND_SERVO.write(40);
  delay(1000);

  // Moving hand
  for (int pos = 40; pos < 129; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding hand
  for (int pos = 129; pos >= 0; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  for (int pos = 120; pos >= 80; pos -= 1) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

void m3alla2() {
  // Moving door
  for (int pos = 80; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // Moving hand
  for (int pos = 0; pos < 127; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  // hiding door
  for (int pos = 155; pos >= 130; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  delay(2000);

  for (int pos = 130; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  for (int pos = 155; pos >= 140; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  for (int pos = 140; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  delay(500);
  // hiding hand
  for (int pos = 127; pos >= 0; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  // hiding door
  for (int pos = 155; pos >= 80; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

void matrix() {

  // Moving door
  for (int pos = 80; pos < 155; pos += 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }

  // Moving hand
  for (int pos = 0; pos < 80; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }

  for (int pos = 80; pos < 129; pos += 1) {
    HAND_SERVO.write(pos);
    delay(30);
  }
  delay(300);

  for (int pos = 129; pos >= 0; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(10);
  }

  // hiding door
  for (int pos = 155; pos >= 80; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

void sneak() {
  // Moving door
  for (int pos = 80; pos < 130; pos += 1) {
    DOOR_SERVO.write(pos);
    delay(30);
  }
  delay(2000);

  // Moving hand
  for (int pos = 0; pos < 40; pos += 1) {
    HAND_SERVO.write(pos);
    delay(30);
  }

  delay(500);

  for (int pos = 130; pos < 155; pos += 4) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
  delay(100);

  for (int pos = 40; pos < 90; pos += 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  delay(500);
  // hiding hand
  for (int pos = 90; pos >= 70; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  delay(100);
  for (int pos = 70; pos < 90; pos += 4) {

    HAND_SERVO.write(pos);
    delay(15);
  }
  delay(100);
  for (int pos = 90; pos >= 70; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  delay(100);

  for (int pos = 70; pos < 129; pos += 4) {

    HAND_SERVO.write(pos);
    delay(15);
  }

  for (int pos = 129; pos >= 0; pos -= 4) {
    HAND_SERVO.write(pos);
    delay(15);
  }
  // hiding door
  for (int pos = 155; pos >= 80; pos -= 3) {
    DOOR_SERVO.write(pos);
    delay(15);
  }
}

// TODO: Don't need?
// void zee7() {
//   // Moving door
//   for (int pos = 80; pos < 155; pos += 3) {
//     DOOR_SERVO.write(pos);
//     delay(15);
//   }
//   delay(2000);
//   // forward @ full speed to the left
//   digitalWrite(motorDirection, LOW);  // Establishes RIGHT direction of Channel A
//   digitalWrite(motorBrake, LOW);      // Disengage the Brake for Channel B
//   analogWrite(motorThrottle, 100);    // Spins the motor on Channel B at full speed
//   delay(300);
//   digitalWrite(motorBrake, HIGH);  // Eengage the Brake for Channel B
//   delay(2000);

//   // backward @ full speed to the right
//   digitalWrite(motorDirection, HIGH);  // Establishes LEFT direction of Channel B
//   digitalWrite(motorBrake, LOW);       // Disengage the Brake for Channel B
//   analogWrite(motorThrottle, 100);     // Spins the motor on Channel B at half speed
//   delay(300);
//   digitalWrite(motorBrake, HIGH);  // Eengage the Brake for Channel B
//   delay(1000);

//   // Moving hand
//   for (int pos = 0; pos < 129; pos += 4) {
//     HAND_SERVO.write(pos);
//     delay(15);
//   }

//   // hiding hand
//   for (int pos = 129; pos >= 0; pos -= 4) {
//     HAND_SERVO.write(pos);
//     delay(15);
//   }

//   // hiding door
//   for (int pos = 155; pos >= 80; pos -= 3) {
//     DOOR_SERVO.write(pos);
//     delay(15);
//   }
// }
*/
