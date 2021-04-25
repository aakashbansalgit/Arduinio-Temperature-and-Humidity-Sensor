#include <SoftwareSerial.h> 
#include "DHT.h"
 
#define DHTPIN 12    
 
#define DHTTYPE DHT11   // DHT 11 
 
DHT dht(DHTPIN, DHTTYPE);
 
char inchar; 
 
SoftwareSerial blue(7, 8); 
 
String TextForSms ;
String humidity = " Humidity: %";
String temperature = "   Temperature";
String sign = " *C";
 
int powerb = 6;
 
void setup() {
 
   Serial.begin(9600);
  blue.begin(9600); // original 19200
    pinMode(powerb, OUTPUT); 
  digitalWrite(powerb, HIGH); 
   dht.begin();
 
  
}
 
 
void loop() {
 
if(blue.available() == 0);
 
  if(blue.available() >0)
  {
 
    inchar=blue.read(); 
  Serial.println(inchar);
    delay(20);
    if (inchar=='v')
    {
      delay(10);
 
   Serial.println(inchar);
    
  delay(2000);
 
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  int f = dht.readTemperature(true);
  
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
 
  int hi = dht.computeHeatIndex(f, h);

  
  TextForSms = TextForSms + "HUMIDITY: ";
  TextForSms.concat(h);
  TextForSms = TextForSms + "%    TEMPERATURE: ";
  TextForSms.concat(t);
  TextForSms = TextForSms + "*C";
   blue.print(TextForSms);
  Serial.println(TextForSms);
  delay(2000);
  TextForSms = " ";
    }

}
}
