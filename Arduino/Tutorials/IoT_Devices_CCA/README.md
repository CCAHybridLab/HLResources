# Using IoT Devices on CCA Network
## &emsp; 1. Find Device's MAC Address. Run the following code in Arduino IDE connected to your device:
   ```
   #include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);  // Give some time for serial to initialize

  // Print the MAC address of the ESP32
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
}
   ```
## &emsp; 2. With the MAC Address, [Follow this Guide to Register device](https://portal.cca.edu/knowledge-base/general/registering-iot-devices-to-wifi/)
## &emsp; 3. Update Arduino Project Code with
```
username = "CCA";
password = "";
```
Example program to test if Wifi is working: (Check Serial monitor for success/error logs)
```
#include <WiFi.h>

// Replace with your network credentials
const char* ssid     = "CCA";
const char* password = "";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Start Wi-Fi connection
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Connected!
  Serial.println("\nWi-Fi connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
}

```
