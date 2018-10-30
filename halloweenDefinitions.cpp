#include <Arduino.h>
#include "halloween.h"


//============ GLOBAL VARIABLES ================//
int SENSOR_TRIG_PIN = 11;
int SENSOR_ECHO_PIN = 12;
int LED_PIN = 6;             // Light up LED (for visual debugging)
int MAXIMUM_TRIGGER_DISTANCE = 48; // In inches, 48 inches = 4 feet
long DURATION, CM, INCHES;  // For converting sensor time to distance.

// Servo variables
Servo MY_SERVO;
int POS = 0;
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

	MY_SERVO.attach(SERVO_PIN);
}
//-----------------------------------------------//
