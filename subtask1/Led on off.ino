boolean ledstate=LOW;
int buttonswitch=10;
boolean buttonlast=LOW;
int led=4;
boolean buttoncurrent=LOW;
boolean debounce(boolean buttonlast)
{
 boolean current=digitalRead(buttonswitch);
 if(current==HIGH && buttonlast==LOW)
 {
   delay(5);
   current=digitalRead(buttonswitch);
 }
  return current;
}

void setup() {
pinMode(led,OUTPUT);
pinMode(buttonswitch,INPUT);
}

void loop() 
{
  buttoncurrent=debounce(buttonlast);
  if(buttoncurrent==HIGH && buttonlast==LOW)
  {
    ledstate=!ledstate;
  }
  buttonlast=buttoncurrent;
  digitalWrite(led,ledstate);

}










