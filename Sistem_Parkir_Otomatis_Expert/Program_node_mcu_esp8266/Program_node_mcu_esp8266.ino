#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "tnjgmUVMrVE7o8azAdhtw7eWRZ7b9yU1"; //Auth dari BLYNK di email anda
char ssid[] = "Nusantara"; //Nama wifi
char pass[] = "T4nahairku"; //Password wifi

#define IR1 D0
#define IR2 D1
#define IR3 D2
#define led1M D3
#define led1H D4
#define led2M D5
#define led2H D6
#define led3M D7
#define led3H D8
int IRValue1;
int IRValue2;
int IRValue3;
int pinValue1;
int pinValue2;
int pinValue3;
BlynkTimer timer;
BLYNK_WRITE(V1)
{
pinValue1 = param.asInt();
}
BLYNK_WRITE(V2)
{
pinValue2 = param.asInt();
}
BLYNK_WRITE(V3)
{
pinValue3 = param.asInt();
}

void setup(){
Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);
  pinMode(led1M, OUTPUT);
  pinMode(led1H, OUTPUT);
  pinMode(led2M, OUTPUT);
  pinMode(led2H, OUTPUT);
  pinMode(led3M, OUTPUT);
  pinMode(led3H, OUTPUT);
  }

void loop(){
  Blynk.run();
  timer.run();
  IRValue1 = digitalRead(IR1);
  if (pinValue1 == HIGH)
  {
    if (IRValue1==HIGH)
  {
      Blynk.virtualWrite(V1, 1);
  }
    if (IRValue1==LOW)
{
      Blynk.virtualWrite(V1, 0);
}}
  else{
    if (IRValue1==HIGH){
      Blynk.virtualWrite(V1, 1);
      }
      if (IRValue1==LOW)
      {
        Blynk.virtualWrite(V1, 0);
      } 
     }
     
  IRValue2 = digitalRead(IR2);
  if (pinValue2 == HIGH)
  {
    if (IRValue2==HIGH)
  {
      Blynk.virtualWrite(V2, 1);
  }
    if (IRValue2==LOW)
{
      Blynk.virtualWrite(V2, 0);
}}
  else{
    if (IRValue2==HIGH){
      Blynk.virtualWrite(V2, 1);
      }
      if (IRValue2==LOW)
      {
        Blynk.virtualWrite(V2, 0);
      } 
     }
  IRValue3 = digitalRead(IR3);
  if (pinValue3 == HIGH)
  {
    if (IRValue3==HIGH)
  {
      Blynk.virtualWrite(V3, 1);
  }
    if (IRValue3==LOW)
{
      Blynk.virtualWrite(V3, 0);
}}
  else{
    if (IRValue3==HIGH){
      Blynk.virtualWrite(V3, 1);
      }
      if (IRValue3==LOW)
      {
        Blynk.virtualWrite(V3, 0);
      } 
     }
  if(IRValue1==0){
    digitalWrite(led1M,HIGH);
    digitalWrite(led1H,LOW);
  }
  if(IRValue1==1){
    digitalWrite(led1H,HIGH);
    digitalWrite(led1M,LOW);
  }
  if(IRValue2==0){
    digitalWrite(led2M,HIGH);
    digitalWrite(led2H,LOW);
  }
  if(IRValue2==1){
    digitalWrite(led2H,HIGH);
    digitalWrite(led2M,LOW);
  }
  if(IRValue3==0){
    digitalWrite(led3M,HIGH);
    digitalWrite(led3H,LOW);
  }
  if(IRValue3==1){
    digitalWrite(led3H,HIGH);
    digitalWrite(led3M,LOW);
  }
}
