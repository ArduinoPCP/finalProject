#include <Servo.h>

#include "Arduino.h"
#include "SoftwareSerial.h" (())
#include "DFRobotDFPlayerMini.h"

Servo myservo1;
Servo myservo2;

SoftwareSerial mySoftwareSerial(11, 12); // RX, TX
DFRobotDFPlayerMini myDFPlayer;
void printDetail(uint8_t type, int value);

#define pp 3
#define nxt 6

int v= 30;

long randNumber;
const int buttonPin = 2;
int buttonState = 0;
int working = 0;

void setup() {

  Serial.begin(9600);

  myDFPlayer.begin(mySoftwareSerial);
  mySoftwareSerial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT); 
  myservo1.attach(9);
  myservo2.attach(10);

  pinMode(pp,INPUT_PULLUP);
  pinMode(nxt,INPUT_PULLUP);
  myDFPlayer.volume(v);  //Set volume value. From 0 to 30
}

void loop() {

  //the robot is off, waiting for the user to turn it on
  while(working == 0) {
    if(robotIsWorking()==true)
      working = 1;
  }
  
  //the robot is on, and it will start "cleaning"
  Serial.println("Robot is working");
  execute();

}

//This function is responsible for the behaviour of the robot, once it is on.
//The robot will move for some time, then stop and say a joke, and repeat this until
//it is disconnected from the electricity.  
void execute() {
  powerMotorRandom();
  delay(3000);
  stopMotor();
  myDFPlayer.play(random(3,11));
  delay(12000);
  myDFPlayer.pause();
  delay(800);
}

//This function terminates and returns true when the user presses the button successfully.
//Since the robot is unconfortable, the user might have to press the button multiples 
//times before it actually works
bool robotIsWorking()
{
    bool isWorking = false;

    while (isWorking==false)
    {
        buttonState = digitalRead(buttonPin);
        if (buttonState == HIGH)
        {
            if (long(buttonState) == generateRandomValue()) 
            {
                Serial.print("robot working here");
                isWorking = true;
            } else {
              myDFPlayer.play(random(1,4));
              delay(5500);
              myDFPlayer.pause();
            }
            delay(200);
        }
    }

    return true;
}

//This function generates an integer random value from 0 to 2
long generateRandomValue()
{
    return random(0,3);
}

//This function makes the robot move. There are four possible moving positions, 
//which are chosen randomly every time the function is executed. 
void powerMotorRandom() {
  int num = random(0,4);
  if(num == 0)
    powerMotorForward();
  
  if(num == 1)
    powerMotorBackward();

  if(num == 2)
    powerMotorRight();

  if(num == 3)
    powerMotorLeft();
}

//This function makes the robot move forward.
void powerMotorForward()
{
    myservo2.write(0);
    myservo1.write(180);
}

//This function makes the robot move backward.
void powerMotorBackward()
{
    myservo2.write(180);
    myservo1.write(0);
}

//This function makes the robot move toward right.
void powerMotorRight()
{
    myservo2.write(90);
    myservo1.write(180);
}

//This function makes the robot move toward left.
void powerMotorLeft()
{
    myservo2.write(0);
    myservo1.write(90);
}

//This function makes the motors of the robot stop. 
void stopMotor()
{
    myservo2.write(90);
    myservo1.write(90);
}