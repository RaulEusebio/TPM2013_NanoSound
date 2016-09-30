# TPM2013_NanoSound
Library for use the Nano Sound Module with Arduino

The library can be used for replay music alocated in the root directory MicroSD.
Currently it contains five functions:
# play_music(char[4]):
This function need 4 characters correspondig to file name to play.

# stop_playback(), next_playback(), previous_playback:
Their names indicate

Finally exist #volume_control(int volume)
This function setup the volume in a range from 00 to 31 (00 is mute and 31 is maximal value)


