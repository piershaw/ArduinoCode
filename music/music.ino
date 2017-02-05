



int buzzerpin = 8;
int light = 7;

#define NOTE_C6 1047
#define NOTE_D6 1175
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_B6 1976
#define NOTE_C7 2093




void setup(){
 pinMode(light,OUTPUT);
  
}

 void loop(){
  tone(buzzerpin,NOTE_C6,500);
 
       delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
  tone(buzzerpin,NOTE_D6,500);
  
    delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
    
  tone(buzzerpin,NOTE_E6,500);
      delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
  tone(buzzerpin,NOTE_C6,500);
       delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
  tone(buzzerpin,NOTE_F6,500);
       delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
  tone(buzzerpin,NOTE_G6,500);
    delay(500);
  tone(buzzerpin,NOTE_A6,500);
       delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
  tone(buzzerpin,NOTE_B6,500);
        delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
  tone(buzzerpin,NOTE_C7,500);
  
     delay(200);
       digitalWrite(light,LOW);
         delay(300);
       digitalWrite(light,HIGH);
}
