#include <WiFiClient.h> 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>
#define trig D2
#define echo D1

const char* ssid = "2.4"; // Your wifi Name       
const char* password = "0595277661";   // Your wifi Password

const char *host = "192.168.0.189";

int distance=0, t=0;

void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
   WiFi.mode(WIFI_OFF);        //Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        //This line hides the viewing of ESP as wifi hotspot
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  Serial.print("Connecting");
  

}

void loop() {
HTTPClient http;
  
  http.begin("http://138.168.0.189/Azzam/InsertDB.php");              //Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
 
  String payload = http.getString();    //Get the response payload

 
 digitalWrite(trig,LOW);
 delayMicroseconds(5);
 digitalWrite(trig,HIGH);
 delayMicroseconds(10);
 digitalWrite(trig,LOW);
 t=pulseIn(echo,HIGH);
 distance=t/57;
 Serial.println(distance);
 delay(500);

  


}
