/*
 *  This sketch sends data via HTTP GET requests to data.sparkfun.com service.
 *
 *  You need to get streamId and privateKey at data.sparkfun.com and paste them
 *  below. Or just customize this script to talk to other HTTP servers.
 *
 */

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
const char* ssid     = "minionlabs";
const char* password = "minionlabs1";

const char* host = "192.168.0.110";   //eg: 192.168.0.222
float humidityData ;
float temperatureData ; 

WiFiClient client;
//const char* host = "data.sparkfun.com";
//const char* streamId   = "....................";
//const char* privateKey = "....................";

void setup() {
  Serial.begin(115200);
  delay(10);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {
  WiFiClient client;
  humidityData = 1.1;
  temperatureData = 2.2; 
  Sending_To_phpmyadmindatabase(); 
  delay(1000);

}
void Sending_To_phpmyadmindatabase()   //CONNECTING WITH MYSQL
 {
   if (client.connect(host, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    String url = "/testcode/dht.php";
    url += "?humidity=";
    url += humidityData;
    url += "&temperature=";
    url += temperatureData;
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                "Host: " + host + "\r\n" +
                "Connection: close\r\n\r\n");
    
//    Serial.print("GET /testcode/dht.php?humidity=");
//    client.print("GET /testcode/dht.php?humidity=");     //YOUR URL
//    Serial.println(humidityData);
//    client.print(humidityData);
//    client.print("&temperature=");
//    Serial.println("&temperature=");
//    client.print(temperatureData);
//    Serial.println(temperatureData);
//    client.print(" ");      //SPACE BEFORE HTTP/1.1
//    client.print("HTTP/1.1");
//    client.println();
//    client.println("Host: Your Local IP");
//    client.println("Connection: close");
//    client.println();
  } else {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
