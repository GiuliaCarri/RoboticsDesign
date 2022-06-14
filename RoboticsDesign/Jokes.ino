//DFRobotDFPlayerMini player from mouth
//TODO declare dictionary that maps joke name to number
//1-15 italian jokes reading BREAK ICE
//16-30 english jokes reading BREAK ICE
//31-38 verses reading NOISE

//PLAY JOKES AND IN CASE THE ASSOCIATED MOVEMENTS (SET SPECIFIC MOVEMENTS WITH DELAY)

void jokesSetup(){
  strcpy(joke, "Hello");
}

void jokesLoop(){
  if(speak){
    speak = false;
    if(strcmp(joke,"")){
      player.playMp3Folder(4); //play specific mp3 in SD:/MP3/0004.mp3; File Name(0~65535)
      strcpy(joke, "");
    }
  }
}

int getJoke(char* joke){
  //translate joke name into int ID
  return 1;
}
