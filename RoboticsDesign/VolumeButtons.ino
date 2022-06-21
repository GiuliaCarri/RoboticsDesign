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
          Serial.println(lang_init);
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
      t0=millis();
    }

    if(volumeDownState==OFF && countDown ==ON){
      //count finish, make action
      countDown=OFF;
      // if long press--> change language, otherwise lower volume
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
          if (VOLUME >9){
            VOLUME -=3;
            Serial.println(VOLUME);
          }
          player.volume(VOLUME);
          player.play(verses_init + 3); //AH! verse is the 4th verse
        }  
    }

  
    t1=millis();
  }
  
}
