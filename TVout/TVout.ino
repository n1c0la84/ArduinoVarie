#include <TVout.h>
#include <fontALL.h>
#include "TVOlogo.h"
#include "schematic.h"

TVout TV; 
void setup() { 
    TV.begin(PAL,120,96); 
}

void loop() {
    printLogo(); TV.delay(3000); 
    TV.clear_screen(); TV.select_font(font6x8);
    TV.println("I am the TVout\nlibrary running on arduino\n"); TV.delay(2000);
    TV.println("I generate a PAL\nor NTSC composite  video using\ninterrupts\n"); TV.delay(3000);
    TV.bitmap(0,0,schematic); TV.delay(5000); TV.clear_screen();
}

void printLogo() {
    int index; unsigned char w,l,wb; 
    w = pgm_read_byte(TVOlogo); l = pgm_read_byte(TVOlogo+1);
    
    if (w&7) wb = w/8 + 1; else wb = w/8; index = wb*(l-1) + 2;
    
    for (unsigned char i = 1; i < l; i++) {
      TV.bitmap((TV.hres() - w)/2,0,TVOlogo,index,w,i);
      index-= wb; TV.delay(50);
    } 
    for (unsigned char i = 0; i < (TV.vres() - l)/2; i++) {
      TV.bitmap((TV.hres() - w)/2,i,TVOlogo);
      TV.delay(50);
    } 
}

