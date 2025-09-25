# Water Level Control with Blynk IoT

## Overview
This project implements a **smart water level monitoring system** using **Arduino Yún**, an **HC-SR04 ultrasonic sensor**, a **piezo buzzer**, and the **Blynk IoT platform**.  
The system continuously measures the water level inside a tank, sends live data to the Blynk dashboard, and triggers an alarm when the level is too low.

## Features
- **Real-time monitoring**: ultrasonic sensor measures water level in cm.  
- **IoT integration**: live data sent to the Blynk app via Virtual Pins.  
- **Adjustable threshold**: maximum distance can be changed dynamically with a Blynk slider (`V1`).  
- **Alarm system**: buzzer activates when the water level drops below 10% of the maximum capacity.  
- **Event notifications**: low water events logged and pushed to Blynk (`low_water`).  
- **Debugging support**: serial monitor shows distance, water level, and percentage.  

## Components
- Arduino Yún (or compatible board with Blynk support)  
- HC-SR04 ultrasonic sensor  
- Piezo buzzer  
- Internet connection (via Arduino Yún)  
- Blynk mobile app  

## Wiring
- HC-SR04 **Trig** → Pin 3  
- HC-SR04 **Echo** → Pin 2  
- Buzzer **+** → Pin 5  
- Common GND between components and Arduino  

## Blynk Virtual Pins
- `V0`: Water level (cm)  
- `V1`: Slider to adjust **MAX_DISTANCE** (tank height)  
- `V2`: Water level percentage (%)  
- `low_water`: Event notification triggered when level < 10%  

## Applications
- Domestic and industrial water tanks  
- Smart irrigation systems  
- IoT-based liquid level monitoring  
