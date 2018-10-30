/* 59 Days of Code - Hack Halloween, October 2018
 *  An ultrasonic sensor will read the distance of a nearby object.
 *  When it detects an object within X distance, then it will
 *  trigger the device.
 *  
 *  - Frank Cha
 */


//========= INCLUDE LIBRARIES ============//
#include "halloween.h"
//----------------------------------------//


void loop() {
  
  sonicSensor();

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

   if (INCHES <= MAXIMUM_TRIGGER_DISTANCE)
   {
      MY_SERVO.write(90); 
      digitalWrite(LED_PIN, HIGH);   // Visual Debugging
      digitalWrite(READY_LED, LOW);
      flashLED(EYES_LED, 5000);      // Stays triggered for 5 seconds
   }
    else
    {
      MY_SERVO.write(0);
      digitalWrite(LED_PIN, LOW);    // Visual Debugging
      digitalWrite(READY_LED, HIGH);
      digitalWrite(EYES_LED, LOW);
    }
    
    delay(250);
}
