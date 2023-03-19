#include <Adafruit_BME280.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7); //configura los pines del shield

#define SEALEVELPRESSURE_HPA (1029)

Adafruit_BME280 bme; // I2C para usar solamente cuatro pines del sensor

void setup() {
    bme.begin();    

    lcd.begin(16,2);
}

void loop() { 
    lcdPrint();         
}

void lcdPrint(){    
    String temp = ("Temp: " + String(bme.readTemperature()) + ((char) 223) + "C");
    String hum = ("Hum: " + String(bme.readHumidity()) + "%");
    String pres = ("   Pres: " + String(bme.readPressure() / 100.0F) + "hPa");
    String alt = ("     Alt: " +String(bme.readAltitude(SEALEVELPRESSURE_HPA)) + "m.s.n");
    
    lcd.setCursor(1,0);
    lcd.print(temp + pres);    
    //Aqui se escribe en la segunda linea del display
    lcd.setCursor(1,1);
    lcd.print(hum + alt);
    //Aqui se realiza el scroll del display
    lcd.setCursor(16,1);
    lcd.scrollDisplayLeft();
    delay(900); 
}
