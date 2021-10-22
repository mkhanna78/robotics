// C++ code
//
#include <Servo.h>

int v_dist = 0;

Servo servo_6;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void setup()
{
  servo_6.attach(6, 500, 2500);

  pinMode(8, OUTPUT);
}

void loop()
{
  servo_6.write(0);
  v_dist = 0.01723 * readUltrasonicDistance(0, 0);
  if (v_dist < 75) {
    servo_6.write(90);
    digitalWrite(8, HIGH);
    delay(2000); // Wait for 2000 millisecond(s)
  }
  servo_6.write(0);
  digitalWrite(8, LOW);
}