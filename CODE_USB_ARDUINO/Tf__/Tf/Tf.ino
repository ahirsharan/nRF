#include "Arduino.h"
#include <SPI.h>
#include <RF24.h>
RF24 radio(7, 8);

const uint64_t pipe= 0xFFFFFFFFFFLL;

void setup() {
  Serial.begin(9600);
  Serial.println("THIS IS THE TRANSMITTER CODE - YOU NEED THE OTHER ARDIUNO TO SEND BACK A RESPONSE");
  
  radio.begin();

  
  radio.setPALevel(RF24_PA_MIN);

  
  radio.setDataRate(RF24_2MBPS);

  radio.setChannel(1);

  radio.openWritingPipe(pipe);
 

  randomSeed(analogRead(A0));
}

void loop() 
{

  unsigned char data = random(0, 254);
    
  radio.stopListening(); 
  radio.write(&data,sizeof(data));
  Serial.print("Sent: ");
  Serial.println(data);
  
  delay(1000);
}
