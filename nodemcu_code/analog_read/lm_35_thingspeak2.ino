
#include <ESP8266WiFi.h> // ESP8266WiFi.h library


const char* ssid     = ":001";
const char* password = "onidaonida";
const char* host = "api.thingspeak.com";
const char* writeAPIKey = "E07TPOGXVY5L2GCK";


void setup() {


//  Connect to WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void loop() {
 int analog=analogRead(A0);
 float temp=analog*0.322265625;

// make TCP connections
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    return;
  }

  String url = "/update?key=";
  url+=writeAPIKey;
  url+="&field1=";
  url+=String(temp);
  url+="\r\n";
  
  // Request to the server
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" + 
               "Connection: close\r\n\r\n");
    delay(100);
}
