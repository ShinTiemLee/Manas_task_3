#include<Servo.h>
Servo smot;
int smotpin=3;
int pot=0;
int b1=2;	
int b2=12;
int ena1=5,in1=9,in2=10;
boolean b1_last=LOW,b2_last=LOW,b1_current=LOW,b2_current=LOW;
boolean flag1=LOW,flag2=LOW;
int val,dspeed,sspeed;

boolean debounce1(boolean b1_last)
{
  b1_current=digitalRead(b1);
  if (b1_current==HIGH && b1_last==LOW)
  delay(5);
 b1_current=digitalRead(b1);
  return b1_current;
}

boolean debounce2(boolean b2_last)
{
  b2_current=digitalRead(b2);
  if (b2_current==HIGH && b2_last==LOW)
  delay(5);
 b2_current=digitalRead(b2);
  return b2_current;
}

void dmot()
{ 
  b2_current=debounce2(b2_last);
  if(b2_current==HIGH && b2_last==LOW)
   {
      flag2=!flag2;
   }
    digitalWrite(in1,flag2);
    digitalWrite(in2,(!flag2));
    analogWrite(ena1,dspeed);
    b2_last=b2_current;
}

void sermot()
{
  for(int i=0;i<=180;i+=20)
    {smot.write(i);
      delay(200);
      delay(sspeed);
    }
}

void setup()
{
  pinMode(b1,INPUT);
  attachInterrupt(digitalPinToInterrupt(b1),loop,CHANGE);
  pinMode(b2,INPUT);
  pinMode(ena1,OUTPUT);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  smot.attach(smotpin);
}

void loop()
{
  val=analogRead(pot);
  dspeed=map(val,0,1023,1,255);
  sspeed=map(val,0,1023,255,0);
  b1_current=debounce1(b1_last);
  if(b1_current==HIGH && b1_last==LOW)
  { 
    flag1=!flag1;
  }
   if(flag1==HIGH)
   {
     smot.write(0);
     dmot();
   }
   else
   {
     analogWrite(ena1,LOW);
     sermot();
   }
  b1_last=b1_current;
}