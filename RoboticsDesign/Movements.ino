#include <Servo.h> 

int neckSidePin = 9, neckUpPin = 6, armPin = 11;
Servo joints[3];
const int  neckSide = 2, neckUp = 1, arm = 0;

int armZero = 90;
int helloMax = 180;
int helloMin = 140;
int hello[] = {11, 8, 7, 7, 7, 7, 7, 7, 7, 7, 12, 28, 60, 98, 117, 119, 89, 59, 86, 104, 70, 63, 104, 112, 104, 71, 40, 18, 4, 0};
int yes[] = {106, 120, 145, 160, 151, 131, 125, 138, 145, 143, 132, 123, 132, 143, 145, 139, 133, 124, 117, 107, 95, 85, 75, 66, 63, 79, 90, 89, 85, 105, 103, 87, 79, 76, 70, 60, 44, 34, 28, 17, 12, 11};
int arraySize(int* arr[]){ //doesn't work
  return (int)(sizeof(arr) / sizeof(arr[0]));
}
int arraySizes[] = {(sizeof(hello) / sizeof(hello[0])),(sizeof(yes) / sizeof(yes[0]))}; //sizes of arrays
int* movements[] = {hello,yes}; //arrays pointers
int choice = 0;

unsigned long movementStartTime = 0;
unsigned long prevMovementTime = 0;

bool prevMOVE = false;

float prevValue = 0;

void movementsSetup(){
  
  joints[neckSide].attach(neckSidePin); 
  joints[neckUp].attach(neckUpPin);
  joints[arm].attach(armPin); 
  
  joints[arm].write(90); 
  joints[neckUp].write(movements[choice][0]); 
  joints[neckSide].write(90); 
  Serial.println("begin");
}

int angles[3] = {90,90,90};
float floatAngles[3] = {0,0,0};
float prevTime = 0;
float prevTime10 = 0;
int repeat = 0;
bool playing = false;
int arraysize = arraySizes[choice];
bool recording = false;

int* ptr = 0;

float currAngle = movements[choice][0];
void movementsLoop(){
  float currTime = millis();
  if(Serial.available()){
    int input = Serial.read()-48;
    Serial.println(input);
    if(input < 9){
      playing = true;
      recording = false;
      choice = input;
      currAngle = movements[choice][0];
    }
    Serial.read();
    Serial.read();
  }
  if(playing){
    if(!ptr)
      ptr = movements[choice];
    if(repeat < arraySizes[choice] - 1){
      if((currTime - prevTime10 >= 10)&&playing){
        currAngle += float(*(ptr+1)-*ptr)/10;
        Serial.println(currAngle); 
        joints[neckUp].write(int(currAngle));
        if((currTime - prevTime >= 100)){
          repeat++;
          ptr++;
          prevTime = currTime;
        }
        prevTime10 = currTime;
      }
    }
    else{
      ptr = 0;
      currAngle = movements[choice][0];
      playing = false;
      repeat = 0;
    }
  }
}
