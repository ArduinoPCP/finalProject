# THE JANITOR 2.0

<img src="https://user-images.githubusercontent.com/79515036/220131430-e028ce11-9195-4459-84fb-575296fab114.png" height="400">

## Introduction

<i>The Janitor 2.0 is the ultimate cleaning robot that acts in every way as a school Janitor! He complains a lot when he needs to start working, tries to delay the job as much as he can, and when it finally starts, he stops every 5 seconds to tell unfunny jokes. Unpleasant and annoying, as we like!</i>

<p float="left">
  <img src="https://user-images.githubusercontent.com/79515036/220124691-99a68a2c-03af-4177-aaa6-930d0a94cea7.png" height="200">
  <img src="https://user-images.githubusercontent.com/79515036/220124706-a486f7f1-67cb-405d-9cff-e08f0622f873.png" height="200">
</p>

## Concept

- It behaves like a janitor! 
- It keeps complaining and it is not in the mood to start its job.
- When it starts cleaning, then it makes bad jokes.  

## Design

The 3D model was developed using the software Fusion 360 and then the slicing was done with Cura. 
The model has been printed at the [Bitz unibz fablab](https://bitzfablab.unibz.it/it/).

<p float="left">
  <img src="https://user-images.githubusercontent.com/79515036/220127297-8644ed0b-5cf8-4d46-aa90-807ff443bfe6.png" height="200">
  <img src="https://user-images.githubusercontent.com/79515036/220127325-14c4f2fe-58c4-4d24-aee3-a74d3c230dd2.png" height="200">
</p>

## Electronics design 

- The tool [Fritzing](https://fritzing.org/) was used for prototyping. 
- Instead of the button a potentiometer has been used. This made it easier to attach it to the lid and use long cables.
- There are two 360° Servomotors in order to implement the movements of the robot. 

<p float="left">
  <img src="https://user-images.githubusercontent.com/79515036/220128138-b983a4d7-6594-4068-af32-9e0d23b6f91c.png" height="400">
  <img src="https://user-images.githubusercontent.com/79515036/220128162-c31f53e2-5524-41ff-bc11-b1c104fbd086.png" height="400">
</p>

## The voice

- The jokes that the robot says have been found on different websites. 
- And with an AI on Internet, the voice was generated. 
- The DFPlayer Mini library allowed to play and control MP3 files. Those are taken from the SD card. 

<img src="https://user-images.githubusercontent.com/79515036/220130231-e96db8c2-a38f-4ad8-a4b0-906e3d8fcff0.png" height="400">

## The code

Have a look at the complete code [here](https://github.com/ArduinoPCP/finalProject/blob/main/main/main.ino)!

```c
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
```

This loop is where the robot is activated by the user. A person has to press the button on top of the robot. 
Sometimes this take multiples trials and the robot might even complain in the meanwhile. 

```c
void execute() {
  powerMotorRandom();
  delay(3000);
  stopMotor();
  myDFPlayer.play(random(3,11));
  delay(12000);
  myDFPlayer.pause();
  delay(800);
}
```

execute is the function responsible for what the robot does once it is on:
- the robot moves randomly for three seconds. There are four possible movements;
- it stops for twelve seconds to say a joke;
- and it repeat forever. 
