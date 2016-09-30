/*
* TPM2013_nanoSound.ino: Example of use of the library TPM2013_nanoSound
* 
* 
* Author: Raul Eusebio
*/
#include "TPM2013_nanoSound.h"



int x = 1;
char incomingByte2 = 0;
int incomingByte = 0;  

TPM2013_nanoSound TPM2013(Serial1); // Initialization of library sound

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  
  char w[4] = {'T','0','0','2'};
  delay(1000);


  // If user enter a "d" next play sound
  if(incomingByte2 == 'd')
    TPM2013.next_playback();
  

  // If user enter a "a" previous play sound
  if(incomingByte2 == 'a')
    TPM2013.previous_playback();


  // If user enter a "s" pause the music
  if(incomingByte2 == 's')
    TPM2013.stop_playback();


  // Play a sound file with the name declared in "w" variable
  if(x==1){
    TPM2013.play_music(w);
    Serial.println("play");
    x++;
  }

  incomingByte2 = 0;  // reset the variable

  // This code receive data from the terminal user 
  // commands to control de module
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte2 = Serial.read();
    // say what you got:
    Serial.print("I received: ");
    Serial.println(incomingByte2, DEC);
  }

  
  // This part is for the reply of the audio module
  if (Serial1.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial1.read();
    // say what you got:
    Serial.print("AudioTPM: ");
    Serial.println(incomingByte, DEC);
  }

}

  
