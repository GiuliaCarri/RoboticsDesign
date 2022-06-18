//CALLS FOR JOKES (break ice when people are silent), OR VERSES/MOVEMENTS (people speaking)



int S =0;
int DELTA=25;

int TTH= 700;

//mic



long mvol=0;

long mm=0;

int speech=0;

void microphoneSetup() {
  
  MIC_STATE=true;
  t2=millis();

}

void microphoneLoop() {

  // put your main code here, to run repeatedly:
  if(MICSERIAL){
    if(Serial.available()){
      int micvalue = (Serial.read()-48);
      Serial.read();
      Serial.read();
      Serial.println(micvalue);
      if(micvalue == 1){
        NOISE = true;
      }
      if(micvalue == 2){
        BREAK_ICE = true;
      }
    }
  }
  else{
 if(MIC_STATE==true){

  
  Serial.println("ecco");
  //Serial.print(mic_th);
  //Serial.print(",");
  Serial.print(mic_th);
  Serial.print(",");
  //Serial.print(pow(mic_th+DELTA,2));
  //Serial.print(",");
  //Serial.print(pow(mic_th-DELTA,2));
  //Serial.print(",");
  
  
  mm= abs(mic.ReadVol());
  if (mm < 50000){
    mm=50000;
  } 
  /*
  uint32_t mm = mic.ReadVol();
  if (mm<10000 && mm >-10000){Serial.println (abs(mm));}
  mvol = mic.sVol();*/
  //Serial.println (abs(mvol));
  if ((mm>mic_th)){
    speech++;
    }
  //Serial.println (mvol);
if((speech>=SPR) && ((millis()-t2)> random_threshold)){//speaking detected
  t2=millis();
  NOISE=true;
  BREAK_ICE=false;
  MIC_STATE=false;
  speech=0;
 }
 
if((speech<SPR) && ((millis()-t2)> silence_threshold)){//silence detected
  t2=millis();
  BREAK_ICE=true;
  NOISE=false;
  MIC_STATE=false;
  speech=0;
  }

  mic.dyn_th();
  mic_th = mic.mic_th;
 }
  }
}
