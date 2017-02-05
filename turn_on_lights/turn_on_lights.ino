
int ledPin = 8; // LED connected to digital 
int resetButton = 2;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(resetButton, INPUT);
}

void loop(){

  delay(90);  
  int sensorValue = analogRead(A0);   // read the input pin
  int buttonValue = digitalRead(resetButton);   // read the input pin
  val = buttonValue;
  float voltage = sensorValue * (5.0 / 1024.0);
  //float voltageButton = val * (5.0 / 1024.0);
 
 //int voltageR = (voltage - 2.0); 
 
  if(voltage < 0.50){
      digitalWrite(ledPin, HIGH);   // sets the LED on
  }
  
 
  if(val == HIGH){
     reset();
  }
  
   //Serial.println(val);
   Serial.println(voltage);
}

void reset(){
   val = 0;
  digitalWrite(ledPin, LOW);
}

