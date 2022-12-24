#include "DHT.h"
#define DHTPIN 12     // what pin we're connected to


#define DHTTYPE DHT11

#define pwm 9

// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));

  dht.begin();
  analogWrite(pwm, 255);
}
void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  Serial.print(F(" Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("C "));
   if(t<32)
    { 
      analogWrite(pwm,0);
      Serial.println("Fan OFF            ");
      delay(100);
    }
    
    else if(t>32 && t<=34)
    {             
      analogWrite(pwm, 75);
      Serial.println("Fan Speed: 20%   ");
      delay(100);
    }
    
     else if(t>34 && t<=36)
    {
      analogWrite(pwm, 102);
      Serial.println("Fan Speed: 40%   ");
      delay(100);
    }
    
     else if(t>36 && t<=38)
    {
      analogWrite(pwm, 153);
      Serial.println("Fan Speed: 60%   ");
      delay(100);
    }
    
    else if(t>38 && t<=40)
    {
      analogWrite(pwm, 204);
      
      Serial.println("Fan Speed: 80%    ");
      delay(100);
    }
     else if(t>40)
    {
      analogWrite(pwm, 255);
      Serial.println("Fan Speed: 100%   ");
      delay(100);
    } 
  delay(3000);
}


