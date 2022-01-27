#define Trig_Pin 3
#define Echo_Pin 2
#define led1 12
#define led2 11
#define led3 10
#define led4 6
#define led5 5
#define led6 4
float distance,duration;
float Max_dist=400;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(Trig_Pin,OUTPUT);
  pinMode(Echo_Pin,INPUT);
}
 
void loop()
{
 Serial.begin(9600); 
 digitalWrite(Trig_Pin,LOW);
 delayMicroseconds(2);
 digitalWrite(Trig_Pin,HIGH);
 delayMicroseconds(10);
 digitalWrite(Trig_Pin,LOW);
 duration=pulseIn(Echo_Pin,HIGH);
 distance=(duration/2)*0.0343;
 if(distance>=0 && distance<=(Max_dist/6))
  {digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);}
 if(distance>(Max_dist/6) && distance<=(2*Max_dist/6))
  {digitalWrite(led2,HIGH);
 digitalWrite(led1,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);}
 if(distance>(2*Max_dist/6) && distance<=(3*Max_dist/6))
  {digitalWrite(led3,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);}
 if(distance>(3*Max_dist/6) && distance<=(4*Max_dist/6))
 {digitalWrite(led4,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led6,LOW);}
 if(distance>(4*Max_dist/6) && distance<=(5*Max_dist/6))
  {digitalWrite(led5,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led6,LOW);}
 if(distance>(5*Max_dist/6) && distance<=(6*Max_dist/6))
  {digitalWrite(led6,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);
  digitalWrite(led3,LOW);} 
  Serial.print(distance);
}