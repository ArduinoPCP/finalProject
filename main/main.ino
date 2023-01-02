#include <Servo.h>

Servo myservo1;
Servo myservo2;

long randNumber;
const int buttonPin = 2;
int buttonState = 0;

void setup() {

  Serial.begin(9600);
  randomSeed(42);
  pinMode(buttonPin, INPUT); 
  myservo1.attach(9);
  myservo2.attach(10);

}

void loop() {
  if (robotIsWorking()==true)
  {
      Serial.println("Robot is working");
      powerMotor();
  }

//this function terminates and returns true when the user presses the button successfully
//since the robot is unconfortable, the user might have to press the button multiples 
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
            }
            delay(200);
        }
    }

    return true;
}

//this function generates a random value from 0 to 2
long generateRandomValue()
{
    return random(1,4)-1;
}

//this function makes the two motor move
void powerMotor()
{
    myservo2.write(270);
    myservo2.write(180);
    myservo2.write(90);
    myservo2.write(0);
    delay(20);
    myservo1.write(0);
    myservo1.write(90);
    myservo1.write(180);
    myservo1.write(270);
    delay(20);
}