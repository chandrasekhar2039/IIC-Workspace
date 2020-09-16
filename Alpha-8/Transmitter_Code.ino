#define dataout 12
#define ledPin 7

 void setup()
 {
   pinMode(dataout, OUTPUT);     
   pinMode(ledPin, OUTPUT);    
 }

 void loop()
 {
   
     digitalWrite(dataout, HIGH);
     digitalWrite(ledPin, HIGH);
     delay(3000);
     
     digitalWrite(dataout,LOW);
     digitalWrite(ledPin, LOW);
     delay(3000);
 
 }
