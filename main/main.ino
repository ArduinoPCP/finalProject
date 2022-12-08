#include <Servo.h>

Servo myservo;
long randNumber;
const int buttonPin = 2;
int buttonState = 0;

void setup() {

  Serial.begin(9600);
  randomSeed(42);
  pinMode(buttonPin, INPUT); 
  
}

void loop() {
  if (robotIsWorking()==true)
  {
      Serial.println("Robot is working");
  }
}

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

long generateRandomValue()
{
    return random(1,4)-1;
}

void setUpMotor()
{
    myservo.attach(9);  // Attach the servo to pin 9
}

void powerMotor()
{
    myservo.write(45); // The speed at which the motor rotates
}