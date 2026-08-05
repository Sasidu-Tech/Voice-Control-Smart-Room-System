//Author :_ Sasidu Wishshanka

#include <DHT.h>
#include "BluetoothSerial.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP32Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

BluetoothSerial SerialBT;

Servo myServo;

#define FAN 19
#define LED 23


#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

float Tempurature;
float Humidity;
 
void setup() {

  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Voice Control");

  lcd.setCursor(0,1);
  lcd.print("Smart Room");

  delay(3000);


  dht.begin();

  Serial.begin(115200);
  SerialBT.begin("ESP32_BT");

  myServo.attach(14);
  myServo.write(80);

  pinMode(FAN, OUTPUT);
  pinMode(LED,OUTPUT);
  pinMode(DHTPIN,INPUT);
  

  readDHT();
  displayTempHum();

  delay(3000);
}

void loop() {

  readDHT();
  voiceCommand();


  delay(100);



  }

  
  
void voiceCommand(){
  
  if (SerialBT.available()) {

    String cmd = SerialBT.readStringUntil('\n');
    cmd.trim();

    lcd.clear();

    if (cmd.equalsIgnoreCase("fan on")) {
      digitalWrite(FAN, HIGH);
      SerialBT.println("FAN ON");

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Fan ON");


    }

    if (cmd.equalsIgnoreCase("fan Of")) {
      digitalWrite(FAN, LOW);
      SerialBT.println("FAN OFF");

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("Fan OFF");
    }

    if (cmd.equalsIgnoreCase("light on")){
      digitalWrite(LED,HIGH);
      SerialBT.println("ROOM LIGHT ON");

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("ROOM LIGHT ON");
    }

    if (cmd.equalsIgnoreCase("light of")){
      digitalWrite(LED,LOW);
      SerialBT.println("ROOM LIGHT OFF");

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("ROOM LIGHT OFF");
    }

    if (cmd.equalsIgnoreCase("open window")){
      for (int pos = 80; pos >= 20; pos--) {
      myServo.write(pos);
      delay(20);
      }
      SerialBT.println("WINDOW OPEN");

      lcd.clear();

      lcd.setCursor(0,0);
      lcd.print("WINDOW OPEN");
    }

    if(cmd.equalsIgnoreCase("close window")){
      for (int pos = 20; pos <= 85; pos++) {
      myServo.write(pos);
      delay(20);
      }
     SerialBT.println("WINDOW CLOSE");

     lcd.clear();

     lcd.setCursor(0,0);
     lcd.print("WINDOW CLOSE");
    }
    delay(2000);
    displayTempHum();  
  }  

  
}

void readDHT(){

  
  Tempurature =dht.readTemperature();
  Humidity    =dht.readHumidity();

  if(isnan(Humidity) || isnan(Tempurature)){
    Serial.println("Sensor error");
    return;
 }
}

void displayTempHum(){

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(Tempurature);
  lcd.print(" C");


  lcd.setCursor(0,1);
  lcd.print("Hum:");
  lcd.print(Humidity);
  lcd.print(" %");

}


