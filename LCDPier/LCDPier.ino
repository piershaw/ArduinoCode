/*
 * Tutorial 8: Using the LCD
 * 
 * Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 * library works with all LCD displays that are compatible with the 
 * Hitachi HD44780 driver. There are many of them out there, and you
 * can usually tell them by the 16-pin interface.
 *
 * Adjust the LCDs contrast with the Potentiometer until you
 * can see the characters on the LCD.
 *
 * The circuit:
 * - LCD RS pin to digital pin 12
 * - LCD Enable pin to digital pin 11
 * - LCD D4 pin to digital pin 5
 * - LCD D5 pin to digital pin 4
 * - LCD D6 pin to digital pin 3
 * - LCD D7 pin to digital pin 2
 * - LCD R/W pin to ground
 * - 10K potentiometer divider for LCD pin VO:
 * - 330ohm resistor betweenm LCD pin A and 5v
 * - LCD pin K to ground
 *
 * Library originally added 18 Apr 2008
 * by David A. Mellis
 * library modified 5 Jul 2009
 * by Limor Fried (http://www.ladyada.net)
 * example added 9 Jul 2009
 * by Tom Igoe
 * modified 22 Nov 2010
 * by Tom Igoe
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * This example code is in the public domain.
 *
 * Derivative work from:
 * http://www.arduino.cc/en/Tutorial/LiquidCrystal
 *
 */

// include the library
#include <LiquidCrystal.h>

// all of our LCD pins
//int lcdRSPin = 12;
//int lcdEPin = 11;

//int lcdD4Pin = 5;
//int lcdD5Pin = 4;
//int lcdD6Pin = 3;
//int lcdD7Pin = 2;

int sensorPin = A0;    // select the input pin for the potentiometer
//int ledPin = 12;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor


int lcd2RSPin = 13;
int lcd2EPin = 6;

int lcd2D4Pin = 10;
int lcd2D5Pin = 9;
int lcd2D6Pin = 8;
int lcd2D7Pin = 7;


// initialize the library with the numbers of the interface pins
//LiquidCrystal lcd(lcdRSPin, lcdEPin, lcdD4Pin, lcdD5Pin, lcdD6Pin, lcdD7Pin);
                  
LiquidCrystal lcd2(lcd2RSPin, lcd2EPin,lcd2D4Pin, lcd2D5Pin, lcd2D6Pin, lcd2D7Pin);


void setup()
{
    // set up the LCD's number of columns and rows: 
    //lcd.begin(16, 2);
    lcd2.begin(16, 2);
     //pinMode(ledPin, OUTPUT);  
    
    // Print a message to the LCD.
    lcd2.print("val");
    //lcd2.print("shaw");
    //lcd2.setCursor(0, 1);
    //lcd2.print("is cool!");
}

void loop()
{
    // set the cursor to column 0, line 1
    // (note: line 1 is the second row, since counting begins with 0)
    //lcd.setCursor(0, 1);
    sensorValue = analogRead(sensorPin); 
    lcd2.setCursor(0, 1);

    // print the number of seconds since reset
    lcd2.print(sensorValue);
    //lcd.print(millis() / 1000);
    //lcd2.print(millis() / 1000);
}
