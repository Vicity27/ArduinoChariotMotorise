// 3,5,6 ports analogiques
// 2,4,7,8 port digitaux
int BOUTON2=2;
int BOUTON1=8;
int M1DIR = 4; 
int M1PWM = 5; 
int M2DIR = 7; 
int M2PWM = 6; 
int slider =0;
 
#define potPin A0
#include <Wire.h>
#include "rgb_lcd.h"
rgb_lcd lcd;


void setup() {
 pinMode(M1DIR, OUTPUT);
 pinMode(M1PWM, OUTPUT);
 pinMode(M2DIR, OUTPUT);
 pinMode(M2PWM, OUTPUT);
 

pinMode(BOUTON1,INPUT);
pinMode(BOUTON2,INPUT);
   
  Serial.begin(9600);
  pinMode(potPin, INPUT);
  
}

void loop() {
  int bouton1 =0;
  int bouton2 = 0 ;
  int d = 0;
  int curseur=0;
  
  int pwm1;
  int pwm2;
  curseur = analogRead(potPin);
  bouton1 = digitalRead(BOUTON1);
  bouton2 = digitalRead(BOUTON2);
  lcd.begin(16, 2);
    lcd.setCursor(0,0);
lcd.print(bouton1);
lcd.print(bouton2);
slider = 1 ;
  if (bouton1==1)
   {
    bouton2=0;
    pwm1 =255 ;
    pwm2 =0 ;
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("tourner a droite");
    delay (20);   
    slider =0 ;
   }
 if (bouton2==1)
   {
    bouton1=0;
    pwm2 =255 ;
    pwm1 =0 ;
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("tourner a gauche");
    delay (20);   
     slider =0 ;
   }
if (slider==1)
  {
  if (curseur<462)
    {
    digitalWrite(M1DIR, 1);
    digitalWrite(M2DIR, 1);
    pwm1 = map((462-curseur),0,462,0,255);
    pwm2 = map((462-curseur),0,462,0,255);
    }
  if (curseur>562)
    {
    digitalWrite(M1DIR, 0);
    digitalWrite(M2DIR, 0);
    pwm1 = map(curseur,562,1024,0,255);
    pwm2 = map(curseur,562,1024,0,255);
    } 
  if ((curseur>=462)&&(curseur<=562))
    {
    pwm1 = 0;
    pwm2 = 0;
    } 
  }     

  /*analogWrite(M1PWM, 0);
  analogWrite(M2PWM, 0);
  */
    /*lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("Cur ");
    lcd.print(curseur);
    lcd.print("Vit ");
    lcd.print(pwm);
    analogWrite(M1PWM,pwm);
    analogWrite(M2PWM,pwm);
    digitalWrite(3,LOW);
    digitalWrite(2,LOW);
   */
    analogWrite(M1PWM,pwm1);
    analogWrite(M2PWM,pwm2);
    
Serial.println(analogRead(potPin));
   
   // digitalWrite (3 , HIGH);
   // delay (2000);
   // digitalWrite(3, LOW);
   //delay (2000);
}
