#include <ESP32Servo.h>
// pastikan sudah install library ESP32Servo

  const int trigPin = 13;
  const int echoPin = 12;
  const int buzzerPin = 14;
  const int servoPin = 27;
  const int redPin = 26;
  const int yellowPin = 25;
  const int greenPin = 33;

const int servoDefaultWrite = 0;

long duration;
int distance;
Servo servo;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzerPin, OUTPUT);
  servo.attach(servoPin);

  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);

  Serial.begin(115200);

  servo.write(servoDefaultWrite);
  digitalWrite(buzzerPin, LOW);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Jarak : ");
  Serial.print(distance);
  Serial.println(" cm");

  // ------------------------

  if (distance < 7) {
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
    delay(350);
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
    // ------
    digitalWrite(buzzerPin, HIGH);
    servo.write(115);
    delay(3500);

  } else {
    digitalWrite(buzzerPin, LOW);
    servo.write(servoDefaultWrite);
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }


  delay(250);
}