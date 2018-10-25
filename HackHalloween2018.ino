/* 59 Days of Code - Hack Halloween, October 2018
 *  
 *  - Frank Cha
 */


//========= INCLUDE LIBRARIES ============//
#include "halloween.h"
//----------------------------------------//


void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse.
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENSOR_TRIG_PIN, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(SENSOR_ECHO_PIN, INPUT);
  DURATION = pulseIn(SENSOR_ECHO_PIN, HIGH);

  // Convert the time into a distance
  CM = (DURATION / 2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  INCHES = (DURATION / 2) / 74;   // Divide by 74 or multiply by 0.0135

  // Output the distance to the serial monitor for observation
  // Hotkey: CTRL + SHIFT + M (opens serial monitor)
  Serial.print(INCHES);
  Serial.print("in, ");
  Serial.print(CM);
  Serial.print("cm");
  Serial.println();
  
  //=================== TRIGGER LED LIGHT =================//
  /* Trigger the LED light HIGH when an ojbect approaches
   *  the sensor within X distance.
   */
   if (INCHES <= MINIMUM_TRIGGER_DISTANCE)
      digitalWrite(LED_PIN, HIGH);   // Visual Debugging
    else
      digitalWrite(LED_PIN, LOW);    // Turn LED off
   //-------------------------------------------------------//

    delay(250);
}
