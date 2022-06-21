
//DFRobotDFPlayerMini player from mouth
//TODO declare dictionary that maps joke name to number
//1-15 italian jokes reading BREAK ICE
//16-30 english jokes reading BREAK ICE
//31-36 verses reading NOISE

//PLAY JOKES AND IN CASE THE ASSOCIATED MOVEMENTS (SET SPECIFIC MOVEMENTS WITH DELAY)

int joke; //where we put the index of the joke to play (=> also of the array of pointers to movements)
int jokes_i;
int moves;
void jokesSetup(){
  randomSeed(analogRead(A3));
}

void jokesLoop(){

  //if noise detected, play verses and random movements
  if(NOISE){
    joke= randomize(verses_init, verses_init + verses_num -1);
    jokes_i=randomize(0, 20);
    moves= randomize(0, 3);
    if (jokes_i<8){
      player.play(joke);
      //MOVEDELAY = 0;
    }
    if (jokes_i>=8){
      SPECIFICMOVE = moves;
    //MOVEDELAY = 0;
    }

    
    NOISE=false;
  }

  //if silence, play jokes and specific movements
  if(BREAK_ICE){
    
    joke= randomize(lang*jokes_per_lang +1, lang*jokes_per_lang + jokes_per_lang);

    player.play(joke);
    //SPECIFICMOVE = joke;
    
    
    BREAK_ICE=false;
    if(PHRASE_FINISHED){// && !MOVEPLAYING){
    Serial.print("FRASE FINITA\nFRASE FINITA\nFRASE FINITA\nFRASE FINITA\nFRASE FINITA");
      MIC_STATE=true;
      PHRASE_FINISHED = false;
      SPECIFICMOVE = randomize(3,4); //TODO NON SEMPRE
      t2=millis();
    }
    if(PHRASE_FINISHED){// && !MOVEPLAYING){
      MIC_STATE=true;
    }
  }
}

int getJoke(char* joke){
  //translate joke name into int ID (?)
  return 1;
}

int randomize(int from, int to){
  
  int rnd= random(from, to);
  return rnd;
}
