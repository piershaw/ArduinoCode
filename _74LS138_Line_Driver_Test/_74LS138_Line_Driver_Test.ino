//**************************************************************//
//  Name    : Line Select Example 1                            //
//  Author  : Pier Shaw                                       //
//  Date    : 1 FEB, 2014                                     //
//  Version : 1.0                                             //
//  Notes   : Code for using a TTL, 74LS138 3 of 8 Decoder/Demultiplexer //
//****************************************************************


//this is good to select a memory andress or something else

int G1 = 2;
int G2A = 3; 
int G2B = 4;
int sel_A = 5;
int sel_B = 6; 
int sel_C = 7;
int line_Address_selector = 0;
int what_ABC_Pin_Number = 0;
int bitArray[10][3];


void setup() {
  
   //this works for me
   digitalWrite(G1, LOW);
   digitalWrite(G2A, LOW);
   digitalWrite(G2B, HIGH);
   
   
  //define pin modes
  pinMode(G1, OUTPUT);
  pinMode(G2A, OUTPUT); 
  pinMode(G2B, OUTPUT);
  pinMode(sel_A, OUTPUT);
  pinMode(sel_B, OUTPUT); 
  pinMode(sel_C, OUTPUT);
  
  //Active Low Selects
  //all possible Bits
  
  //Y0 
  bitArray[0][0] = 0;
  bitArray[0][1] = 0;
  bitArray[0][2] = 0;
  //Y1
  bitArray[1][0] = 0;
  bitArray[1][1] = 0;
  bitArray[1][2] = 1;
  //Y2
  bitArray[2][0] = 0;
  bitArray[2][1] = 1;
  bitArray[2][2] = 0;
  //Y3
  bitArray[3][0] = 0;
  bitArray[3][1] = 1;
  bitArray[3][2] = 1;
  //Y4
  bitArray[4][0] = 1;
  bitArray[4][1] = 0;
  bitArray[4][2] = 0;
  //Y5
  bitArray[5][0] = 1;
  bitArray[5][1] = 0;
  bitArray[5][2] = 1;
  //Y6
  bitArray[6][0] = 1;
  bitArray[6][1] = 1;
  bitArray[6][2] = 0;
  //Y7
  bitArray[7][0] = 1;
  bitArray[7][1] = 1;
  bitArray[7][2] = 1;
  
  
  
}

void loop() {
Serial.begin(9600);
pickLine();
}


void pickLine(){
  
     if(line_Address_selector >= 7){
       line_Address_selector = -1;
     }else{
       line_Address_selector += 1;
       Serial.println("____line_Address_selector____");
       Serial.println(line_Address_selector);
     }
     
     
     if(what_ABC_Pin_Number >= 2){
       what_ABC_Pin_Number = -1;
     }else{
       what_ABC_Pin_Number += 1;
       Serial.println("____Pin ABC____");
       Serial.println(what_ABC_Pin_Number);
     }
     
        
       digitalWrite(sel_A,  bitArray[line_Address_selector][0]);
       digitalWrite(sel_B,  bitArray[line_Address_selector][1]);
       digitalWrite(sel_C,  bitArray[line_Address_selector][2]);
     
 delay(2000);
   
}
