// Paint application - Demonstate both TFT and Touch Screen
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of the GNU Lesser General Public
//  License as published by the Free Software Foundation; either
//  version 2.1 of the License, or (at your option) any later version.
//
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
#include <stdint.h>
#include <TouchScreen.h> 
#include <TFT.h>
#include <SdFat.h>

#ifdef SEEEDUINO
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 14   // can be a digital pin, this is A0
  #define XP 17   // can be a digital pin, this is A3 
#endif

#ifdef MEGA
  #define YP A2   // must be an analog pin, use "An" notation!
  #define XM A1   // must be an analog pin, use "An" notation!
  #define YM 54   // can be a digital pin, this is A0
  #define XP 57   // can be a digital pin, this is A3 
#endif 

//Measured ADC values for (0,0) and (210-1,320-1)
//TS_MINX corresponds to ADC value when X = 0
//TS_MINY corresponds to ADC value when Y = 0
//TS_MAXX corresponds to ADC value when X = 240 -1
//TS_MAXY corresponds to ADC value when Y = 320 -1

#define TS_MINX 140 
#define TS_MAXX 900
#define TS_MINY 120
#define TS_MAXY 940

int color = WHITE;  //Paint brush color
int X,Y;
// information we extract about the bitmap file
int bmpWidth, bmpHeight;
uint8_t bmpDepth, bmpImageoffset;

SdFat sd;
SdFile myFile;
String message;
// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// The 2.8" TFT Touch shield has 300 ohms across the X plate

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); //init TouchScreen port pins
const int chipSelect = SS;

void setup() {
  Serial.begin(9600);
 
  Tft.init();
//  Serial.print("Initializing SD card...");
//  pinMode(chipSelect, OUTPUT); //53 is used as chip select pin
//  
//  
//  // read from the file until there's nothing else in it:
//  int data;
//  while ((data = myFile.read()) >= 0) Serial.write(data);
//  
//  if (!myFile.open("test.txt", O_RDWR | O_CREAT | O_AT_END)) {
//    sd.errorHalt("opening test.txt for write failed");
//  }else{
//  
//  }
//   message = "hello"; 
  
  //String sensorVal = String(analogRead(A0));

  
  
   //char c = myFile.read();
   //Serial.print(c);
  
  //bmpdraw(myFile, 0, 0);
  //myFile.close();

 
  pinMode(0,OUTPUT);
  X = 0; 
  Y = 0;
        
  int screenWidth = 240; 
  int screenHeight = 320;
        
  
         	
}


void loop() {
//Image 1
//   myFile.open("back01.bmp",O_READ);
//   if(! bmpReadHeader(myFile)) { 
//     Serial.println("bad bmp");
//     return;
//  }
//bmpdraw(myFile, 0, 0);

//Tft.drawString(message,0,160,1,CYAN);
//Tft.drawChar(message,160,1,CYAN);

Tft.fillRectangle(107,119,10,10,0xcc6600);

Tft.fillRectangle(107,119,10,10,0xcc6600);

Tft.fillRectangle(97,124,10,10,0xcc6600);

Tft.fillRectangle(93,135,10,10,0xcc6600);

Tft.fillRectangle(96,142,10,10,0xcc6600);

Tft.fillRectangle(105,146,10,10,0xcc6600);

Tft.fillRectangle(113,148,10,10,0xcc6600);

Tft.fillRectangle(123,137,10,10,0xcc6600);

Tft.fillRectangle(120,126,10,10,0xcc6600);

Tft.fillRectangle(117,116,10,10,0xcc6600);

Tft.fillRectangle(116,119,10,10,0xcc6600);

Tft.fillRectangle(110,127,10,10,0xcc6600);

Tft.fillRectangle(104,129,10,10,0xcc6600);

Tft.fillRectangle(101,135,10,10,0xcc6600);

Tft.fillRectangle(101,135,10,10,0xcc6600);

Tft.fillRectangle(101,135,10,10,0xcc6600);

Tft.fillRectangle(101,135,10,10,0xcc6600);

Tft.fillRectangle(113,137,10,10,0x006600);

Tft.fillRectangle(107,143,10,10,0x006600);

Tft.fillRectangle(107,143,10,10,0x006600);

Tft.fillRectangle(107,143,10,10,0x006600);

Tft.fillRectangle(106,135,10,10,0x006600);

Tft.fillRectangle(106,135,10,10,0x006600);

Tft.fillRectangle(106,135,10,10,0x006600);

Tft.fillRectangle(106,135,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(123,144,10,10,0x006600);

Tft.fillRectangle(99,162,10,10,0x006600);

Tft.fillRectangle(99,162,10,10,0x006600);

Tft.fillRectangle(99,162,10,10,0x006600);

Tft.fillRectangle(100,154,10,10,0x006600);

Tft.fillRectangle(93,167,10,10,0x006600);

Tft.fillRectangle(93,167,10,10,0x006600);

Tft.fillRectangle(123,110,10,10,0x006600);

Tft.fillRectangle(130,98,10,10,0x006600);

Tft.fillRectangle(130,98,10,10,0x006600);

Tft.fillRectangle(129,104,10,10,0x006600);

Tft.fillRectangle(131,117,10,10,0x006600);

Tft.fillRectangle(141,119,10,10,0x006600);

Tft.fillRectangle(141,119,10,10,0x006600);

Tft.fillRectangle(125,120,10,10,0x006600);

Tft.fillRectangle(130,129,10,10,0x006600);

Tft.fillRectangle(138,133,10,10,0x006600);

Tft.fillRectangle(138,133,10,10,0x006600);

Tft.fillRectangle(138,133,10,10,0x006600);

Tft.fillRectangle(137,148,10,10,0x006600);

Tft.fillRectangle(129,145,10,10,0x006600);

Tft.fillRectangle(144,153,10,10,0x006600);

Tft.fillRectangle(121,151,10,10,0x006600);

Tft.fillRectangle(126,163,10,10,0x006600);

Tft.fillRectangle(130,168,10,10,0x006600);

Tft.fillRectangle(106,109,10,10,0x006600);

Tft.fillRectangle(100,99,10,10,0x006600);

Tft.fillRectangle(96,91,10,10,0x006600);

Tft.fillRectangle(94,113,10,10,0x006600);

Tft.fillRectangle(83,115,10,10,0x006600);

Tft.fillRectangle(75,111,10,10,0x006600);

Tft.fillRectangle(87,124,10,10,0x006600);

Tft.fillRectangle(77,124,10,10,0x006600);

Tft.fillRectangle(70,125,10,10,0x006600);

Tft.fillRectangle(87,139,10,10,0x006600);

Tft.fillRectangle(75,139,10,10,0x006600);

Tft.fillRectangle(75,139,10,10,0x006600);

Tft.fillRectangle(75,139,10,10,0x006600);

Tft.fillRectangle(75,139,10,10,0x006600);

Tft.fillRectangle(75,139,10,10,0x006600);

Tft.fillRectangle(74,159,10,10,0x006600);

Tft.fillRectangle(80,154,10,10,0x006600);

Tft.fillRectangle(80,154,10,10,0x006600);

Tft.fillRectangle(80,154,10,10,0x006600);

Tft.fillRectangle(88,147,10,10,0x006600);

Tft.fillRectangle(88,147,10,10,0x006600);

Tft.fillRectangle(136,90,10,10,0x006600);

Tft.fillRectangle(148,116,10,10,0x006600);

Tft.fillRectangle(100,110,10,10,0x006600);

Tft.fillRectangle(122,157,10,10,0x006600);

Tft.fillRectangle(122,157,10,10,0x006600);

Tft.fillRectangle(110,157,10,10,0x006600);

Tft.fillRectangle(110,157,10,10,0x006600);

Tft.fillRectangle(110,157,10,10,0x006600);

Tft.fillRectangle(110,169,10,10,0x006600);

Tft.fillRectangle(110,169,10,10,0x006600);

Tft.fillRectangle(111,179,10,10,0x006600);

Tft.fillRectangle(112,189,10,10,0x006600);

Tft.fillRectangle(113,200,10,10,0x006600);

Tft.fillRectangle(109,165,10,10,0x006600);

Tft.fillRectangle(111,206,10,10,0x006600);

Tft.fillRectangle(111,206,10,10,0x006600);

Tft.fillRectangle(111,206,10,10,0x006600);

Tft.fillRectangle(114,197,10,10,0x006600);

Tft.fillRectangle(109,219,10,10,0x006600);

Tft.fillRectangle(109,219,10,10,0x006600);

Tft.fillRectangle(109,219,10,10,0x006600);

Tft.fillRectangle(109,212,10,10,0x006600);

Tft.fillRectangle(122,186,10,10,0x006600);

Tft.fillRectangle(122,186,10,10,0x006600);

Tft.fillRectangle(119,192,10,10,0x006600);

Tft.fillRectangle(127,193,10,10,0x006600);

Tft.fillRectangle(127,193,10,10,0x006600);

Tft.fillRectangle(127,193,10,10,0x006600);

Tft.fillRectangle(100,204,10,10,0x006600);

Tft.fillRectangle(100,204,10,10,0x006600);

Tft.fillRectangle(100,204,10,10,0x006600);

Tft.fillRectangle(96,210,10,10,0x006600);


//Tft.fillRectangle(0,200,240,320,BLACK);

//Tft.clearGraphics();
}


#define BUFFPIXEL 20

void bmpdraw(SdFile f, int x, int y) {
  //myFile.seek(bmpImageoffset);
  
  uint32_t time = millis();
  uint16_t p;
  uint8_t g, b;
  int i, j;
  
  uint8_t sdbuffer[3 * BUFFPIXEL];  // 3 * pixels to buffer
  uint8_t buffidx = 3*BUFFPIXEL;
  

  for (i=0; i< bmpHeight; i++) {
    
      Tft.setXY(x, y+bmpHeight-i); 
    
    
    for (j=0; j<bmpWidth; j++) {
      // read more pixels
      if (buffidx >= 3*BUFFPIXEL) {
        myFile.read(sdbuffer, 3*BUFFPIXEL);
        buffidx = 0;
      }
      
      // convert pixel from 888 to 565
      b = sdbuffer[buffidx++];     // blue
      g = sdbuffer[buffidx++];     // green
      p = sdbuffer[buffidx++];     // red
      
      p >>= 3;
      p <<= 6;
      
      g >>= 2;
      p |= g;
      p <<= 5;
      
      b >>= 3;
      p |= b;
     
       // write out the 16 bits of color
      Tft.sendData(p);
    }
  }
  Serial.print(millis() - time, DEC);
  Serial.println(" ms");
}

boolean bmpReadHeader(SdFile f) {
   // read header
  uint32_t tmp;
  
  if (read16(f) != 0x4D42) {
    // magic bytes missing
    return false;
  }
 
  // read file size
  tmp = read32(f);  
  Serial.print("size 0x"); Serial.println(tmp, HEX);
  
  // read and ignore creator bytes
  read32(f);
  
  bmpImageoffset = read32(f);  
  Serial.print("offset "); Serial.println(bmpImageoffset, DEC);
  
  // read DIB header
  tmp = read32(f);
  Serial.print("header size "); Serial.println(tmp, DEC);
  bmpWidth = read32(f);
  bmpHeight = read32(f);

  
  if (read16(f) != 1)
    return false;
    
  bmpDepth = read16(f);
  Serial.print("bitdepth "); Serial.println(bmpDepth, DEC);

  if (read32(f) != 0) {
    // compression not supported!
    return false;
  }
  
  Serial.print("compression "); Serial.println(tmp, DEC);

  return true;
}

/*********************************************/
// These read data from the SD card file and convert them to big endian 
// (the data is stored in little endian format!)

// LITTLE ENDIAN!
uint16_t read16(SdFile f) {
  uint16_t d;
  uint8_t b;
  b = f.read();
  d = f.read();
  d <<= 8;
  d |= b;
  return d;
}

// LITTLE ENDIAN!
uint32_t read32(SdFile f) {
  uint32_t d;
  uint16_t b;
 
  b = read16(f);
  d = read16(f);
  d <<= 16;
  d |= b;
  return d;
}

