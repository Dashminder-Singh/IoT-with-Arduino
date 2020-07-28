const int button1 = 7, button2 = 8, button3 = 12, button4 = 13;  
const int led1 =  10, led2 =  6,led3 =  9,led4 =  11;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(button1, INPUT);
  
  pinMode(led2, OUTPUT);
  pinMode(button2, INPUT);
  
  pinMode(led3, OUTPUT);
  pinMode(button3, INPUT);
  
  pinMode(led4, OUTPUT);
  pinMode(button4, INPUT);
  
}

int but1Press=0,but2Press=0,but3Press=0,but4Press=0;
void loop()
{     //for button 4
  
  if(digitalRead(button4)== HIGH)
  {
    if (but4Press==1) 
    {
      but4Press=0;
    }else {
      but4Press=1;
    }
    while (digitalRead(button4)== HIGH ); 
  }
    if (but4Press == 1)
    {
    digitalWrite (led4 , HIGH);
    }else 
    {
    digitalWrite (led4, LOW);
    }
  
  //for button 3
  if(digitalRead(button3)== HIGH)
  {
    if (but3Press==1)
    {
      but3Press=0;
    }else
    {
      but3Press=1;
    }
    while (digitalRead(button3)== HIGH );
  }
  
  if (but3Press==1)
  {
    digitalWrite(led3 , HIGH); 
  } else 
  {
    digitalWrite(led3 , LOW); 
  }
  
//for button2
 if(digitalRead(button2)== HIGH)
  {
    if (but2Press==1)
    {
      but2Press=0;
    }else
    {
      but2Press=1;
    }
    while (digitalRead(button2)== HIGH );
  }
  
  if (but2Press==1)
  {
    digitalWrite(led2 , HIGH); 
  } else 
  {
    digitalWrite(led2 , LOW); 
  }
  
//for button1

if(digitalRead(button1)== HIGH)
  {
    if (but1Press==1)
    {
      but1Press=0;
    }else
    {
      but1Press=1;
    }
    while (digitalRead(button1)== HIGH );
  }
  
  if (but1Press==1)
  {
    digitalWrite(led1 , HIGH); 
  } else 
  {
    digitalWrite(led1 , LOW); 
  }
  
}
