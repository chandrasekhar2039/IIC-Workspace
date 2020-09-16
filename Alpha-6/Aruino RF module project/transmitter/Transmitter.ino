#define dataOut 12 //Pin 12 is attatched to OUT of Tranmitter Module.
#define ledPin 7   //Pin 7 is attached to LED.

void setup() {
  // put your setup code here, to run once:
 pinMode(dataOut,OUTPUT);  //initializes the Transmitter for Input.
 pinMode(ledPin,OUTPUT);  //inializes digital pin
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dataOut,HIGH); //Writes "1" to the transmitter. 
  digitalWrite(ledPin,HIGH);  //Turns the LED on.
  delay(1000);                //wait for a second.

  digitalWrite(dataOut,LOW); //Writes "0" to the transmitter.
  digitalWrite(ledPin,LOW);  ///Turns the LED off.
  delay(1000);

  
}
