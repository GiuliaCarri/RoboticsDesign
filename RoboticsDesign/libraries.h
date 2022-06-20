//define pins
//analogic read
static const uint8_t MIC_PIN=A0;
static const uint8_t SPEAKER_PIN=A1;
//digital read/write
static const uint8_t BUT_DOWN_PIN=2;
static const uint8_t BUT_UP_PIN=3;
static const uint8_t BUSY_PIN=4;
static const uint8_t TX_PIN=7; // DF 8 tx
static const uint8_t RX_PIN=8; // DF 7 rx
static const uint8_t MOUTH_PIN=5; //giallo
static const uint8_t ARM_PIN=11; //bianco
static const uint8_t HEAD_YES_PIN=6; //blu
static const uint8_t HEAD_NO_PIN=9; //verde


#include "DFRobotDFPlayerMini.h"
#include <Servo.h> 
#include "movements.h"
#include "SoftwareSerial.h"
#include "mic.h"
