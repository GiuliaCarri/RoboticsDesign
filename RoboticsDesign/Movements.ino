

Servo joints[3];
const int  neckSide = 2, neckUp = 1, arm = 0;

int armZero = 0;
int yesZero = 150;
int noZero = 90;
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
  joints[neckUp].write(noZero); 
  joints[neckSide].write(yesZero); 
  Serial.println("begin");
}


float prevTime = 0;
float prevTimeDelay = 0;
float prevTime10 = 0;
int repeat = 0;
int arraysize = arraySizes[choice];
bool recording = false;

int* ptr = 0;

float currAngle[] = {armZero,noZero,yesZero,180};
void movementsLoop(){
  float currTime = millis();
  if(MOVEMENTSSERIAL){
  if(Serial.available()){
    int input = Serial.read()-48;
    Serial.println(input);
    if((input < 9)&&(input>-1)){
      MOVEPLAYING = true;
      recording = false;
      choice = input;
      currAngle[0] = *movements[choice*4];
    currAngle[1] = *movements[choice*4+1];
    currAngle[2] = *movements[choice*4+2];
    currAngle[3] = *movements[choice*4+3];
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
    //Serial.print(currAngle[0]);
    //Serial.print(", ");
    //Serial.print(currAngle[1]);
    //Serial.print(", ");
    //Serial.println(currAngle[2]);
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
            if(*(movements[choice*4+i])>-1){
              currAngle[i] += float(*(movements[choice*4+i]+repeat+1)-*(movements[choice*4+i]+repeat))/10 * (float)(deltaTimeMov/10);
              if(i==3){
                if(!MOUTH_BUSY){
                  mouth.write(int(currAngle[i]));
                }
              }
              else{
                joints[i].write(int(currAngle[i]));
                if(MOVEMONITOR){
                  Serial.print(i);
                  Serial.print(": ");
                  Serial.print(currAngle[i]);
                  //Serial.print(*(movements[choice*4+i]+repeat)-90); 
                  Serial.print("/"); 
                  Serial.print(*(movements[choice*4+i]+repeat));
                  Serial.print("    ");
                }
              }
            }
          if((currTime - prevTime >= 100)){
            repeat++;
            for(int i=0; i<4; i++){
              currAngle[i] = *(movements[choice*4+i]+repeat);
            }
            ptr++;
            prevTime = currTime;
          }
          prevTime10 = currTime;
        }
          if(MOVEMONITOR){
          Serial.println(deltaTimeMov); 
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
    currAngle[0] = armZero;
    currAngle[1] = noZero;
    currAngle[2] = yesZero;
    currAngle[3] = 180;
    joints[0].write(int(currAngle[0]));
    joints[1].write(int(currAngle[1]));
    joints[2].write(int(currAngle[2]));
    mouth.write(int(currAngle[3]));
    MOVEPLAYING = false;
    repeat = 0;
}
