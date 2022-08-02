//Kartu putih 12512812555
//Gantungan kunci 5111823129

#include<SPI.h>
#include<MFRC522.h>
#include <Servo.h>

Servo servo;
int sudut=0;

const int pin_ss=10;
const int pin_rst=9;
const int pin_sp=8;

const int triger = A1;
const int echo = A2;

const int IR1 = 2;
const int IR2 = 3;

const int led1M = 4;
const int led1H = 5;
const int led2M = 6;
const int led2H = 7;

MFRC522 rfid(pin_ss,pin_rst);

void setup() {
  Serial.begin(9600);
  pinMode(triger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(led1M, OUTPUT);
  pinMode(led1H, OUTPUT);
  pinMode(led2M, OUTPUT);
  pinMode(led2H, OUTPUT);
  servo.attach(8);
  SPI.begin();
  rfid.PCD_Init();
  servo.write(90);
}

void loop() {
  int hasilIR1 = digitalRead(IR1);
  int hasilIR2 = digitalRead(IR2);
  Serial.println("IR1:"+String(hasilIR1)+" || IR2:"+String(hasilIR2));
  if(hasilIR1==0){
    digitalWrite(led1M,HIGH);
    digitalWrite(led1H,LOW);
  }
  if(hasilIR1==1){
    digitalWrite(led1H,HIGH);
    digitalWrite(led1M,LOW);
  }
  if(hasilIR2==0){
    digitalWrite(led2M,HIGH);
    digitalWrite(led2H,LOW);
  }
  if(hasilIR2==1){
    digitalWrite(led2H,HIGH);
    digitalWrite(led2M,LOW);
  }
  
  digitalWrite(triger,HIGH);
  delay(10);
  digitalWrite(triger,LOW);
  double data = pulseIn(echo,HIGH);
  double jarak = 0.0343 *(data / 2);
  Serial.print(jarak);
  Serial.println("cm");
  delay (200);
  if (jarak < 5)
  {
    servo.write(90);
  }

  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    return;
  }
  String id;
  id=String(rfid.uid.uidByte[0]) + String(rfid.uid.uidByte[1]) + String(rfid.uid.uidByte[2]) + String(rfid.uid.uidByte[3]);
  Serial.print("ID Anda: ");
  Serial.println(id);

  if(id=="12512812555" || "5111823129"){
    servo.write(180);
  }
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();  
  

}

void bacaServo(){
  digitalWrite(triger,HIGH);
  delay(10);
  digitalWrite(triger,LOW);
  double data = pulseIn(echo,HIGH);
  double jarak = 0.0343 *(data / 2);
  Serial.print(jarak);
  Serial.println("cm");
  delay (500);
}
