#include <Servo.h>

Servo myservo1;  // create servo objects to control the servos
Servo myservo2;
int servoPin1 = 3;
int servoPin2 = 5;
int pushButtonPin1 =2;// the pin where push button is connected
int pushButtonPin2 = 6;
int angle =180;    // initial angle  for servos
int angleStep = 90;
int angle2 =25;   
int angleStep2 =25;
int buttonState = 0;  // variables for reading the pushbutton status
int buttonState2 = 0; 

void setup() {
  myservo1.attach(servoPin1);  // attaches the servo on pin 9 to the servo object
  myservo2.attach(servoPin2);
  pinMode(pushButtonPin1,INPUT);
  pinMode(pushButtonPin2,INPUT);
  pinMode(7, OUTPUT);
  Serial.begin(9600);
  Serial.print("Hello");
  
}
void loop() { 

  buttonState = digitalRead(pushButtonPin1);
  buttonState2 = digitalRead(pushButtonPin2);
  Serial.println(buttonState);
  if(buttonState == HIGH){
  // change the angle for next time through the loop:
    angle = angle - angleStep;

    // reverse the direction of the moving at the ends of the angle:
    if (angle <= 90 || angle >= 180) {
      delay(500);
      angleStep = -angleStep;
    }  
  myservo1.write(angle); // move the servo to desired angle

  delay(200); // waits for the servo to get there
  }
  if(buttonState2 == HIGH){
  // change the angle for next time through the loop:
    angle2 = angle2 + angleStep2;

    // reverse the direction of the moving at the ends of the angle:
    if (angle2 <= 20 || angle2 >= 50) {
      angleStep2 = -angleStep2;
    }  
  myservo2.write(angle2); // move the servo to desired angle

  delay(200); // waits for the servo to get there
  }
}

