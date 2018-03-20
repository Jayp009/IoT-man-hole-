#include <ESP8266WiFi.h>

#define sensorinput 2 // water sensor 

const char* ssid     = "Yuvalay Elab";    // wifi ssid
const char* password = "elabyuvalay";     // wifi password

const char* host = "maker.ifttt.com";     // predefine host

int storeoutput;                          // to store and read pin data


void setup() {

  Serial.begin(115200);                   // Serial cummunication buad rate

  int storeoutput;                        // output store variable

  pinMode(sensorinput, INPUT);           // set pin as input pin
}

void loop() {

  storeoutput = digitalRead(sensorinput);

  if (storeoutput == HIGH) {            // if the condition is full fill then
    WiFi.begin(ssid, password);         // connecting to wifi
    while (WiFi.status() != WL_CONNECTED) {
      Serial.println("Conencting");      // print Conecting
      delay(500);
    }
    WiFiClient client;
    const int httpPort = 80;
    if (!client.connect(host, httpPort)) {
      Serial.println("Weak Network");
      return;
    }
    /////////////////////////////////////////// Email with key //////////////////////////////////

    // We now create a URI for the request
    String url1 = "/trigger/email/with/key/PLEvK7l37T895cS4P_e64bheN0gFurn5otleJgfvl6/";   //our link to trigger the event with special key and event name

    // This will send the request to the server
    client.print(String("GET ") + url1 + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n" + "\r\n");  // GET request

    Serial.println(storeoutput);
    Serial.println("check email");
    delay(10000);

    ////////////////////////////////////////////twitter with key ///////////////////////////////

    // We now create a URI for the request
    String url = "/trigger/twitter/with/key/PLEvK7l37T895cS4P_e64bheN0gFurn5otleJgfvl6/";   //our link to trigger the event with special key and event name

    // This will send the request to the server
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" + "Connection: close\r\n\r\n" + "\r\n");  // GET request

    Serial.println(storeoutput);
    Serial.println("check twitter");
    delay(10000);
    //////////////////////////////////////////////////////////////////////////////////////////

  }

  else {
  }

}
