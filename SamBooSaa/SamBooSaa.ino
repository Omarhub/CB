float    i = 0;
int relay1 = 7;
int relay2 = 8;
int relay3 = 9;

#include <dht.h>
dht DHT;
#define DHT11_PIN 2

int source5v = 46;

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  // put your setup code here, to run once:
  pinMode(source5v, OUTPUT);
  digitalWrite(source5v, HIGH);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  pinMode(relay3, OUTPUT);
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH) ;
  digitalWrite(relay3, HIGH);

  
  
  
  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  
  Serial.begin(9600);
  Serial.print("test_37");
  Serial.setTimeout(10);
  while(Serial.available() ==0) {}
  i = Serial.parseFloat();


}

void loop() {
  // put your main code here, to run repeatedly:
  // when connected to Normally closed HIGH is OFF
 /* 
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, LOW) ;
  digitalWrite(relay3, HIGH);
  delay(3000);

  digitalWrite(relay1, LOW) ;
  digitalWrite(relay2, HIGH);
  digitalWrite(relay3, LOW) ;
  delay(3000);

*/
/*
  digitalWrite(relay1, HIGH); 
  digitalWrite(relay2, HIGH) ;
  digitalWrite(relay3, HIGH);
  */
  double chk = DHT.read11(DHT11_PIN);
  
  lcd.backlight();
  lcd.setCursor(0,0);  // (col,row)
  lcd.print("now Temp=");
  
  lcd.setCursor(11,0);
  lcd.print(DHT.temperature);
  
  
  lcd.setCursor(0,1);
  lcd.print("user Temp=");
  lcd.setCursor(11,1);
  lcd.print(i);
  
  Serial.print("i = ");
  Serial.println(i);
  delay(1000);

  if (i<DHT.temperature) {
    Serial.println("test_85");
    digitalWrite(relay1, LOW);
    digitalWrite(relay2, LOW);
    /*
    delay(3000);
    digitalWrite(relay1, HIGH);
    delay(3000);
    */

    }
  else if (i<DHT.temperature) {
 /*   Serial.println("test_93");
 
  digitalWrite(relay2, LOW);
    delay(3000);
    digitalWrite(relay2, HIGH);
    delay(3000); 
    */
  }

    else {
      Serial.println("test_101");
      digitalWrite(relay1, HIGH);
      digitalWrite(relay1, HIGH);
    
    /*  
    digitalWrite(relay3, LOW);
    delay(3000);
    digitalWrite(relay3, HIGH);
    delay(3000); */

      }
  
  
  
}
