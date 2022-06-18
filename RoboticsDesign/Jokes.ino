
//DFRobotDFPlayerMini player from mouth
//TODO declare dictionary that maps joke name to number
//1-15 italian jokes reading BREAK ICE
//16-30 english jokes reading BREAK ICE
//31-38 verses reading NOISE

//PLAY JOKES AND IN CASE THE ASSOCIATED MOVEMENTS (SET SPECIFIC MOVEMENTS WITH DELAY)

int joke; //where we put the index of the joke to play (=> also of the array of pointers to movements)
void jokesSetup(){
  
}

void jokesLoop(){

  //if noise detected, play verses and random movements
  if(NOISE){
    joke= randomize(lang*jokes_per_lang +1, lang*jokes_per_lang + jokes_per_lang);

    player.play(joke);
    SPECIFICMOVE = joke;
    MOVEDELAY = 4000; //SPOSTARE NEL MAIN
    //fare movements

    t2=millis();
    NOISE=false;
    //MIC_STATE=true;
  }

  //if silence, play jokes and specific movements
  if(BREAK_ICE){
    joke= randomize(verses_init, verses_init + verses_num -1);

    player.play(joke);
    //fare movements
    
    t2=millis();
    BREAK_ICE=false;
    //MIC_STATE=true;
  }
  if(!MOUTH_BUSY && !MOVEPLAYING){
    MIC_STATE=true;
  }
  if(PHRASE_FINISHED){
    SPECIFICMOVE = -1;//KERMIT TURN, MOUTH OPEN TO START LAUGHING ECC
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
