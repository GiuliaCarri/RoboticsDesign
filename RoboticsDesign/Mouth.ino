#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h> 

//FIXARE VIBRAZIONE BOCCA

// MP3 and motors/


int MOUTHCOOLDOWN = 60;
int maxMouthAngle = 30;
int mouthZero = 180;


//Move and talk///////////////////////////
int mouthTime = 0;
int maxLoudness = 0;
int servoAngle = 0;
int targetAngle = 0;
int threshold = 300;
int powerIncrease = 2.2;
int correctedThreshold = 0;
bool closing = false;
unsigned long prevTimeMouth = 0;
bool speaking = false;

int mouthCooldown = 100;
bool openMouth = false;
int busyMouth = 0;

void mouthSetup(){
  // Init serial port for DFPlayer Mini
  //softwareSerial.begin(9600);
  mouth.attach(MOUTH_PIN); 
  mouth.write(mouthZero);
  /*if(!player.begin(ss)){
    Serial.println("error player"); 
 } */ 

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
  int analogValue = analogRead(SPEAKER_PIN);
  int loudness = abs((analogValue-512)*(analogValue-512));// 3.3V: -340, 5V: -512

  if(MOUTHSERIAL){
    if(Serial.available()){
      MOUTHCOOLDOWN = (Serial.read()-48) *10;
      Serial.read();
      Serial.read();
      player.play(35);
    }
  }
    if(MOUTHMONITOR){
    Serial.print(loudness);
    Serial.print(",");
    Serial.print(MOUTH_BUSY * 300);
    Serial.print(",");
    Serial.println(correctedThreshold = threshold * pow(powerIncrease,(VOLUME - 15) /3));
   }
   MOUTH_BUSY = (bool)busyMouth;
   busyMouth = !(int)(digitalRead(BUSY_PIN)) * 300;
   if(MOUTH_BUSY && !busyMouth){ //setta zero solo quando finisce di parlare cosi movements può controllarla
      mouth.write(mouthZero);
      PHRASE_FINISHED = true;
   }
   correctedThreshold = threshold * pow(powerIncrease,(VOLUME - 15) /3);
    if(loudness >= correctedThreshold)
      openMouth = true;
   if(busyMouth){
   if((openMouth)){ //c'era già :p AGGIUNTO CONTROLLO BUSY PIN, VEDI SE SMETTE DI TREMARE. LOW=PLAYING
    mouthCooldown = MOUTHCOOLDOWN;
    mouth.write(mouthZero-(int)(float)maxMouthAngle*((float)VOLUME/30));
    MOUTH_STATE = true;
    openMouth = false;
   }
    if(currTimeMouth - prevTimeMouth >= 10){
      mouthCooldown-=10;
      prevTimeMouth = currTimeMouth;
    }
    
    if(mouthCooldown <= 0){
    mouth.write(mouthZero);
    MOUTH_STATE = false;
    }
    //Serial.print(",");
   }
}
