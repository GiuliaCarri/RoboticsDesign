#include "DFRobotDFPlayerMini.h"
#include "SoftwareSerial.h"

static const long RST=172800000; //2 gg
//volatile int volume = 12;
int volume =15;
char* joke;
bool speak = false;
DFRobotDFPlayerMini player; //pin to 5v
long t =0;
bool MOUTHSERIAL = false;
static const uint8_t TX=7;
static const uint8_t RX=8;
SoftwareSerial ss(RX, TX);

void setup() {
    // Init USB serial port for debugging
    Serial.begin(9600);
    ss.begin(9600);
    //microphoneSetup();
    mouthSetup();
    //jokesSetup();
    movementsSetup();
    volumeButtonsSetup();
}

void loop() {
   //reset after RST time
  if(millis()>= RST){
    rst();
  }
  
    mouthLoop();
    //microphoneLoop();
    //jokesLoop();
    movementsLoop();
    volumeButtonsLoop();
    //delay(1);
  }

void rst(){
  asm volatile (" jmp 0");
}
