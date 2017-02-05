// Ported to SdFat from the native Arduino SD library example by Bill Greiman
// On the Ethernet Shield, CS is pin 4. SdFat handles setting SS

#include <stdint.h>
#include <TouchScreen.h>
#include <TFT.h>
#include <SD.h>
#include <SdFat.h>


const int chipSelect = SS;


static unsigned int TS_MINX, TS_MAXX, TS_MINY, TS_MAXY;
 
//Touch Screen Co-ordinate mapping register
static unsigned int MapX1, MapX2, MapY1, MapY2;
 
// For better pressure precision, we need to know the resistance
// between X+ and X- Use any multimeter to read it
// The 2.8" TFT Touch shield has 300 ohms across the X plate
 
/* Usage: TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300); 
 Where, XP = X plus, YP = Y plus, XM = X minus and YM = Y minus */
//init TouchScreen port pins. This would be reinitialized in setup() based on the hardware detected.
static unsigned int cardSelect = SS;
//works
TouchScreen ts = TouchScreen(17, A2, A1, 14, 300); 
 
// In the SD card, place 24 bit color BMP files (be sure they are 24-bit!)
// the file itself

///this might change for me 24bit 
File bmpFile;
int bmpWidth, bmpHeight;
uint8_t bmpDepth, bmpImageoffset;

SdFat sd;
SdFile myFile;

void setup() {
  
  Tft.init();//init TFT
  initTouchScreenParameters(); //initializes Touch Screen parameters based on the detected TFT Touch Schield hardware
 
  
  Serial.begin(9600);
  while (!Serial) {}  // wait for Leonardo
  Serial.println("Type any character to start");
  while (Serial.read() <= 0) {}
  delay(400);  // catch Due reset problem
  
  // Initialize SdFat or print a detailed error message and halt
  // Use half speed like the native library.
  // change to SPI_FULL_SPEED for more performance.
  if (!sd.begin(chipSelect, SPI_HALF_SPEED)) sd.initErrorHalt();


   //Image 1
  bmpFile = SD.open("back01.raw");
  if (! bmpFile) {
    Serial.println("didnt find image");
    while (1);
  }
  
 
  if (! bmpReadHeader(bmpFile)) { 
     Serial.println("bad");
  }else{
     Serial.println("good");
  }
  
   bmpdraw(bmpFile, 0, 0);
   
 

}


 #define BUFFPIXEL 20

void bmpdraw(File f, int x, int y) {
  bmpFile.seek(bmpImageoffset);
  
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
        bmpFile.read(sdbuffer, 3*BUFFPIXEL);
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
boolean bmpReadHeader(File f) {
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
 
void initTouchScreenParameters()
{
  //This function initializes Touch Screen parameters based on the detected TFT Touch Schield hardware


    ts = TouchScreen(14, A1, A2, 17, 300); //init TouchScreen port pins

    //Touchscreen parameters for this hardware
    TS_MINX = 120;
    TS_MAXX = 910;
    TS_MINY = 120;
    TS_MAXY = 950;
 
    MapX1 = 239;
    MapX2 = 0;
    MapY1 = 0;
    MapY2 = 319; 
 
    //Touchscreen parameters for this hardware
    TS_MINX = 140;
    TS_MAXX = 900;
    TS_MINY = 120;
    TS_MAXY = 940;
 
    MapX1 = 239;
    MapX2 = 0;
    MapY1 = 319;
    MapY2 = 0;
  
}


/*********************************************/
// These read data from the SD card file and convert them to big endian 
// (the data is stored in little endian format!)

// LITTLE ENDIAN!
uint16_t read16(File f) {
  uint16_t d;
  uint8_t b;
  b = f.read();
  d = f.read();
  d <<= 8;
  d |= b;
  return d;
}

// LITTLE ENDIAN!
uint32_t read32(File f) {
  uint32_t d;
  uint16_t b;
 
  b = read16(f);
  d = read16(f);
  d <<= 16;
  d |= b;
  return d;
}



