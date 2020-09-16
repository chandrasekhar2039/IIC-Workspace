#define dataout 12


 int buttonpin = 10;
//int signalstate 1;
// because initially we are going to set the value to HIGH
const int d1 = 100;
const int d2 =  500;
const int d3 = 1000;

void setup() {
  //code for the transmission part //
Serial.begin(9600);
//setting up all the pins 
pinMode(buttonpin,INPUT);
//pinMode(ledpin,OUTPUT);
//pinMode(datain,INPUT);
pinMode(dataout,OUTPUT);
}

void loop() {
delay(d1);
digitalWrite(dataout,HIGH);
if (digitalRead(buttonpin)==1){
  digitalWrite(dataout,LOW);
  delay(d2);
  }
else{
digitalWrite(dataout,HIGH);
}

}
