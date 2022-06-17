#ifndef MIC_H
#define MIC_H

//global variables
//#define PIN 0
#define TH_SAMPLES 100
#define VOL_SAMPLES 1
long tt=0;

class Mic{

  public:

  int status;
  int pin;
  long vol;
  long mic_th;
  long sread;

  public:

  Mic();
  void SetPin();
  long ReadVol();
  long sVol();
  void dyn_th();
  
  
  
  };

Mic::Mic(){
  status = LOW;
  SetPin();
  }

void Mic::SetPin(){
  pin = MIC_PIN;
  pinMode(pin, INPUT);
  
  }

long Mic::ReadVol(){
  
  return pow((analogRead (pin)-360),2);
  
  }

long Mic::sVol(){

  vol=0;
  for(int i=0; i<VOL_SAMPLES; i++){
    vol += ReadVol();
    //delay(5);
    tt=millis();
    while(millis()-tt<10){};
    tt=millis();
   }
   vol = vol/VOL_SAMPLES;
   //vol = abs(vol);
   vol = pow(vol, 2);
   //vol = (int)vol;
   //delay(500);
   return vol; 
}


void Mic::dyn_th(){

/*OLD
  for(int i=0; i<TH_SAMPLES; i++){
    mic_th += ReadVol();
    //delay(5);
    tt=millis();
    while(millis()-tt<10){};
    tt=millis();
   }
   mic_th = mic_th/TH_SAMPLES;
   
   //mic_th = pow(mic_th, 2);
   mic_th = (long)(((float)mic_th * 1.0f)); //aumento th del 20% 
   mic_th = abs(mic_th); 
   //mic_th = pow(mic_th, 2);
   */
   for(int i=0; i<TH_SAMPLES; i++){
    //sread += ReadVol();
    sread= analogRead(pin);
    if(sread<50000){
    mic_th += abs(sread);
    } else mic_th +=50000;
    
    //delay(5);
    /*
    tt=millis();
    while(millis()-tt<10){};
    tt=millis();*/
   }
   mic_th = mic_th/TH_SAMPLES;
   
   //mic_th = pow(mic_th, 2);
   mic_th = (long)(((float)mic_th * 2.0f)); //supposing uniform distribution of noise, *2 should be ok... 
   mic_th = abs(mic_th); 
   //mic_th = pow(mic_th, 2);
}


#endif
