#include <Arduino.h>
#include "UIPEthernet.h"
#include "PubSubClient.h"

#define CS_PIN 5
#define STATUS_LED 2

uint8_t mac[6] = {0x00, 0xA0, 0xC9, 0x14, 0xC8, 0x29};
//00:A0:C9:14:C8:29
EthernetClient ethClient;
PubSubClient mqttClient;

void eth_reconnect(){
  if (Ethernet.begin(mac) == 0) {
    Serial.println(F("[ETH] Ethernet configuration using DHCP failed"));
    for (;;);
  }
  Serial.println("[ETH] Connected");
  Serial.print("[ETH] Local IP : ");
  Serial.println(Ethernet.localIP());
  Serial.print("[ETH] Subnet Mask : ");
  Serial.println(Ethernet.subnetMask());
  Serial.print("[ETH] Gateway IP : ");
  Serial.println(Ethernet.gatewayIP());
  Serial.print("[ETH] DNS Server : ");
  Serial.println(Ethernet.dnsServerIP());
}
// void mqtt_reconnect(){
//   int mqtt_connect_retry = 0;
//   if(!ethClient.connected()){
//     Serial.println("[ETH} Disconnected");
//     eth_reconnect();
//   }
//   else{
//     if(!mqttClient.connected()){
//     mqttClient.connect("ethClient");
//     while (mqtt_connect_retry < 5){
//       if (mqttClient.connected()) {
//           Serial.println(mqttClient.state());
//           Serial.println("[MQTT] client connected");
//           mqtt_connect_retry = mqtt_connect_retry + 5;
//         } else {
//           mqtt_connect_retry++;
//           Serial.print("[MQTT] Counter: ");
//           Serial.println(mqtt_connect_retry);
//           Serial.print("[MQTT] failed, rc=");
//           Serial.print(mqttClient.state());
//           Serial.println("[MQTT] try again in 5 seconds");
//           // Wait 5 seconds before retrying
//           for (int i = 0; i <= 5; i++) {
//             digitalWrite(STATUS_LED, LOW);
//             delay(500);
//             digitalWrite(STATUS_LED, HIGH);
//             delay(500);
//           }
//         }
//      }
//     }
//   }
  
// }

void setup() {
  // setup serial communication
  Serial.begin(115200);
  Ethernet.init(CS_PIN);
  eth_reconnect();
  // setup ethernet communication using DHCP
  
  // setup mqtt client
  // mqttClient.setClient(ethClient);
  // mqttClient.setServer("test.mosquitto.org", 1883);
  //mqttClient.setServer("192.168.1.xxx",1883); //for using local broker
  //mqttClient.setServer("broker.hivemq.com",1883);
  Serial.println("MQTT client configured");

}

// void send_data() {
//   if (mqttClient.connect("ethClient")) {
//     mqttClient.publish("hal", "hello");

//   }
// }



void loop() {
  // Serial.println(ethClient.connected());
  // if(!mqttClient.connected()){
  //   mqtt_reconnect();
  // }
  // mqttClient.loop();
  // send_data();
  // delay(2000);
}