//receiver sketch
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to receive messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) receiver with an Rx-B1 module

#include <RH_ASK.h> //includes the RadioHead lib
#include <SPI.h> 


RH_ASK driver;   //object driver called

void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
/*In the loop() a buffer is set whose size is equal to the size of the data that will be received
*/
void loop()
{
    uint8_t buf[30];
    uint8_t buflen = sizeof(buf);

    if (driver.recv(buf, &buflen)) // checking whether the data is valid or not
    {
	int i;
        Serial.print("Data:");          //printing the received data
        Serial.println((char*)buf);
    }
}
