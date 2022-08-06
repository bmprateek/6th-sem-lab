#include <DHT.h>  // Including library for dht
 
#include <ESP8266WiFi.h>
 
String apiKey = "WT2OUNUFFV33LYN4";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "G";     // replace with your wifi ssid and wpa2 key
const char *pass =  "";
const char* server = "api.thingspeak.com";
 
#define DHTPIN 2          //pin where the dht11 is connected
 
DHT dht(DHTPIN, DHT11);
 int input_val = 0;  // Varible to store Input values

WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
//       delay(10);
       dht.begin();
 
      Serial.println("Connecting to ");
      Serial.println(ssid);
 
// 
      WiFi.begin(ssid, pass);
// 
      while (WiFi.status() != WL_CONNECTED) 
    {
            delay(500);
            Serial.print(".");
    }
      Serial.println("");
      Serial.println("WiFi connected");

}
 const int LDR = A0; // Defining LDR PIN 

void loop() 
{
  
      float h = dht.readHumidity();
      float t = dht.readTemperature();
                   input_val = analogRead(LDR);      // Reading Input
                if (input_val < 250){
                   Serial.print("Humidity is :");
                   Serial.println(h);
                  Serial.print("Temperature is :");
                   Serial.println(t);
                Serial.println("uploading");
                delay(1000);
                        if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {       String postStr = apiKey;
                              postStr +="&field1=";
                              postStr += String(t);
                              postStr +="&field2=";
                               postStr += String(h);
                               postStr += "\r\n\r\n";

                              client.print("POST /update HTTP/1.1\n");
                               client.print("Host: api.thingspeak.com\n");
                              client.print("Connection: close\n");
                              client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                              client.print("Content-Type: application/x-www-form-urlencoded\n");
                              client.print("Content-Length: ");
                              client.print(postStr.length());
                              client.print("\n\n");
                              client.print(postStr);

                              Serial.print("Temperature: ");
                              Serial.print(t);
                              Serial.print(" degrees Celcius, Humidity: ");
                              Serial.print(h);
                              Serial.println("%. Send to Thingspeak.");
                        }
                        client.stop();
                        Serial.println("Waiting...");
  
  // thingspeak needs minimum 15 sec delay between updates
                        delay(1000);
                }
}