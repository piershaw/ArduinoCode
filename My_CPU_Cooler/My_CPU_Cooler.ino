

int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor

// include the library
#include <LiquidCrystal.h>

// all of our LCD pins
//int lcdRSPin = 12;
//int lcdEPin = 11;

//int lcdD4Pin = 5;
//int lcdD5Pin = 4;
//int lcdD6Pin = 3;
//int lcdD7Pin = 2;


//int ledPin = 12;      // select the pin for the LED



int lcd2RSPin = 13;
int lcd2EPin = 6;

int lcd2D4Pin = 10;
int lcd2D5Pin = 9;
int lcd2D6Pin = 8;
int lcd2D7Pin = 7;

LiquidCrystal lcd(lcd2RSPin, lcd2EPin,lcd2D4Pin, lcd2D5Pin, lcd2D6Pin, lcd2D7Pin);


int R = 2;
int G = 3;
int B = 4;


int RGBColor[8][3];

void setup() {
    // declare the ledPin as an OUTPUT:
    pinMode(R, OUTPUT);  
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    
    Serial.begin(9600);
    lcd.begin(16, 2);
    lcd.print("TEMP");
    
    RGBColor[0][0] = 1;//white
    RGBColor[0][1] = 1;//white
    RGBColor[0][2] = 1;//white
    
    RGBColor[1][0] = 1;//red
    RGBColor[1][1] = 0;//red
    RGBColor[1][2] = 0;//red
}

void loop() {
  // read the value from the sensor:
   sensorValue = analogRead(sensorPin); 
   Serial.println("temp");   
   Serial.println(((sensorValue + 700) / 10));  
  // turn the ledPin on
  
    delay(1000);    
   //set the cursor to column 0, line 1
   //(note: line 1 is the second row, since counting begins with 0)
    lcd.setCursor(0, 1);
 
    lcd.print(((sensorValue + 700) / 10));
   
    
    if(((sensorValue + 500) / 10) > 100){
       digitalWrite(R, RGBColor[1][0]); 
       digitalWrite(G, RGBColor[1][1]); 
       digitalWrite(B, RGBColor[1][2]);
    }else{
       digitalWrite(R, RGBColor[0][0]); 
       digitalWrite(G, RGBColor[0][1]); 
       digitalWrite(B, RGBColor[0][2]);
    }
    
    
     
     
}
