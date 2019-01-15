#include "Arduino.h"
#include <SPI.h>
#include <RF24.h>
int p=0;
int x;
unsigned int l1,l2;
RF24 radio(53,48);
int i=0,j=0,m=0,size1=0,size2=-1,c=-1,k=0,f=0;
byte data[5800];
byte addresses[][6] = {"1Node","2Node"};
void setup() 
{
  Serial.begin(9600);

  Serial.println("THIS IS THE RECEIVER CODE - YOU NEED THE OTHER ARDUINO TO TRANSMIT");
  radio.begin();

  radio.setPALevel(RF24_PA_MAX);

  
  radio.setDataRate(RF24_2MBPS);

  radio.setChannel(124);

  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1, addresses[1]);
  radio.startListening();
 
}


void loop() 
{ 
    
      l1=millis();
     while(!radio.available() && p!=1)
     {
        l2=millis();
       if(l2-l1 >20000)
          p=1;
      }
     
     while(radio.available()) 
            { 
           
              radio.read(&(data[m]),sizeof(byte));
               m++;
               if(m%8==0)
                  radio.flush_rx();            
             }
       
         
    if(p==1)              
{ 
   Serial.println("Image Received:"); 
 
 for(i=0;i<data[m-2];i++)
  {for(j=0;j<data[m-1];j++)
    {Serial.print(data[f]);
    f++;
    }
   Serial.println("");
  }
  
 delay(10000000);  
}     
 
 }

