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
  TPM2013_nanoSound(HardwareSerial &);  // Constructor. Receive a Serial port
  int play_music(char [4]); // Receive a name file with 4 characters
  int stop_playback(void);  // Stop the current file
  int next_playback(void);  // Next file 
  int previous_playback(void); // Previous file
  int volume_control(int volume); // Volume control from 00-1F

 private:
  HardwareSerial* printer;
  int lenght;
  int command_code;
  int file_name;
  int check_code;
  
};

#endif
