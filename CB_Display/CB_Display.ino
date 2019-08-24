float i = 0;
int  b = 0;
#include <dht.h>

dht DHT;
#define DHT11_PIN 2




int source5v = 46;



#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  pinMode(source5v, OUTPUT);
  digitalWrite(source5v, HIGH);
  

  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  
  Serial.begin(9600);
  Serial.setTimeout(10);
  while(Serial.available() ==0) {}
  i = Serial.parseFloat();


  
    } 



void loop() {
  // put your main code here, to run repeatedly:
  
  
  
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



}
