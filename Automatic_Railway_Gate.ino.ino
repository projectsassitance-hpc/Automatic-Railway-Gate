

#include <Servo.h>

const int irSensorPin = 8; // IR sensor signal pin
Servo myServo; // Only one servo

void setup() {
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
  myServo.attach(6); // Servo motor pin

  Serial.begin(9600); // Serial monitor setup
}

void loop() {
  int irSensorState = digitalRead(irSensorPin); // Read the state of the IR sensor

  Serial.print("IR Sensor State: ");
  Serial.println(irSensorState);

  if (irSensorState == LOW) { // Object detected by IR sensor (LOW means object detected)
    myServo.write(90); // Rotate servo to 90 degrees
  } else { // No object detected by IR sensor (HIGH means no object)
    myServo.write(0); // Rotate servo to 0 degrees
  }

  delay(500); // Wait for the servo to reach position
}
