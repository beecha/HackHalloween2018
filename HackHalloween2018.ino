/* 59 Days of Code - Hack Halloween
 *  
 *  - Frank Cha
 */

//============ GLOBALS =================//
int sensorTrigPin = 11;
int sensorEchoPin = 12;
int ledPin = 9;             // Light up LED (for visual debugging)
long duration, cm, inches;  // For converting sensor time to distance.
//--------------------------------------//


//=============== SET PORTS AND PINS ================//
void setup() {
  Serial.begin(9600);

  // Input and output pins
  pinMode(sensorTrigPin, OUTPUT);
  pinMode(sensorEchoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse.
  digitalWrite(sensorTrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(sensorTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorTrigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(sensorEchoPin, INPUT);
  duration = pulseIn(sensorEchoPin, HIGH);

  // Convert the time into a distance
  cm = (duration / 2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration / 2) / 74;   // Divide by 74 or multiply by 0.0135

  // Output the distance to the serial monitor for observation
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  //=================== TRIGGER LED LIGHT =================//
  /* Trigger the LED light HIGH when an ojbect approaches
   *  the sensor within X distance.
   */
   if (inches <= 5)
      digitalWrite(ledPin, HIGH);   // Visual Debugging
    else
      digitalWrite(ledPin, LOW);    // Turn LED off
   //-------------------------------------------------------//


    delay(250);
}
