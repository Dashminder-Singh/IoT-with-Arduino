#include<EEPROM.h>
int but1=8;
int led1=6;
int butpressed=0;
void setup() 
{
  pinMode (led1,OUTPUT);
  pinMode (but1,INPUT);
butpressed = EEPROM.read(9);
}

void loop()
{
  
  if(digitalRead(but1)==HIGH)
    {
      if(butpressed==1)
       butpressed=0;
       else  
       butpressed=1;
       while(digitalRead(but1)==HIGH);
   }
    if(butpressed==1)
    {
      digitalWrite (led1,HIGH);
      EEPROM.write(9,1);
     }else
    {
     digitalWrite(led1,LOW);  
     EEPROM.write(9,0);
    }
   }
