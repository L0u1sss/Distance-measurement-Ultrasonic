#include<UltraDistSensor.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

UltraDistSensor sensor;
float centimeter;
float inch;

void setup() {
    pinMode(A0,OUTPUT);
    lcd.init();
    lcd.backlight();
    Serial.begin(9600);
    sensor.attach(12,13);
}

void loop() {
    centimeter=sensor.distanceInCm();
    inch=sensor.distanceInInch();
    if(((centimeter>=100)&&(centimeter<=110))||((centimeter>=200)&&(centimeter<=210))||((centimeter>=300)&&(centimeter<=310))||((centimeter>=400)&&(centimeter<=410))){
    digitalWrite(A0,0);
      delay(500);
      digitalWrite(A0,1);
     }
    else{
    digitalWrite(A0,1);
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(inch);
    lcd.print("inches");
    lcd.setCursor(0,1);
    lcd.print(centimeter);
    lcd.print("centimeters");
    delay(1000);
}
