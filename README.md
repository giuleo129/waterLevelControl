# Water Level Control with Blynk IoT

This project implements a smart water level monitoring system using Arduino Yún, an HC-SR04 ultrasonic sensor, a piezo buzzer, and the Blynk IoT platform. The system measures the water level in a tank, sends live data to the Blynk dashboard, and triggers an alarm when the level falls below a set threshold.

## Features
- **Real-time monitoring:** Ultrasonic sensor measures water level in centimeters.  
- **IoT integration:** Live data sent to Blynk app via Virtual Pins.  
- **Adjustable threshold:** Maximum distance can be changed dynamically via Blynk slider (V1).  
- **Alarm system:** Buzzer activates when water level drops below 10% of maximum capacity.  
- **Event notifications:** Low water events logged and pushed to Blynk (low_water).  
- **Debugging support:** Serial monitor displays distance, water level, and percentage.

## Components
- Arduino Yún (or compatible board with Blynk support)  
- HC-SR04 ultrasonic sensor  
- Piezo buzzer  
- Internet connection via Arduino Yún  
- Blynk mobile app

## Wiring
- HC-SR04 Trig → Pin 3  
- HC-SR04 Echo → Pin 2  
- Buzzer + → Pin 5  
- Common GND between components and Arduino  

## Blynk Virtual Pins
- V0: Water level (cm)  
- V1: Slider to adjust MAX_DISTANCE (tank height)  
- V2: Water level percentage (%)  
- low_water: Event notification triggered when level < 10%

## Applications
- Domestic and industrial water tanks  
- Smart irrigation systems  
- IoT-based liquid level monitoring

## Key Takeaway
Demonstrates practical experience with IoT systems, sensor integration, and real-time monitoring dashboards using Blynk.
