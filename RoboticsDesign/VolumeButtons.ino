long buttonDebounce = 500; //debounce for pressure
unsigned long tPush=1500; //how long pressure to detect change

int volumeUpState =0;
int volumeDownState =0;

bool volumeUpPressed;
bool volup_prev;

bool volumeDownPressed;
bool voldown_prev;


void volumeButtonsSetup(){
  // put your setup code here, to run once:

  pinMode(BUT_UP_PIN, INPUT_PULLUP);
  pinMode(BUT_DOWN_PIN, INPUT_PULLUP);
  
}


void volumeButtonsLoop(){
  //Serial.print(volume);
  //Serial.print(",");
  
  volumeUpState = digitalRead(BUT_UP_PIN); //pin up= pin 3 pressed -> state 0
  volumeDownState = digitalRead(BUT_DOWN_PIN); //pin down =pin2 pressed -> state 0

  if (volumeUpState){
    volumeUpPressed = true;
  }
  if (volumeDownState){
    volumeDownPressed = true;
  }

  //raise volume
  if ((volumeUpPressed) and !(volumeUpState) and (millis()-t1)>buttonDebounce){
    volumeUpPressed = false;
    if (VOLUME < 30)
       VOLUME +=3;
    player.volume(VOLUME);
    player.play(verses_init + 3); //AH! verse is the 4th verse
    t1=millis();
    
  }
  
  //reduce volume
  if ((volumeDownPressed) and !(volumeDownState) and (millis()-t1)>buttonDebounce){
    volumeDownPressed = false;
    if(VOLUME > 0)
      VOLUME -=3;
    player.volume(VOLUME);
    player.play(verses_init + 3); //AH! verse is the 4th verse
    t1=millis();
 
  }

  //change language if UPBT long pressure
  if (!volup_prev && volumeUpPressed){
    //start counting
    t0= millis();  
  } 

  if (volup_prev && !volumeUpPressed){
    //end counting
    if((millis()-t0) > tPush){
      //change language
      if(lang<NUMLANG-1){
        lang++;
        lang_init += jokes_per_lang;
        player.play(lang_init);
          
      } else if(lang == NUMLANG -1){
          lang=0;
          lang_init =1;
          player.play(lang_init);
        }
        //t0=millis();
        t1=millis();
    }
  }

    //recalculate mic threshold if DOWNBT long pressed
    if (!voldown_prev && volumeDownPressed){
    //start counting
    t0= millis();  
    } 

    if (voldown_prev && !volumeDownPressed){
    //end counting
      if((millis()-t0) > tPush){
        //mic threshold
        mic.dyn_th();
        mic_th = mic.mic_th;
      
        //t0=millis();
        t1=millis();
    } 
    
    
  }

  volup_prev = volumeUpPressed;
  voldown_prev = volumeDownPressed;
}
