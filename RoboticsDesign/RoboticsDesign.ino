/*OLD
#include "DFRobotDFPlayerMini.h"
#include "movements.h"*/
#include "libraries.h"

//general utils
static const long RST=172800000; //2 gg for reset
DFRobotDFPlayerMini player; //pin to 5v
SoftwareSerial ss(RX_PIN, TX_PIN);
Mic mic = Mic();

//Times

unsigned long t0; //time to count push time
unsigned long t1 =0; //time for button debounce
unsigned long t2 = 0; //time for mic count seconds

//Microphone
bool MIC_STATE= false; //mic hears if true
bool MICSERIAL = true;
bool NOISE=false; //if noise detected verses
bool BREAK_ICE= false; //jokes random if SILENCE
int SPR=10; //Detected peaks threshold for speaking recognition
long silence_threshold = 6000; //if silence for 6 sec -> BREAK_ICE
long random_threshold = 8000; //if talking after 8 sec -> NOISE
long mic_th=0; //contains mic threshold

//Jokes
//int SPECIFIC_MOVEMENT; //movement to do according to a verse. Possibility of delay
int MOVEDELAY = 0; //SPOSTARE NEL MAIN
int SPECIFICMOVE = -1; //SPOSTARE NEL MAIN

//Mouth
bool MOUTH_STATE=false;
bool MOUTHSERIAL = false;
bool MOUTHMONITOR = false;
bool MOUTH_BUSY = false;
Servo mouth;
bool PHRASE_FINISHED = false;

//Buttons
int VOLUME =3;

int lang=0; //language audio dfplayer
int NUMLANG=2; //#languages until now
int lang_init=1;
int jokes_per_lang=15;
int verses_num=7;
int verses_init = NUMLANG*jokes_per_lang +1;

//Movements
bool MOVEMENT_STATE=false;
bool MOVEMENTSSERIAL = false;
bool MOVEPLAYING = false;
bool MOVEMONITOR = true;

bool PRINTROBOT = false;

void setup() {
    // Init USB serial port for debugging
    Serial.begin(9600);
    ss.begin(9600);
    if(!player.begin(ss)){
      Serial.println("error player"); 
    }
    else
      Serial.println("Player ok"); 

    player.volume(VOLUME);
    player.play(lang_init); // say hello in the specific language. This will give us the initial output sound and allow to understand the language and the volume.
    
    microphoneSetup();
    mouthSetup();
    jokesSetup();
    movementsSetup();
    volumeButtonsSetup();
}

void loop() {
   //reset after RST time
  if(millis()>= RST){
    rst();
  }
  if(PRINTROBOT){
    Serial.print("MIC_STATE ");
    Serial.print(MIC_STATE);
    Serial.print("|");
    Serial.print("NOISE ");
    Serial.print(NOISE);
    Serial.print("|");
    Serial.print("BREAK_ICE ");
    Serial.print(BREAK_ICE);
    Serial.print("|");
    Serial.print("VOLUME ");
    Serial.print(VOLUME);
    Serial.print("|");
    Serial.print("MOUTH_STATE ");
    Serial.print(MOUTH_STATE);
    Serial.print("|");
    Serial.print("SPECIFICMOVE ");
    Serial.print(SPECIFICMOVE);
    Serial.print("|");
    Serial.println("|");
  }
    mouthLoop();
    microphoneLoop();
    jokesLoop();
    movementsLoop();
    volumeButtonsLoop();
    
  }

void rst(){
  asm volatile (" jmp 0");
}

//in mic fai funz mic listen: mic stato dipende da mouth stato e movment stato
