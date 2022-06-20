long buttonDebounce = 100; //debounce for pressure
unsigned long tPush=1000; //how long pressure to detect change


int volumeUpState =0;
int volumeDownState =0;

int countUp=0;
int countDown=0;

const int ON =0;
const int OFF=1;

void volumeButtonsSetup(){
  // put your setup code here, to run once:

  pinMode(BUT_UP_PIN, INPUT_PULLUP);
  pinMode(BUT_DOWN_PIN, INPUT_PULLUP);
  t1=millis();
  t0=millis();
  int countUp=OFF;
  int countDown=OFF;
  
}

void volumeButtonsLoop(){
  //Serial.print(volume);
  //Serial.print(",");
  
  volumeUpState = digitalRead(BUT_UP_PIN); //pin up= pin 3 pressed -> state 0
  volumeDownState = digitalRead(BUT_DOWN_PIN); //pin down =pin2 pressed -> state 0

  if(millis()-t1> buttonDebounce){
    //if debounce ok, I can do actions

    //BUTTON UP
    if(volumeUpState== ON && countUp ==OFF){
      //start counting
      countUp=ON;
      t0=millis();
    }

    if(volumeUpState==OFF && countUp ==ON){
      //count finish, make action
      countUp=OFF;
      // if long press--> change language, otherwise rise volume
      if(millis()-t0>tPush){
         //change language
         Serial.println("long");
         if(lang<NUMLANG-1){
          lang++;
          lang_init += jokes_per_lang;
          player.play(lang_init);
          
         } else if(lang == NUMLANG -1){
          lang=0;
          lang_init =1;
          player.play(lang_init);
        }
      } else{
          if (VOLUME < 30){
            VOLUME +=3;
            Serial.println(VOLUME);
          }
          player.volume(VOLUME);
          player.play(verses_init + 3); //AH! verse is the 4th verse
        }  
    
    }

    //BUTTON DOWN
    if(volumeDownState== ON && countDown ==OFF){
      //start counting
      countDown=ON;
    }

    if(volumeDownState==OFF && countDown ==ON){
      //count finish, make action
      countDown=OFF;
      if(VOLUME > 6){
        VOLUME -=3;
        Serial.println(VOLUME);
      }
      player.volume(VOLUME);
      player.play(verses_init + 3); //AH! verse is the 4th verse  
    }

  
    t1=millis();
  }
  
}

/*
bool volumeUpPressed;
bool volup_prev;

bool volumeDownPressed;
bool voldown_prev;


void volumeButtonsSetup(){
  // put your setup code here, to run once:

  pinMode(BUT_UP_PIN, INPUT_PULLUP);
  pinMode(BUT_DOWN_PIN, INPUT_PULLUP);
  t1=millis();
  t0=millis();
  
}


void volumeButtonsLoop(){
  //Serial.print(volume);
  //Serial.print(",");
  
  volumeUpState = digitalRead(BUT_UP_PIN); //pin up= pin 3 pressed -> state 0
  volumeDownState = digitalRead(BUT_DOWN_PIN); //pin down =pin2 pressed -> state 0

  if (volumeUpState==0){
    volumeUpPressed = true;
  }
  if (volumeDownState==0){
    volumeDownPressed = true;
  }

  if((volumeUpPressed) and (millis()-t1)>buttonDebounce){

    if (!volup_prev && volumeUpPressed){
      //start counting
      t0=millis();
      
    }

    if (volup_prev && !volumeUpPressed && millis()-t0>tPush){
    //end counting
    
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
        volumeUpPressed = false;
   
  } else if (volup_prev && !volumeUpPressed && millis()-t0<tPush){
    volumeUpPressed = false;
    if (VOLUME < 30)
       VOLUME +=3;
    player.volume(VOLUME);
    player.play(verses_init + 3); //AH! verse is the 4th verse
    t1=millis();
    }
    t1=millis();
    
    
  }
  /*
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
  /*
  //change language if UPBT long pressure
  if (!volup_prev && volumeUpPressed and !(volumeUpState)){
    //start counting
    t0= millis(); 
  } 

  if (volup_prev && !volumeUpPressed && (volumeUpState)){
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
}*/
