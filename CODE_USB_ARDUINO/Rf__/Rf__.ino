#include "Arduino.h"
#include <SPI.h>
#include <RF24.h>


RF24 radio(7, 8);
const uint64_t pipe= 0xFFFFFFFFFFLL;
void setup() {
  Serial.begin(9600);
  Serial.println("THIS IS THE RECEIVER CODE - YOU NEED THE OTHER ARDUINO TO TRANSMIT");
  radio.begin();

  radio.setPALevel(RF24_PA_MIN); 
  radio.setDataRate(RF24_2MBPS);
  radio.setChannel(1);
  radio.openReadingPipe(1,pipe);
  radio.startListening();
}


void loop() 
{

  unsigned char data; 
  if ( radio.available()) {
   
    while (radio.available()) 
    {
       radio.read( &data, sizeof(char));
       Serial.print("Received response ");
       Serial.println(data);
    }
  }
}
