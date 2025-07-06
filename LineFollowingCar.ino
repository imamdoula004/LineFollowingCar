// Define motor pins
#define rmb 3    // Right Motor Backward
#define rmf 9    // Right Motor Forward
#define lmb 10   // Left Motor Backward
#define lmf 11   // Left Motor Forward

// Define speed constant
#define spd 60   // Base speed for the motors

// Setup function: initialize serial communication and set motor pins as outputs
void setup() {
  Serial.begin(9600);
  pinMode(rmb, OUTPUT);
  pinMode(rmf, OUTPUT);
  pinMode(lmb, OUTPUT);
  pinMode(lmf, OUTPUT);
}

// Pattern variables to track sensor readings
String patt, lastpatt;

void loop() {
  // Read sensor values (inverted because of active-low logic)
  int sen_l = !digitalRead(A2); // Left sensor
  int sen_m = !digitalRead(A3); // Middle sensor
  int sen_r = !digitalRead(A4); // Right sensor

  // Combine sensor readings into a binary string pattern
  patt = String(sen_l) + String(sen_m) + String(sen_r);

  // Debug output of the sensor pattern
  Serial.println(patt);

  // Decision tree based on sensor pattern
  if (patt == "010") {
    forward(); // Go straight
  } 
  else if (patt == "011") {
    rightForward(); // Slight right curve
  } 
  else if (patt == "001") {
    right(); // Hard right
  } 
  else if (patt == "110") {
    leftForward(); // Slight left curve
  } 
  else if (patt == "100") {
    left(); // Hard left
  } 
  else if (patt == "000") {
    // Lost line - perform U-turn based on last known direction
    if (lastpatt == "100") {
      leftU(); // Last turn was left, recover with left U-turn
    } 
    else if (lastpatt == "001") {
      rightU(); // Last turn was right, recover with right U-turn
    }
  } 
  else if (patt == "111") {
    stop(); // All sensors see line — stop at junction or endpoint
  }

  // Save current pattern for future U-turn decision
  lastpatt = patt;
}

// Move both motors forward
void forward() {
  analogWrite(rmf, spd);
  analogWrite(lmf, spd);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

// Move both motors backward
void backward() {
  analogWrite(rmb, spd);
  analogWrite(lmb, spd);
  analogWrite(rmf, 0);
  analogWrite(lmf, 0);
}

// Hard right turn — right motor slow/stop, left motor moves
void right() {
  analogWrite(rmf, spd / 2);
  analogWrite(lmf, spd);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

// Recovery right U-turn — spin right wheel backward and left wheel forward
void rightU() {
  analogWrite(rmb, spd / 2);
  analogWrite(lmf, spd / 2);
  analogWrite(rmf, 0);
  analogWrite(lmb, 0);
}

// Hard left turn — left motor slow/stop, right motor moves
void left() {
  analogWrite(rmf, spd);
  analogWrite(lmf, spd / 2);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

// Recovery left U-turn — spin left wheel backward and right wheel forward
void leftU() {
  analogWrite(rmf, spd / 2);
  analogWrite(lmb, spd / 2);
  analogWrite(rmb, 0);
  analogWrite(lmf, 0);
}

// Slight right turn while moving forward — right motor slower
void rightForward() {
  analogWrite(rmf, spd * 2 / 3);
  analogWrite(lmf, spd);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

// Slight left turn while moving forward — left motor slower
void leftForward() {
  analogWrite(rmf, spd);
  analogWrite(lmf, spd * 2 / 3);
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
}

// Stop all motor movement
void stop() {
  analogWrite(rmb, 0);
  analogWrite(lmb, 0);
  analogWrite(rmf, 0);
  analogWrite(lmf, 0);
}
