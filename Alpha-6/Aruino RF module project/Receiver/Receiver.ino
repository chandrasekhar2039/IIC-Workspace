#define dataIn A0
const int ledPin=12;
unsigned int temp = 0;

const unsigned int lowerValue = 50;
const unsigned int upperValue = 600;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 temp = analogRead(dataIn);
 if(temp < lowerValue) {
  
  digitalWrite(ledPin,HIGH);
  
 }
 else if(temp > upperValue){
  digitalWrite(ledPin,LOW);
  
  }
  
}
