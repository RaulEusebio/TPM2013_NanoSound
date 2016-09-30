# TPM2013_NanoSound
Library for use the Nano Sound Module with Arduino

The library can be used for replay music alocated in the root directory MicroSD of the Nano Sound Module TPM2013.

There are two directories "example_TPM2013_nanoSound/" and "example_TPM2013_w_SoftwareSerial/" and each is util with different hardware characteristics.
Example the library in "example_TPM2013_nanoSound/" is for use with serial port of any board and the example in "example_TPM2013_w_SoftwareSerial/" is for use with SoftwareSerial.h library, this allow us use another pins for simulate a serial port.


Currently in both libraries have five functions:
# play_music(char[4]):
This function need 4 characters correspondig to file name to play.

# stop_playback(), next_playback(), previous_playback:
As the name indicated are for stop, next and previous playback.

Finally exist
# volume_control(int volume)
This function set up the volume in a range from 00 to 31 (00 is mute and 31 is maximal value)


Questions or comments please contact me at: luar.eugr@gmail.com



