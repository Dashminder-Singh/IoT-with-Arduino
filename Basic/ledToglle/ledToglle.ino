int but1=8;
int led1=6;
void setup() 
{
  pinMode (but1,INPUT);
  pinMode (led1,OUTPUT); 
}
int butpressed=0;
void loop()
{   if(digitalRead(but1)==HIGH)
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
     }else
    {
     digitalWrite(led1,LOW);  
    }
  }
