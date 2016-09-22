/*
*    Library for the nano sound module TPM2013
*    
*    Form of the command string:     
*                                   |+++++++++PARAMETER++++++++|
*    |START CODE|LENGTH|COMMAND CODE|FILE HIGH BIT|FILE LOW BIT|CHECK CODE|END CODE|
*    LENGTH = COMMAND CODE(a Byte) + PARAMETER(Bytes) + CHECK CODE(a Byte)
*    CHECH CODE = LENGTH + COMMAND CODE + PARAMETER
*    
*    Basic commands
*    Specify root directory (A0):     7E 05 A0 00 01 A6 EF
*    Specify file name playback (A3): 7E 07 A3 
*    Stop playback( AB):              7E 03 AB AE EF
*    Next file playback (AC):         7E 03 AC AF EF
*    Previous file playback( AD):     7E 03 AD B0 EF
*    Volume control 00-1F (AE):       7E 04 AE 1F D1 EF 
*    

*/

#define STOP 0xAB
#define NEXT 0xAC
#define PREVIOUS 0xAD
#define VOLUME 0xAE

int start_code = 0x7E;
int lenght = 0x00;
int command_code = 0x00;
int file_name = 0x00;
int check_code = 0x00;
int end_code = 0xEF;

int x = 1;
char incomingByte2 = 0;
int incomingByte = 0;  

int play_music(char);
int stop_playback(void);
int next_playback(void);
int previous_playback(void);

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop(){
  
  char w[4] = {'T','0','0','2'};
  delay(1000);


if(incomingByte2 == 'd'){
  next_playback();
}

if(incomingByte2 == 'a'){
  previous_playback();
}

if(incomingByte2 == 's'){
  stop_playback();
}

if(x==1){
  play_music(w);
  //delay(8000);
  //w[3] = '3';
  //play_music(w);
  //delay(8000);
 x++;
}
  

incomingByte2 = 0;
if (Serial.available() > 0) {
                // read the incoming byte:
                incomingByte2 = Serial.read();

                // say what you got:
                Serial.print("I received: ");
                Serial.println(incomingByte2, DEC);
        }
  

      
if (Serial1.available() > 0) {
                // read the incoming byte:
                incomingByte = Serial1.read();

                // say what you got:
                Serial.print("I receivedww: ");
                Serial.println(incomingByte, DEC);
        }
}
  

// Play a file .MP3 
int play_music(char file_name[4]){
  lenght=0x07; // Number of the bytes in command
  command_code = 0xA3; // Command to play a file
  char c1 = file_name[0];
  char c2 = file_name[1];
  char c3 = file_name[2];
  char c4 = file_name[3];
 
  check_code = lenght + command_code + c1 + c2 + c3 + c4; // Is the sum of several commands
  check_code = check_code & 0x0FF;
  // Send of the commands 
  Serial1.write(start_code);
  Serial1.write(lenght);
  Serial1.write(command_code);
  Serial1.write(c1);
  Serial1.write(c2);
  Serial1.write(c3);
  Serial1.write(c4);
  Serial1.write(check_code);
  Serial1.write(end_code);

  return 0;
}

// Stop the playback
int stop_playback(void){
  lenght=0x03;
  command_code = 0xAB;
  check_code = 0xAE;
  Serial1.write(start_code);
  Serial1.write(lenght);
  Serial1.write(command_code);
  Serial1.write(check_code);
  Serial1.write(end_code);  
}

// Next playback
int next_playback(void){
  lenght=0x03;
  command_code = 0xAC;
  check_code = 0xAF;
  Serial1.write(start_code);
  Serial1.write(lenght);
  Serial1.write(command_code);
  Serial1.write(check_code);
  Serial1.write(end_code);  
}

// Previous playback
int previous_playback(void){
  lenght=0x03;
  command_code = 0xAD;
  check_code = 0xB0;
  Serial1.write(start_code);
  Serial1.write(lenght);
  Serial1.write(command_code);
  Serial1.write(check_code);
  Serial1.write(end_code);  
}

// Volume control from 00 - 1F
int volume_control(int volume){
  lenght=0x04;
  command_code = VOLUME;
  check_code = lenght + command_code + volume;
  
  Serial1.write(start_code);
  Serial1.write(lenght);
  Serial1.write(command_code);
  Serial1.write(volume);
  Serial1.write(check_code);
  Serial1.write(end_code);  
}



