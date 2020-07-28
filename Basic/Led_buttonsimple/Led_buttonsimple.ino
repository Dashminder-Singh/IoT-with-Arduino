/*Buttons - 7,8,12,13
leds - 10,6,9,11*/

int but1=7;
int led1=10;
void setup() 
{
   pinMode(led1,OUTPUT) ;  
   pinMode(but1,INPUT) ;
}

void loop() 
{
  if (digitalRead (but1) == HIGH)
    {  
      digitalWrite (led1,HIGH);
    }
    else
      {
      digitalWrite (led1,LOW); 
     }
} 


   
