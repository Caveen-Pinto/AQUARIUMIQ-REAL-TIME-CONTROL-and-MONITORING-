#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <RTClib.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const char* wifiSSID = "YOUR_SSID"; // CHANGE THIS
const char* wifiPASS = "YOUR_PASSWORD"; // CHANGE THIS

String HARDCODED_ID = "AQM-1234";
WebServer server(80);

// Global Variables
float minTemp, maxTemp, minPH, maxPH;
RTC_DS3231 rtc;
bool fedMorning = false, fedEvening = false;
Servo feeder;

const int FEEDER_PIN = 4;
const int HEATER_PIN = 27;
const int COOLER_PIN = 13;
const int TEMP_SENSOR_PIN = 23;
const int LIGHT_PIN = 2;
const int PH_PIN = 19;
const int PUMP_PIN = 32;
const int SOLENOID_PIN = 33;
const int TRIG_PIN = 18;
const int ECHO_PIN = 5;

float presentTemperature = 0.0, presentpH = 0.0, waterLevelDistance = 0.0;
bool tempManualOverride = false, lightManualOverride = false, phManualOverride = false;
bool lightState = false, pumpState = false, solenoidState = false, feederRunning = false;
bool phFilling = false; // State variable to replace blocking while loop

OneWire oneWire(TEMP_SENSOR_PIN);
DallasTemperature sensors(&oneWire);

// ... [Keep loadDefaults, runFeeder, checkFeedingTime, monitorTemperature, monitorLight as is] ...

// FIXED: Non-blocking monitorPHAndWater
void monitorPHAndWater() {
    readpH();
    readWaterLevel();

    if (phManualOverride) return;

    // Safety: Water level check
    if (waterLevelDistance > 15.0) { // MIN_WATER_LEVEL
        digitalWrite(SOLENOID_PIN, HIGH);
        digitalWrite(PUMP_PIN, LOW);
        solenoidState = true;
        pumpState = false;
        return;
    }

    if (waterLevelDistance < 5.0) { // MAX_WATER_LEVEL
        digitalWrite(SOLENOID_PIN, LOW);
        solenoidState = false;
    }

    // Logic: pH High -> Non-blocking fill
    if (presentpH > maxPH && !phFilling) {
        digitalWrite(PUMP_PIN, HIGH);
        pumpState = true;
        delay(500); 
        digitalWrite(PUMP_PIN, LOW);
        pumpState = false;
        digitalWrite(SOLENOID_PIN, HIGH);
        solenoidState = true;
        phFilling = true; // Enter "filling" state
    }

    // If we are in filling state, monitor level without blocking
    if (phFilling) {
        if (waterLevelDistance <= 5.0) { // MAX_WATER_LEVEL
            digitalWrite(SOLENOID_PIN, LOW);
            solenoidState = false;
            phFilling = false;
        }
    }
}

void setup(){
    Serial.begin(115200);
    WiFi.begin(wifiSSID, wifiPASS);
    
    // WiFi Timeout fix
    int timeout = 0;
    while (WiFi.status() != WL_CONNECTED && timeout < 20) {
        delay(500);
        Serial.print(".");
        timeout++;
    }

    Wire.begin(21, 22);
    rtc.begin();
    feeder.attach(FEEDER_PIN);
    feeder.write(92);

    pinMode(HEATER_PIN, OUTPUT);
    pinMode(COOLER_PIN, OUTPUT);
    pinMode(LIGHT_PIN, OUTPUT);
    pinMode(PUMP_PIN, OUTPUT);
    pinMode(SOLENOID_PIN, OUTPUT);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    sensors.begin();
    
    // Register handlers
    server.on("/", handleRoot);
    server.on("/verify", HTTP_POST, handleVerify);
    server.on("/dashboard", handleDashboard);
    server.on("/details", handleDetails);
    server.on("/save", HTTP_POST, handleSave);
    server.on("/manualfeed", HTTP_POST, handleManualFeed);
    server.begin();
}

void loop(){
    checkFeedingTime();
    monitorTemperature();
    monitorPHAndWater();
    server.handleClient();
    monitorLight();
}
