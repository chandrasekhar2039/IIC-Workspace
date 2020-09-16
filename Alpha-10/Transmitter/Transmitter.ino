// **** TRANSMITTER  **** //

#include <SPI.h>
#include <RH_ASK.h>

//  RadioHead library allows simple data transfer between Arduino boards.
//  This library takes our data and encapsulateit into a packet of data
//  which includes a CRC(Cyclic Redundancy Check)& then sends it.
//  A RadioHeaad packet consists of
//        * A 36 bit of training preamble: This is sent at the beginning
//          of every transmission.It contains a stream of 1 and 0 in pairs.
//        * A 12-bits start symbol
//        * 8-bit of message length(the message length <27 characters)
//        * 16-bit of Frame Check Sequence : This checks the CRC for 
//          authentication.

RH_ASK rf_driver;
// Creating the Amplitude Shift Keying object for the transmitter

void setup() {
  // Intializing the ASK object
  rf_driver.init();

  // Setting Pins
  pinMode(12,OUTPUT);
}

void loop() {
  const char *message = "Arduino World";
  // defining the message to be transmitted
  
  rf_driver.send((uint8_t *)message, strlen(message));
  // the send() method takes two parameters
  //    * an array of the data to be transmitted
  //     * length of the data 

  rf_driver.waitPacketSent();
  // waitPacketSent() methods confirms that the data are transmitted
  // in a proper sequence
  
  delay(1000);
  // This stops our transmitter for 1s which is helpful for
  // our reciever as it needs some time for processing the message.

}
