// **** RECEIVER  **** //

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
// Creating the Amplitude Shift Keying object for the RECEIVER


void setup() {
  // Intializing the ASK object
  rf_driver.init();

  // Setting the pin Mode
  pinMode(12,INPUT);
  
  // Setting up the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Setting the size of buffer to size of expected message
  uint8_t buf[13]; 
  uint8_t buflen = sizeof(buf);

  // This rev function first checks the length of the incoming message &
  // if its true with the defined length then the message is copied to
  // buf variable and the function returns "True"
  if(rf_driver.recv(buf, &buflen)) {
    // On entering this block the sketch prints the message in the
    // serial window
    Serial.print("Data Received: ");
    Serial.println((char*)buf);
  }

}
