## Interfacing of Ethernet with ESP32

#### Hardware components:

1. ESP32 DOIT-DEVKIT-v1

2. ENC28J60 module

3. Jumper wires 

4. LAN cable 

   

#### Software components:

**Environment:** Platformio

**Framework:** Arduino Framework



#### Pin Mapping:

| ENC28J60   | ESP32   |
| :--------- | ------- |
| VCC        | Vin(5v) |
| GND        | GND     |
| SCLK (SCK) | GPIO18  |
| MISO (SO)  | GPIO19  |
| MOSI (ST)  | GPIO23  |
| CS         | GPIO5   |



#### Libraries Used:

1- UIPEthernet  (https://github.com/UIPEthernet/UIPEthernet)

2- PubSubClient 



#### Testing:

MQTT Broker: test.mosquitto.org (public broker), broker.hivemq.com (public broker)

MQTT Port: 1883 



