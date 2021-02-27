#include <Servo.h>

Servo myservo1;
Servo myservo2;
Servo myservo3;
Servo myservo4;

int pos = 0;

void setup() {
    myservo1.attach(2);
    myservo2.attach(3);
    myservo3.attach(4);
    myservo4.attach(5);
}

void loop() {
  for (pos = 60; pos <= 120; pos += 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);

    delay(15);
  }
  for (pos = 120; pos >= 60; pos -= 1) {
    myservo1.write(pos);
    myservo2.write(pos);
    myservo3.write(pos);
    myservo4.write(pos);

    delay(15);
  }
}
