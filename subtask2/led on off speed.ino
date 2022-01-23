int pot=0;
int led1=12,led2=11,led3=10,led4=9;
int button=13;
boolean buttonlast=LOW;
boolean buttoncurrent=LOW;
boolean flag=LOW;

boolean debounce(boolean last)
{
 buttoncurrent=digitalRead(button);
 if(buttoncurrent==HIGH && buttonlast==LOW)
  {
    delay(5);
    buttoncurrent=digitalRead(button);
  }
  return buttoncurrent;
}

void setup ()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(button,INPUT);
  pinMode(pot,INPUT);
}
void loop()
{
 int val=analogRead(pot);
 int speed=map(val,0,1023,255,0);
 buttoncurrent=debounce(buttonlast);
 if(buttoncurrent==HIGH && buttonlast==LOW)
 {
   flag=!flag;
  digitalWrite(led1,flag);
  delay(speed);
  digitalWrite(led2,flag);
  delay(speed);
  digitalWrite(led3,flag);
  delay(speed);
  digitalWrite(led4,flag);
  delay(speed);
 }
 buttonlast=buttoncurrent;
}