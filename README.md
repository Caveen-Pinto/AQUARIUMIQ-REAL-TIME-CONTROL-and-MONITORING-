# AQUARIUMIQ-REAL-TIME-CONTROL-and-MONITORING

## Overview

AquariumIQ is an ESP32-based IoT-enabled smart aquarium management system developed as a continuation of the **Aquarium Monitoring and Actuation** project. This version enhances the previous prototype by introducing a modular hardware design, an integrated web-based control interface, and a compact enclosure for easier deployment inside aquarium setups.

Unlike the previous version, which relied on third-party mobile applications, AquariumIQ features a built-in web server hosted on the ESP32, allowing users to monitor sensor data, configure system parameters, and control aquarium devices directly through any web browser connected to the same network. This improves usability, scalability, and simplifies future feature upgrades.

The system continuously monitors critical aquarium parameters and automatically controls devices such as the heater, feeder, lighting, water circulation pump, and other actuators to maintain a healthy environment for aquatic life while minimizing manual intervention.

---

## Previous Project

This project is an upgraded version of the following repository:

**Aquarium Monitoring and Actuation**  
https://github.com/Caveen-Pinto/AQUARIUM-MONITORING-and-ACTUATION-

---

## What's New

- Modular hardware design for compact installation
- Built-in ESP32 web server replacing third-party mobile applications
- Improved user interface for monitoring and control
- Custom PCB implementation using Zero PCB
- Compact 3D-printed enclosure
- Redesigned automatic feeder mechanism
- Easier deployment, maintenance, and future upgrades
- Improved wiring and hardware organization
- Enhanced overall system reliability

---

## Features

- Real-time temperature monitoring
- pH monitoring
- Automatic fish feeding
- Smart lighting control
- Automatic heater and cooler control
- Water circulation control
- ESP32 web server for monitoring and configuration
- Wi-Fi-based remote access
- Live sensor monitoring
- User-configurable parameter settings
- Modular embedded system architecture

---

## Hardware Components

- ESP32 Development Board
- DS18B20 Temperature Sensor
- pH Sensor Module
- Relay Module
- Water Pump
- Solenoid Valve
- RTC Module
- MOSFET Driver Circuit
- Custom Zero PCB
- 3D Printed Enclosure
- 3D Printed Automatic Feeder
- Power Supply Module

---

## Software Used

- Arduino IDE
- ESP32 Web Server

---

## Working Principle

1. The ESP32 continuously monitors aquarium parameters through connected sensors.
2. Sensor data is processed locally by the ESP32.
3. The embedded web server hosts a browser-based dashboard for monitoring and control.
4. Users can view live sensor readings and modify operating parameters without installing any external application.
5. Based on predefined thresholds, the ESP32 automatically controls connected actuators such as the heater, feeder, lighting, and water circulation system.
6. The modular hardware design allows the system to be easily installed and maintained inside an aquarium.

---

## Applications

- Home Aquariums
- Aquarium Shops
- IoT-Based Automation
- Educational Projects

---

## Technologies Used

- ESP32
- Arduino
- Embedded C/C++
- IoT
- Embedded Systems
- Sensor Integration
- 3D Printing

---

## Contributors

This project was developed as a Major Project by students of the Department of Electronics and Communication Engineering, Canara Engineering College.

CAVEEN PRASHANTH PINTO
[SHEIK MAHAMMAD NIZAMUDDIN](https://github.com/SheikNizam/)
SAMRADH GAMBHIR
PRANAV T

### My Contributions

- Literature survey and technical research
- Component selection
- Modular hardware design
- Custom Zero PCB implementation
- Hardware integration
- Sensor interfacing
- Embedded web server integration
- System testing and debugging
- Documentation and presentation

---

## Future Improvements

- Dissolved Oxygen (DO) Monitoring
- Ammonia Detection
- Nitrite Detection
- Nitrate Detection
- Turbidity Monitoring
- Cloud Database Integration
- Mobile Notifications
- AI-based Fish Health Analysis
- Mobile Application Support

---

## Recognition

Developed as a Major Project at Canara Engineering College, Department of Electronics and Communication Engineering.

---

## License

This project is licensed under the MIT License.
