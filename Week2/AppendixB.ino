const int segmentA = 2; // D0
const int segmentB = 3; // D1
const int segmentC = 4; // D2
const int segmentD = 5; // D3
const int segmentE = 6; // D4
const int segmentF = 7; // D5
const int segmentG = 8; // D6

const int button1 = 9;
const int button2 = 10;

int i=0;

void setup() {
// Initialize the digital pins as OUTPUTs
pinMode(segmentA, OUTPUT);
pinMode(segmentB, OUTPUT);
pinMode(segmentC, OUTPUT);
pinMode(segmentD, OUTPUT);
pinMode(segmentE, OUTPUT);
pinMode(segmentF, OUTPUT);
pinMode(segmentG, OUTPUT);

pinMode(button1,INPUT);
pinMode(button2,INPUT);


}

void loop() {

int x=digitalRead(button1);
int y=digitalRead(button2);

switch(i){
  case 0:call0();
  break;
  case 1:call1();
  break;
  case 2:call2();
  break;
  case 3:call3();
  break;
  case 4:call4();
  break;
  case 5:call5();
  break;
  case 6:call6();
  break;
  case 7:call7();
  break;
  case 8:call8();
  break;
  case 9:call9();
  break;
  case 10:i=0;
  }
if(x==1)
  {
  i++;
  delay(500);
    }

if(y==1)
{
  i=0;
}

}

void call0(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,LOW);

}

void call1(){
  
digitalWrite(segmentA, LOW);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, LOW);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG,LOW);

}
void call2(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, LOW);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG,HIGH);

}
void call3(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG,HIGH);

}
void call4(){
  
digitalWrite(segmentA, LOW);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, LOW);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,HIGH);

}
void call5(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, LOW);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,HIGH);

}
void call6(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, LOW);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,HIGH);

}
void call7(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, LOW);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, LOW);
digitalWrite(segmentG,LOW);

}
void call8(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,HIGH);

}
void call9(){
  
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, LOW);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,HIGH);

}
void reset(){
digitalWrite(segmentA, HIGH);
digitalWrite(segmentB, HIGH);
digitalWrite(segmentC, HIGH);
digitalWrite(segmentD, HIGH);
digitalWrite(segmentE, HIGH);
digitalWrite(segmentF, HIGH);
digitalWrite(segmentG,LOW);
}
void anime(){
  for(int i=0;i<3;i++){
digitalWrite(segmentA, HIGH);
delay(10);
digitalWrite(segmentB, HIGH);
delay(10);
digitalWrite(segmentC, HIGH);
delay(10);
digitalWrite(segmentD, HIGH);
delay(10);
digitalWrite(segmentE, HIGH);
delay(10);
digitalWrite(segmentF, HIGH);
delay(10);
digitalWrite(segmentG,HIGH);
delay(10);
digitalWrite(segmentA, LOW);
delay(10);
digitalWrite(segmentB, LOW);
delay(10);
digitalWrite(segmentC, LOW);
delay(10);
digitalWrite(segmentD, LOW);
delay(10);
digitalWrite(segmentE, LOW);
delay(10);
digitalWrite(segmentF, LOW);
delay(10);
digitalWrite(segmentG,LOW);
delay(10);
}
}
