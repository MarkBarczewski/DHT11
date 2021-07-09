#include "DHT.h"          
 
#define DHTPIN 2          
#define DHTTYPE DHT11    
 
DHT dht(DHTPIN, DHTTYPE); 
 
void setup()
{
  Serial.begin(9600);    
  dht.begin();           
}
 
void loop()
{
 
  float t = dht.readTemperature();
  float h = dht.readHumidity();
 
  
  if (isnan(t) || isnan(h))
  {
    
    Serial.println("Blad odczytu danych z czujnika");
  } else
  {
    // Jeśli tak, wyświetlamy wyniki pomiaru
    Serial.print("Wilgotnosc: ");
    Serial.print(h);
    Serial.print(" % ");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
}
