#include "COS_MQ7.h"

// Pin definitions
#define ACTIVE_MONOX_PIN 5
#define READ_MONOX_PIN A4
#define READ_COPSV_PIN A3

// Variable initializations
int reading, voltage;
int heater = 6;
int sense = 4;
// create CO sensor object
// Last parameter is the duration of initial purge in seconds, negative value sets to default 500 seconds
COS_MQ7 MQ7(ACTIVE_MONOX_LED_PIN, ACTIVE_MONOX_PIN, READ_MONOX_PIN, READ_COPSV_PIN, -1);

void setup() {
  Serial.begin(9600);
  /*pinMode(heater, OUTPUT);
  pinMode(sense, INPUT);
  digitalWrite(heater, HIGH);        // Heater on
  Serial.println("Purge started...");
  for(int i = 60; i > 0; i--) {         // Purge for 60 seconds
    Serial.println(i);
    delay(1000);
  }
   Serial.println("Purge completed...");

  Serial.println("Sensing...");

  for(int i = 0; i <= 90; i++) {     // Read for 90 seconds
    Serial.print(i, DEC);                   //  This code may be repeated
    if(digitalRead(sense) == 1)
      Serial.print("  ALARM");
    Serial.println("");
    delay(1000);
  }
  Serial.println("Sense complete...");
  */
}

void loop() {
  MQ7.Power_cycle();
  
  // for testing
  Serial.print(MQ7.Get_state());
  Serial.print(',');
  Serial.print(MQ7.Get_Voltage_reading());
  Serial.print(',');
  Serial.println(MQ7.Get_current_CO_reading());
  
  // Only record 'good' reading
  if(MQ7.Get_state() == 4) {
    voltage = MQ7.Get_CO_reading();
  }
  
  // Do something when CO psu voltage is too low
  
  if(MQ7.Get_Voltage_reading() < 400) {
    Serial.println("CO sensor power supply voltage is too low.");
    // do something
  }
  
  delay(1000);
}
