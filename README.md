# Portable Bluetooth Speaker using MATLAB and Arduino
The project was designed on MATLAB R2018b using the guide package available as part of the functionality making up the software. The circuitry for powering the speaker was designed using Arduino along with a breadboard, jumper cables, an SD Card module, a transistor for amplification and a Bluetooth module for communication. The Arduino board is powered by a 5000mah battery which in turn it uses to supply 5 volts to the speaker and the Bluetooth module. The Bluetooth object built into MATLAB was used to initiate the wireless connection between the guide interface and the Bluetooth module. In this report we will go into detail on how the project was designed by breaking it down into the designs which involved MATLAB and the designs which involved Arduino.

## Interfacing MATLAB with Arduino via Bluetooth
MATLAB is used to establish a connection to Arduino using the Bluetooth driver of the device and a device known as a Bluetooth module which allows Arduino to receive data via Bluetooth. The Bluetooth module is paired with the device on which MATLAB is installed and then using the built-in Bluetooth object in MATLAB, we can select the Bluetooth module which is named ‘HC-05’ from the list of paired devices, establish a connection and then send instructions, in this case, characters which we can use to manipulate whatever instruction Arduino will send to the speaker. We will be implementing four instructions, namely the Play, Pause and Stop function.
The following code is used to create a Bluetooth connection between Arduino and MATLAB

![picture1](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262182/picture1_biynpn.png)

## Designing the interface using MATLAB
![picture2](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262314/picture2_aijsau.png)

Using MATLAB guide, three buttons were created, each with their own unique function.
When the Play button is clicked, the file picker is triggered and this allows the user to select music so it can be played by the speaker.

![picture3](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262424/picture3_zqyeki.png)

The speaker library used to play the audio can only play audio in a .wav file format and so four songs were converted to audio files and uploaded to the SD card module so it can be played. The file picker sends the user into the directory which contain the same songs as is on the SD card so depending on the song the user selects, one particular character is sent to the Arduino board via Bluetooth (either ‘1’, ‘2’, ‘3’, ‘4’ based on the audio file selected). Arduino will then know which audio file to play.
When the ‘Pause’ button is clicked, the following code is executed

![picture4](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262507/picture4_pr2x4g.png)

MATLAB sends the character ‘P’ to the Arduino board which then momentarily stops the song currently playing.
Clicking on the same button once more causes Arduino to resume playing the song that was originally paused.
When the stop button is clicked, the following code is executed

![picture5](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262604/picture5_vxz4ic.png)

The character ‘S’ is sent to Arduino which then allows it to stop the song which is currently being played

## Implementing programming logic in Arduino

In Arduino, the SD card library allows us to play audio from an external SD card. This external SD contains songs that were uploaded to the device and exist in a .wav format which is the only audio format that the TMRpcm library, an open-source library for playing full length audio from an external SD card in Arduino can play. The Software Serial library allows us to initiate a Bluetooth connection using the Bluetooth module to any device to pair, in this case, the device which has MATLAB installed.
The following code allows us to initiate the Bluetooth connection while setting up our SD card and the TMRpcm library.

![picture6](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262721/picture6_pmcviy.png)

Now for the main logic, Arduino must first receive instructions from MATLAB, to know when an instruction has been received, we check whether the Bluetooth.available() function returns true and when it does we cycle through a few if statements to know which audio file will be playing as follows:

![picture7](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262797/picture7_kht64y.png)

Now we implement a while loop that runs while aud.isPlaying() returns true as we want the current audio file to keep playing before any other action takes place. The only actions that might need to take place while the audio is playing is the stop and pause functionality so inside of the while loop we need too check for that so we do that in the following code:

![picture8](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262892/picture8_gj7eyc.jpg)

## The picture below is the final circuit implementation

![picture9](https://res.cloudinary.com/emmanuelkepler/image/upload/v1679262999/picture9_cyomhh.jpg)

