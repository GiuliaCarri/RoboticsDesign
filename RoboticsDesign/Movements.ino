

Servo joints[3];
const int  neckSide = 2, neckUp = 1, arm = 0;

int armZero = 180;
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
  
  joints[arm].write(armZero); 
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
int arraysize = arraySizes[choice];
bool recording = false;

int* ptr = 0;

float currAngle[] = {movements[choice][0],movements[choice][0],movements[choice][0],movements[choice][0]};
void movementsLoop(){
  float currTime = millis();
  if(MOVEMENTSSERIAL){
  if(Serial.available()){
    int input = Serial.read()-48;
    Serial.println(input);
    if(input < 9){
      MOVEPLAYING = true;
      recording = false;
      choice = input;
      currAngle[0] = movements[choice][0];
      currAngle[1] = movements[choice][0];
      currAngle[2] = movements[choice][0];
    }
    Serial.read();
    Serial.read();
  }
  }
  if(SPECIFICMOVE > -1){
    choice = SPECIFICMOVE;
    resetMovements();
    MOVEPLAYING = true;
    currAngle[0] = *movements[choice*4];
    currAngle[1] = *movements[choice*4+1];
    currAngle[2] = *movements[choice*4+2];
    currAngle[3] = *movements[choice*4+3];
    Serial.print(currAngle[0]);
    Serial.print(", ");
    Serial.print(currAngle[1]);
    Serial.print(", ");
    Serial.println(currAngle[2]);
    SPECIFICMOVE = -1;
    prevTimeDelay = millis();
  }
  if(MOVEPLAYING){
    //Serial.println(currTime - prevTimeDelay);
    if(currTime - prevTimeDelay > MOVEDELAY){ //wait to start movement
      if(!ptr){
        prevTime10 = currTime;
        ptr = movements[choice*4];
      }
      if(repeat < arraySizes[choice] - 1){
        float deltaTimeMov = (float)(currTime - prevTime10);
        if((deltaTimeMov >= 10)&&MOVEPLAYING){
          for(int i=0; i<4; i++){
          currAngle[i] += float(*(movements[choice*4+i]+repeat+1)-*(movements[choice*4+i]+repeat))/10 * (float)(deltaTimeMov/10);
          if(i==3){
            if(!MOUTH_BUSY){
              mouth.write(180-int(currAngle[i]));
            }
          }
          joints[i].write(180-int(currAngle[i]));
          if((currTime - prevTime >= 100)){
            repeat++;
            ptr++;
            prevTime = currTime;
          }
          prevTime10 = currTime;
        }
          if(MOVEMONITOR){
          Serial.print(choice*4);
          Serial.print(", "); 
          Serial.print(*(movements[choice*4]+repeat)); 
          Serial.print(", "); 
          Serial.print(*(movements[choice*4 +1]+repeat)); 
          Serial.print(", "); 
          Serial.println(*(movements[choice*4 +2]+repeat)); 
          Serial.print(", "); 
          Serial.println(*(movements[choice*4 +3]+repeat)); 
          }
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
    currAngle[0] = *movements[choice*4];
    currAngle[1] = *movements[choice*4+1];
    currAngle[2] = *movements[choice*4+2];
    currAngle[3] = *movements[choice*4+3];
    MOVEPLAYING = false;
    repeat = 0;
}
