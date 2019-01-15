#include "Arduino.h"
#include <SPI.h>
#include <RF24.h>
RF24 radio(53,48);
int R,C;
int i,j,size=0,m=0;
byte Matrix[5800];
byte addresses[][6] = {"1Node", "2Node"}; 
          

void setup() {
  Serial.begin(9600);
  Serial.println("THIS IS THE TRANSMITTER CODE - YOU NEED THE OTHER ARDUINO TO SEND BACK A RESPONSE");
  
  radio.begin();

  radio.setPALevel(RF24_PA_MAX);

  radio.setDataRate(RF24_2MBPS);

  radio.setChannel(124);
 
  radio.openWritingPipe(addresses[1]);
  radio.openReadingPipe(1, addresses[0]);
  Serial.setTimeout(50000000);

}

void loop() 
{
  
  Serial.println("Enter row and column count:");
  while(Serial.available()==0){}
   R=Serial.parseInt();
   C=Serial.parseInt();

   
  Serial.println("Enter Image Matrix(Binary): ");
  for(i=0;i<R;i++)
  {
     for(j=0;j<C;j++)
   {
    while(Serial.available()==0);
       Matrix[m]=Serial.parseInt(); 
      m++;   
  }    
  }
  m=0;
  Serial.println("Image Entered and Sent is:");
  for(i=0;i<R;i++)
  {
     for(j=0;j<C;j++)
     {Serial.print(Matrix[m]);
     m++;}
       Serial.println("");
  } 
  Serial.println("Please wait for 20 seconds!");
  size=m;
  Matrix[size]=R;
  Matrix[size+1]=C;
  m=0;
  
   while(1)
    {
     radio.stopListening();
     radio.write(&Matrix[m],sizeof(byte));    
     m++;  
    if(m==size+2)
     exit(0);
    }
     
  }
 

