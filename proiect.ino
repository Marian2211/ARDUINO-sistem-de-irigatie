#include <LiquidCrystal.h> 
#include <DHT.h> 
#define DHTPIN A0 
#define DHTTYPE DHT11 
#define LED1 13 
#define senzorSol A1 
#define RELE_PIN 8 // Pinul digital pe care este conectat pinul de control al releului 
DHT dht(DHTPIN, DHTTYPE); 
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2; 
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); 
float f=0; 
float h=0; 
float moisture_percentage=0; 
void setup() { 
lcd.begin(16, 2); 
dht.begin(); 
pinMode(RELE_PIN, OUTPUT); 
digitalWrite(RELE_PIN, LOW); // Inițial, dezactivează releul 
lcd.print("Humidity: Temp:"); 
} 
void loop() { 
delay(500); 
lcd.setCursor(0, 1); 
f = dht.readTemperature(); 
h = analogRead(senzorSol); 
moisture_percentage = (100 - ((h / 1023.00) * 100)); 
if (moisture_percentage < 20) { 
if(f<30 || isnan(f) ) 
{ 
digitalWrite(13, HIGH); // Activează LED-ul 
digitalWrite(RELE_PIN, HIGH); // Activează releul (și implicit pompa de apă) 
lcd.begin(16, 2); 
lcd.setCursor(0,0);
lcd.print("Pompa activa"); 
} 
else 
{ 
digitalWrite(13, LOW); // Dezactivează LED-ul 
digitalWrite(RELE_PIN, LOW); // Dezactivează releul (și implicit pompa de apă) 
lcd.begin(16, 2); 
lcd.print("Humidity: !Temp:"); 
lcd.setCursor(0, 1); 
lcd.print(moisture_percentage); 
lcd.setCursor(10, 1); 
lcd.print(f); 
} 
} else { 
digitalWrite(13, LOW); // Dezactivează LED-ul 
digitalWrite(RELE_PIN, LOW); // Dezactivează releul (și implicit pompa de apă) 
lcd.begin(16, 2); 
lcd.print("Humidity: Temp:"); 
lcd.setCursor(0, 1); 
lcd.print(moisture_percentage); 
lcd.setCursor(10, 1); 
lcd.print(f); 
} 
} 
