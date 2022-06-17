

Servo joints[3];
const int  neckSide = 2, neckUp = 1, arm = 0;

int armZero = 90;
int helloMax = 180;
int helloMin = 140;

int choice = 0;

unsigned long movementStartTime = 0;
unsigned long prevMovementTime = 0;

bool prevMOVE = false;

float prevValue = 0;

void movementsSetup(){
  
  joints[neckSide].attach(HEAD_NO_PIN); 
  joints[neckUp].attach(HEAD_YES_PIN);
  joints[arm].attach(ARM_PIN); 
  
  joints[arm].write(90); 
  joints[neckUp].write(movements[choice][0]); 
  joints[neckSide].write(90); 
  Serial.println("begin");
}

int angles[3] = {90,90,90};
float floatAngles[3] = {0,0,0};
float prevTime = 0;
float prevTimeDelay = 0;
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
  if(SPECIFICMOVE){
    choice = SPECIFICMOVE;
    prevTimeDelay = millis();
    resetMovements();
  }
  if(playing){
    if(currTime - prevTimeDelay > MOVEDELAY){ //wait to start movement
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
        resetMovements();
      }
    }
  }
}

void resetMovements(){
    ptr = 0;
    currAngle = movements[choice][0];
    playing = false;
    repeat = 0;
}
