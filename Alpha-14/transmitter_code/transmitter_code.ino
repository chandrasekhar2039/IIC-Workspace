//transmitter sketch
// -*- mode: C++ -*-
// Simple example of how to use RadioHead to transmit messages
// with a simple ASK transmitter in a very simple way.
// Implements a simplex (one-way) transmitter with an TX-C1 module

#include <RH_ASK.h>
#include <SPI.h> // includes RadioHead ASK lib
int dt=1000;     //delay time of 1sec
RH_ASK driver;   //RH_ASK object called driver
/*initializing RH_ASK object in setup() by using init() */
void setup()
{
    Serial.begin(9600);	  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}
/*sending the data.Data saved in data variable*/
void loop()
{
    const char *data = "Welcome to IIC of VSSUT Burla.";

    driver.send((uint8_t*)data, strlen(data));      //sending data
    driver.waitPacketSent();
    delay(dt);                                      //delay time
}
