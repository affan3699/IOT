#include <WiFi.h>

const char* ssid = "YourHotspotSSID";
const char* password = "YourHotspotPassword";

void setup() {
  Serial.begin(115200);
  delay(1000);
  // Connect to WiFi network
  Serial.println();
  Serial.println("Connecting to WiFi network");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // Your code here
}
