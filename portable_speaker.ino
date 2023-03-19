#include <SoftwareSerial.h>
#include <SPI.h>
#include <SD.h>
#define SD_ChipSelectPin 4
#include <TMRpcm.h>

int TxD;
int RxD;
int data = 2;
char sample[] = "sample1.wav";
SoftwareSerial bluetooth(TxD, RxD);
TMRpcm aud;



void setup () {
    Serial.begin(9600);
    bluetooth.begin(9600);
    aud.speakerPin = 9;
   
    if (!SD.begin(SD_ChipSelectPin)) {
        Serial.println("SD card not found");
        return;
    }
    Serial.println("SD card found");
}

void loop (){
    if(bluetooth.available()){
        data = bluetooth.read();
    }

    if(data == '1'){
        aud.play(sample,"sample1.wav");
        aud.setVolume(6);
        aud.play(sample);
    } else if(data == '2'){
        strcpy(sample, "sample2.wav");
        aud.setVolume(6);
        aud.play(sample);
    } else if(data == '3'){
        strcpy(sample, "sample3.wav");
        aud.setVolume(6);
        aud.play(sample);
    } else if(data == '4'){
        strcpy(sample, "sample4.wav");
        aud.setVolume(6);
        aud.play(sample);
    } 

    while(aud.isPlaying()){
        if(bluetooth.available()){
            data = bluetooth.read();
        }
        if(data == 'P'){
            aud.pause();
        }else if(data == 'S'){
            aud.stopPlayback();
        }
    }
}