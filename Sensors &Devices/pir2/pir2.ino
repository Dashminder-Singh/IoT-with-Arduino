int pir1=2;
int value=0;
int pirstate=LOW;

void setup() 
{
  pinMode(pir1,INPUT);
  Serial.begin(9600);
}

void loop() 
{
 value=digitalRead(pir1);

      if(value==HIGH)
      {
        if(pirstate==LOW)
      {
        Serial.println("Motion is detected"); 
        pirstate=HIGH;  
    
      }
    }
    else
    {
      if(pirstate==HIGH)
      {
 
        Serial.println("Motion ended");
        pirstate=LOW;
      }

    }
}
