float i = 0;

int  b = 0;
//#include <dht.h>

//dht DHT;
//#define DHT11_PIN 2

// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>

/********************************************************************/
// Data wire is plugged into pin 2 on the Arduino 
#define ONE_WIRE_BUS 2 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  

// (not just Maxim/Dallas temperature ICs) 

OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 

DallasTemperature sensors(&oneWire);
/********************************************************************/

int source5v = 46;



//#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  pinMode(source5v, OUTPUT);
  digitalWrite(source5v, HIGH);
  

  
  lcd.init();                      // initialize the lcd 
  lcd.init();
  
  Serial.begin(9600);
  //Serial.setTimeout(10);

// Start up the library 
 sensors.begin(); 
  
  //while(Serial.available() ==0) {}
  //i = Serial.parseFloat();


  
    } 



void loop() {
  // put your main code here, to run repeatedly:
  
  
  
  //double chk = DHT.read11(DHT11_PIN);

  sensors.requestTemperatures(); // Send the command to get temperature readings 
  
  lcd.backlight();
  lcd.setCursor(0,0);  // (col,row)
  lcd.print("now Temp=");
  
  lcd.setCursor(9,0);
  lcd.print(sensors.getTempCByIndex(0)); // Why "byIndex"?  
   // You can have more than one DS18B20 on the same bus.  
   // 0 refers to the first IC on the wire 
   delay(1000);
  
  /*
  lcd.setCursor(0,1);
  lcd.print("user Temp=");
  lcd.setCursor(11,1);
  lcd.print(i);
  
  Serial.print("i = ");
  Serial.println(i);
  delay(1000);

*/

}
