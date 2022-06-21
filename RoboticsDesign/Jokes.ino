
//DFRobotDFPlayerMini player from mouth
//TODO declare dictionary that maps joke name to number
//1-15 italian jokes reading BREAK ICE
//16-30 english jokes reading BREAK ICE
//31-36 verses reading NOISE

//PLAY JOKES AND IN CASE THE ASSOCIATED MOVEMENTS (SET SPECIFIC MOVEMENTS WITH DELAY)

int joke; //where we put the index of the joke to play (=> also of the array of pointers to movements)
void jokesSetup(){
  randomSeed(analogRead(A3));
}

void jokesLoop(){

  //if noise detected, play verses and random movements
  if(NOISE){
    joke= randomize(verses_init, verses_init + verses_num -1);

    player.play(joke);
    //SPECIFICMOVE = joke;
    //MOVEDELAY = 0; //SPOSTARE NEL MAIN
    //fare movements

    
    NOISE=false;
  }

  //if silence, play jokes and specific movements
  if(BREAK_ICE){
    
    joke= randomize(lang*jokes_per_lang +1, lang*jokes_per_lang + jokes_per_lang);

    player.play(joke);
    SPECIFICMOVE = joke;
    //fare movements
    
    
    BREAK_ICE=false;
  }
  if(PHRASE_FINISHED){// && !MOVEPLAYING){
    MIC_STATE=true;
    PHRASE_FINISHED = false;
    SPECIFICMOVE = -1;
    t2=millis();
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
