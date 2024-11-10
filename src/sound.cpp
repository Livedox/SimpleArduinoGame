#include <Arduino.h>
#include "sound.h"


void play(int* melody, int* duration, int len, int wholenote, int pinPiezo) {
    for (int thisNote = 0; thisNote < len; thisNote++) {
        int d;
        if (duration[thisNote] > 0) {
            d = wholenote / duration[thisNote];
        } else {
            d = wholenote / abs(duration[thisNote]);
            d *= 1.5;
        }
        tone(pinPiezo, melody[thisNote], d);
        int pauseBetweenNotes = d * 1.30;
        delay(pauseBetweenNotes);
        noTone(pinPiezo);
    }
}


int winMelody[] = {
    NOTE_D5, NOTE_E5, NOTE_A4, //1
    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_G5, NOTE_FS5,
    NOTE_D5, NOTE_E5, NOTE_A4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_D5,
    NOTE_D5, NOTE_E5, NOTE_A4, //repeat from 1
    NOTE_E5, NOTE_FS5, NOTE_A5, NOTE_G5, NOTE_FS5,
    NOTE_D5, NOTE_E5, NOTE_A4,
    NOTE_A4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_D5,
    REST, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_D5, NOTE_E5, NOTE_CS5,
    NOTE_B4, NOTE_A4, REST, 

    REST, NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_A4, //7
    NOTE_A5, REST, NOTE_A5, NOTE_E5, REST, 
    NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_E5, REST,
    REST, NOTE_CS5, NOTE_B4, NOTE_A4, REST,
    REST, NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_A4,
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, REST,
    
    NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_D5, //13
    NOTE_E5, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A4,
    REST, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4,
    REST, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,

    NOTE_E5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, //18
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, NOTE_A4, 
    NOTE_E5, NOTE_D5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_A5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,

    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4,  //23
    NOTE_E5, NOTE_D5, REST,
    REST, NOTE_B4, NOTE_D5, NOTE_B4, NOTE_D5, NOTE_E5, REST,
    REST, NOTE_CS5, NOTE_B4, NOTE_A4, REST,
    REST, NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_A4,
    REST, NOTE_A5, NOTE_A5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_D5,
    
    REST, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, //29
    REST, NOTE_CS5, NOTE_B4, NOTE_A4, REST,
    NOTE_B4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, NOTE_A4, REST,
    REST, NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, 
    NOTE_D5, NOTE_D5, NOTE_E5, NOTE_FS5, NOTE_E5, 
    NOTE_E5, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_A4,

    REST, NOTE_A4, NOTE_B4, NOTE_CS5, NOTE_D5, NOTE_B4, //35
    REST, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_E5, NOTE_E5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, 

    NOTE_E5, NOTE_D5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, //40
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_A5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4,  
    NOTE_E5, NOTE_D5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, //45
    NOTE_A5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4,  
    NOTE_E5, NOTE_D5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_FS5, NOTE_FS5, NOTE_E5, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4, //45
    
    NOTE_A5, NOTE_CS5, NOTE_D5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_B4, NOTE_D5, NOTE_B4,
    NOTE_D5, NOTE_E5, NOTE_CS5, NOTE_B4, NOTE_A4, NOTE_A4, 

    NOTE_E5, NOTE_D5, REST
};
int winDurations[] = {
    -4 ,-4, 4, //1
    -4, -4, 16, 16, 8,
    -4, -4, 2,
    16, 16, 16, 8, 16,
    -4, -4, 4, //repeat from 1
    -4, -4, 16, 16, 8,
    -4, -4, 2,
    16, 16, 16, 8, 16,
    4, 8, 8, 8, 8, 8, -8,
    16, 2, 4,

    8, 8, 8, 8, 8, 4, 8, //7
    8, 8, 8, -4, 4, 
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, -4, 4,
    8, 8, 8, 8, 8, 8, 4,
    8, 8, 8, 8, 4, 4,
    
    2, 8, 8, 8, //13
    8, 8, 8, 8, 4, 4,
    2, 8, 8, 8, 8,
    8, 8, 8, -4, 16, 16, 16, 16,
    -8, -8, -4, 16, 16, 16, 16,

    -8, -8, -8, 16, -8, 16, 16, 16, 16, //18
    4, 8, -8, 16, 8, 8, 8, 
    4, 2, 16, 16, 16, 16,
    -8, -8, -4, 16, 16, 16, 16,
    4, 8, -8, 16, 8, 16, 16, 16, 16,

    4, 8, -8, 16, 4, 8,  //23
    4, 2, 4,
    8, 8, 8, 8, 8, 4, 8,
    8, 8, 8, -4, 4,
    8, 8, 8, 8, 8, 8, 4,
    8, 8, 8, 8, 8, 8, 8,
    
    8, 8, 8, 8, 8, 8, //29
    8, 8, 8, -4, 4,
    8, 8, 8, 8, 8, 4, 8,
    8, 8, 8, 4, -4, 
    2, 8, 8, 8, 4, 
    8, 8, 8, 8, 8, 4,

    -4, 8, 8, 8, 8, 8, //35
    8, 8, 8, -4, 16, 16, 16, 16,
    -8, -8, -4, 16, 16, 16, 16,
    -8, -8, -8, 16, 8, 16, 16, 16, 16,
    4, 8, -8, 16, 4, 8, 

    4, 2 ,16, 16, 16, 16, //40
    -8, -8, -4, 16, 16, 16, 16,
    4, 8, -8, 16, 8, 16, 16, 16, 16,
    4, 8, -8, 16, 4, 8,  
    4, 2, 16, 16, 16, 16,
    
    -8, -8, -4, 16, 16, 16, 16, //45
    4, 8, -8, 16, 8, 16, 16, 16, 16,
    4, 8, -8, 16, 4, 8,  
    4, 2, 16, 16, 16, 16,
    -8, -8, -4, 16, 16, 16, 16, //45
    
    4, 8, -8, 16, 8, 16, 16, 16, 16,
    4, 8, -8, 16, 4, 8, 

    4, 2, 4
};

void playWin(int pinPiezo) {
    play(winMelody, winDurations, 340, 2144, pinPiezo);
}

int lossMelody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int lossDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};
void playLoss(int pinPiezo) {
    play(lossMelody, lossDurations, 8, 1000, pinPiezo);
}