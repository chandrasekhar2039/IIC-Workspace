#include <VirtualWire.h>     // virtual wire library is included


int ledPin=8;    // pin 8 has led connected on board
const int dataPin=12;  // pin 12 is connected with data pin of reciever

void setup()
{
    vw_set_rx_pin(dataPin);  //sets the dataPin to use for recieving data
    vw_setup(2000);          //initialises the virtual wire to operate at 2000 bits per second
    pinMode(ledPin, OUTPUT);
    vw_rx_start();           //starts the reciever to recieve data
}

void loop()
{
    uint8_t buf[VW_MAX_MESSAGE_LEN];      // declare a variable to store the recieved data
    uint8_t buflen = VW_MAX_MESSAGE_LEN;  // declares a variable to store the length of recieved data
 
    if (vw_get_message(buf, &buflen))    //if the message is available copies it to buf
    {
      if(buf[0]=='a')  
      {  
       digitalWrite(ledPin,HIGH);        // turns led on
      }  
      else if(buf[0]=='b')
      {
       digitalWrite(ledPin,LOW);         //turns led off
      }
    }
}
