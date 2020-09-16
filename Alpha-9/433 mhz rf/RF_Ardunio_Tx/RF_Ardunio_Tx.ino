#include <VirtualWire.h>     // virtual wire library is included



char *data;
const int dataPin=12;   // pin 12 is connected with data pin of the transmitter
const int buttonPin=9;  // pin 9 is connected to the switch
int buttonValue;

void setup() 
{
  vw_set_tx_pin(dataPin);  // sets the dataPin to use for transmitting data
  vw_setup(2000);          //initialises the virtual wire to operate at 2000 bits per second
  pinMode(buttonPin,INPUT); //initialise the buttonPin as an input
  Serial.begin(9600);      
}

void loop()
{
  buttonValue = digitalRead(buttonPin);    //reads the state of pushbutton(0 or 1)
  Serial.println(buttonValue);
  if(buttonValue==1)
  {
    data="a";
    vw_send((uint8_t *)data, strlen(data));  //sends the message data ="a" along with its length
    vw_wait_tx();   // block and wait until a message is transmitter is idle
    delay(500);     //wait for 500ms for the data to be transmitted
  }
  else
  {
    data="b";
    vw_send((uint8_t *)data, strlen(data)); // sends the message data="b" along with its length
    vw_wait_tx();
    delay(500);
    
  }
  delay(200);
}
