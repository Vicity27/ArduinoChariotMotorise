int M1DIR = 4; 
int M1PWM = 5; 
int M2DIR = 7; 
int M2PWM = 6; 
#define potPin A0
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;


void setup() {
  pinMode(M1DIR, OUTPUT);
 pinMode(M1PWM, OUTPUT);
 pinMode(M2DIR, OUTPUT);
 pinMode(M2PWM, OUTPUT);
  pinMode(4, INPUT);
  pinMode(7, INPUT);
  Serial.begin(9600);
  pinMode(potPin, INPUT);
 
}

void loop() {
  int a ;
  int b ;
  int d = 0;
  a = digitalRead (4);
  b = digitalRead (7);
  d = analogRead(potPin);
  int pwm = map(d,0,1023,0,255);
 analogWrite(M1PWM, 0);
  analogWrite(M2PWM, 0);
 
Serial.println(analogRead(potPin));

  if (a==1)
    {
     analogWrite(M1PWM,pwm);
     analogWrite(M2PWM,pwm);
     delay(200);
  
     lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("    AVANCER ");
    lcd.setCursor(0,1);
    lcd.print(" Vitesse = "); 
    lcd.print(pwm/45);
    lcd.print("Km/h");
   
 
    }

 if (b==1)
    {
     analogWrite(M1PWM,pwm);
     analogWrite(M2PWM,pwm);
      digitalWrite(M1DIR,1);
     digitalWrite(M2DIR,1);
     delay(200);
   
     lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("    RECULER ");
    lcd.setCursor(0,1);
    lcd.print(" Vitesse = "); 
    lcd.print(pwm/32);
    lcd.print("Km/h");
 
    }
 if((b!=1) && (a!=1))
    {
      lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("     Bug");
    delay(200);
    analogWrite(M1PWM,0);
  analogWrite(M2PWM,0);
    
    }
   
   // digitalWrite (3 , HIGH);
   // delay (2000);
   // digitalWrite(3, LOW);
   //delay (2000);
}
