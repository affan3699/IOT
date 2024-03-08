#include <WiFi.h>
#include "time.h"
const char* ssid = "I-Consult-2_5G";
const char* password = "Consult@321";
const char* ntpServer = "pool.ntp.org";
const long gmtoffset_sec = 18000; /*GMT OFFSET +5 HOURS (18000 SEC)*/
const int daylightoffset_sec = 3600; /*1 hour daylight offset*/
void printLocalTime()
{
struct tm timeinfo;
if(!getLocalTime (&timeinfo)) {
Serial.println("Failed to obtain time");
return;
}

Serial.println (&timeinfo, "%A, %B %d %Y %H:%M:%S");
} 
void setup()
{
Serial.begin(115200);
//connect to Mii
Serial.printf("Connecting to %s", ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println(" CONNECTED");
//init and get the time
configTime(gmtoffset_sec, daylightoffset_sec, ntpServer);
printLocalTime();
//disconnect ii as it's no longer needed
WiFi.disconnect(true);
WiFi.mode(WIFI_OFF);

}
void loop()
{
delay(1000);
printLocalTime();
}