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

//this function sets up the motor
void setUpMotor()
{
    myservo.attach(9);  // Attach the servo to pin 9
}

//this function makes the motor move
void powerMotor()
{
    myservo.write(45); // The speed at which the motor rotates
}