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
MFRC522 rfid(pin_ss,pin_rst);

void setup() {
  Serial.begin(9600);
  pinMode(triger,OUTPUT);
  pinMode(echo,INPUT);
  servo.attach(8);
  SPI.begin();
  rfid.PCD_Init();
  servo.write(90);
}

void loop() {
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
    servo.write(180);
  }

  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    return;
  }
  String id;
  id=String(rfid.uid.uidByte[0]) + String(rfid.uid.uidByte[1]) + String(rfid.uid.uidByte[2]) + String(rfid.uid.uidByte[3]);
  Serial.print("ID Anda: ");
  Serial.println(id);

  if(id=="1502377987" || "633415211"){
    servo.write(90);
  }
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();  
  

}
