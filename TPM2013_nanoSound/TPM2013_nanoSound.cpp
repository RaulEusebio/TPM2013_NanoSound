/*
 * TPM2013_nanoSound.cpp: Library for the TPM2013 nano sound module
 * 
 * The module work with protocol serial. 
 * The library is configurable for work with any Serial port 
 * only need add it in the initialization with the constructor method
 * 
 * Author: Raul Eusebio
 * Date: September 22nd, 2016
 */
#include "Arduino.h"
#include "TPM2013_nanoSound.h"
#define STOP 0xAB
#define NEXT 0xAC
#define PREVIOUS 0xAD
#define VOLUME 0xAE
#define START_CODE 0x7E
#define END_CODE 0xEF


// Constructor method
// receive the address of the serial port
TPM2013_nanoSound::TPM2013_nanoSound(HardwareSerial &print)
{
  printer = &print; //operate on the address of print
  printer -> begin(9600); // Begin de port at 9600 bauds
}


// Play a file .MP3
// Receive an array with the name of the file of 4 characters
int TPM2013_nanoSound::play_music(char file_name[4])
{
  lenght=0x07; // Number of the bytes in command
  command_code = 0xA3; // Command to play a file
  char c1 = file_name[0];
  char c2 = file_name[1];
  char c3 = file_name[2];
  char c4 = file_name[3];

  // Sum of several commands
  check_code = lenght + command_code + c1 + c2 + c3 + c4; 
  check_code = check_code & 0x0FF; // Delete of the 4 more significant bits
  
  // Send commands 
  printer->write(START_CODE);
  printer->write(lenght);
  printer->write(command_code);
  printer->write(c1);
  printer->write(c2);
  printer->write(c3);
  printer->write(c4);
  printer->write(check_code);
  printer->write(END_CODE);

  return 0;
}


// Stop the playback
int TPM2013_nanoSound::stop_playback(void)
{
  lenght=0x03;
  command_code = STOP;
  check_code = 0xAE;

  // Send commands 
  printer->write(START_CODE);
  printer->write(lenght);
  printer->write(command_code);
  printer->write(check_code);
  printer->write(END_CODE);
  return 0;
}


// Next playback
int TPM2013_nanoSound::next_playback(void){
  lenght=0x03;
  command_code = NEXT;
  check_code = 0xAF;

  // Send commands 
  printer->write(START_CODE);
  printer->write(lenght);
  printer->write(command_code);
  printer->write(check_code);
  printer->write(END_CODE);  
}


// Previous playback
int TPM2013_nanoSound::previous_playback(void)
{
  lenght=0x03;
  command_code = PREVIOUS;
  check_code = 0xB0;

  // Send commands 
  printer->write(START_CODE);
  printer->write(lenght);
  printer->write(command_code);
  printer->write(check_code);
  printer->write(END_CODE);
  return 0;
}


// Volume control from 00 - 1F
// 00 is mute, 31 is maximum.
int TPM2013_nanoSound::volume_control(int volume)
{
  lenght=0x04;
  command_code = VOLUME;
  check_code = lenght + command_code + volume;

  // Send commands 
  printer->write(START_CODE);
  printer->write(lenght);
  printer->write(command_code);
  printer->write(volume);
  printer->write(check_code);
  printer->write(END_CODE);
  return 0;
}
