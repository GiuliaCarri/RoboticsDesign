#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h> 

// MP3 and motors/
int mouthPin = 5;
Servo mouth;
//DFRobotDFPlayerMini player; //pin to 3.3v
int mouthTime_reset = 10; //cooldown for closing mouth
int speakerPin = A1;
int maxMouthAngle = 30;
int mouthZero = 87;

//int volume = 15;
//String joke = "";

//Move and talk///////////////////////////
int mouthTime = 0;
int maxLoudness = 0;
int servoAngle = 0;
int targetAngle = 0;
int threshold = 200;
int powerIncrease = 2.2;
int correctedThreshold = 0;
bool closing = false;
unsigned long prevTimeMouth = 0;
bool speaking = false;

int mouthCooldown = 100;
int MOUTHCOOLDOWN = 60;
bool openMouth = false;
int busyMouth = false;

void mouthSetup(){
  // Init serial port for DFPlayer Mini
  //softwareSerial.begin(9600);
  mouth.attach(mouthPin); 
  if(!player.begin(ss)){
    Serial.println("error player"); 
 }  

  // Start communication with DFPlayer Mini
  /*if (player.begin(softwareSerial)) {
   Serial.println("OK");
    // Set volume (0 to 30).
    // TODO Play "hello" MP3 file on the SD card
  } else {
    Serial.println("Connecting to DFPlayer Mini failed!");
  }*/
}

void mouthLoop(){
  unsigned long currTimeMouth = millis();
  int analogValue = analogRead(speakerPin);
  int loudness = abs((analogValue-512)*(analogValue-512));// 3.3V: -340, 5V: -512

  if(MOUTHSERIAL){
    if(Serial.available()){
      MOUTHCOOLDOWN = (Serial.read()-48) *10;
      Serial.read();
      Serial.read();
      player.play(1);
    }
  }
    if(true){
    Serial.print(loudness);
    Serial.print(",");
    Serial.print(busyMouth = !(int)(digitalRead(4)) * 300);
    Serial.print(",");
    Serial.println(correctedThreshold = threshold * pow(powerIncrease,(volume - 15) /3));
    if(loudness >= correctedThreshold)
      openMouth = true;
   if((openMouth)&&busyMouth){
    mouthCooldown = MOUTHCOOLDOWN;
    mouth.write(mouthZero-(int)(float)maxMouthAngle*((float)volume/30));
    openMouth = false;
   }
   
    if(currTimeMouth - prevTimeMouth >= 10){
      mouthCooldown-=10;
      prevTimeMouth = currTimeMouth;
    }
    
    if(mouthCooldown <= 0){
    mouth.write(mouthZero);
    }
    //Serial.print(",");
    
  }
}
