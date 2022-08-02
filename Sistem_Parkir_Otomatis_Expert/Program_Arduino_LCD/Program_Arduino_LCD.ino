//Kartu putih 12512812555
//Gantungan kunci 5111823129

#include<SPI.h>
#include<MFRC522.h>
#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
char array1[] = "   SELAMAT DATANG";  // CHANGE THIS AS PER YOUR NEED 
char array2[] = " SILAKAN TEMPELKAN";     // CHANGE THIS AS PER YOUR NEED 
char array3[] = " KARTU RFID KALIAN";   // CHANGE THIS AS PER YOUR NEED
char array4[] = "    TERIMAKASIH";     // CHANGE THIS AS PER YOUR NEED
LiquidCrystal_I2C lcd(0x27, 20, 4); // CHANGE THE 0X27 ADDRESS TO YOUR SCREEN ADDRESS IF NEEDED
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
  servo.write(270);
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  
  lcd.print(array1);
  
  lcd.setCursor(0,1);
  lcd.print(array2);
  
  lcd.setCursor(0,2);
  lcd.print(array3);
  
  lcd.setCursor(0,3);
  lcd.print(array4);
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
    servo.write(270);
  }

  if(!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()){
    return;
  }
  String id;
  id=String(rfid.uid.uidByte[0]) + String(rfid.uid.uidByte[1]) + String(rfid.uid.uidByte[2]) + String(rfid.uid.uidByte[3]);
  Serial.print("ID Anda: ");
  Serial.println(id);

  if(id=="1502377987" || "633415211"){
    servo.write(180);
  }
  
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();  
  

}
