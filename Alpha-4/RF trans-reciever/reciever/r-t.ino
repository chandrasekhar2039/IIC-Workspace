
#define datain 11
#define ledpin 9
 
//int signalstate 1;
// because initially we are going to set the value to HIGH
const int d1 = 100;
const int d2 =  500;
const int d3 = 1000;

void setup() {
  //code for the transmission part //
Serial.begin(9600);
//setting up all the pins 
pinMode(ledpin,OUTPUT);
pinMode(datain,INPUT);
}

void loop() {



//code for the recievre part
if(analogRead(datain)==0){
  //then golw the led
  //means we recieved 0
  digitalWrite(ledpin,HIGH);
  delay(d3);
  }
else{
  // whenever the t send 1 means led will glow 2 times
  
  digitalWrite(ledpin,LOW);
  delay(d2);
  }

}
