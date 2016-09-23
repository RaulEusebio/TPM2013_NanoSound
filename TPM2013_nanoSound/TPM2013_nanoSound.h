/*
 * TPM2013_nanoSound.h: Library for the TPM2013 nano sound module
 * 
 * The module work with protocol serial. 
 * The library is configurable for work with any Serial port 
 * only need add it in the initialization with the constructor method
 * 
 * Author: Raul Eusebio
 * Date: September 22nd, 2016
 */
#include "Arduino.h"
#ifndef TPM2013_nanoSound_h
#define TPM2013_nanoSound_h

class TPM2013_nanoSound
{
 public:
  TPM2013_nanoSound(HardwareSerial &);
  int play_music(char []);
  int stop_playback(void);
  int next_playback(void);
  int previous_playback(void);
  int volume_control(int volume);

 private:
  HardwareSerial* printer;
  int lenght;
  int command_code;
  int file_name;
  int check_code;
  
};

#endif
