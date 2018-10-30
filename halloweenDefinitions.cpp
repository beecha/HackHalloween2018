#include <Arduino.h>
#include "halloween.h"


//============ GLOBAL VARIABLES ================//
// Ultrasonic
int SENSOR_TRIG_PIN = 11;
int SENSOR_ECHO_PIN = 12;
int MAXIMUM_TRIGGER_DISTANCE = 48; // In inches, 48 inches = 4 feet
long DURATION, CM, INCHES;  // For converting sensor time to distance.

// LEDs
int LED_PIN = 6;             // Light up LED (for visual debugging)
int READY_LED = 7;           // Light up LED (for visual debugging)
int EYES_LED = 5;

// Change this value for how many seconds to flash eye LED(s)
long int FLASH_INTERVAL = 5;

// Servo variables
Servo MY_SERVO;
int SERVO_PIN = 9;
//----------------------------------------------//





//============= SET PORTS AND PINS ===============//
void setup()
{
	Serial.begin(9600);

	// Input and output pins
	pinMode(SENSOR_TRIG_PIN, OUTPUT);
	pinMode(SENSOR_ECHO_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
  pinMode(READY_LED, OUTPUT);
  pinMode(EYES_LED, OUTPUT);

	MY_SERVO.attach(SERVO_PIN);
}
//-----------------------------------------------//





//============== FUNCTION DEFINITIONS ================//

void flashLED(int pin, int interval)
{
  int flashDelay = 0;
  int msBlinks = 200;    // 3 to 4 blinks per second
  while (flashDelay < interval)
  { 
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
    delay(msBlinks);
    flashDelay += msBlinks;
  }
}


void sonicSensor()
{
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse.
  digitalWrite(SENSOR_TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(SENSOR_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SENSOR_TRIG_PIN, LOW);
}
//----------------------------------------------------//
