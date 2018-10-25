#include <Arduino.h>
#include "halloween.h"


//============ GLOBAL VARIABLES ================//
int SENSOR_TRIG_PIN = 11;
int SENSOR_ECHO_PIN = 12;
int LED_PIN = 9;             // Light up LED (for visual debugging)
int MINIMUM_TRIGGER_DISTANCE = 5;
long DURATION, CM, INCHES;  // For converting sensor time to distance.
//----------------------------------------------//



//============= SET PORTS AND PINS ===============//
void setup()
{
	Serial.begin(9600);

	// Input and output pins
	pinMode(SENSOR_TRIG_PIN, OUTPUT);
	pinMode(SENSOR_ECHO_PIN, INPUT);
	pinMode(LED_PIN, OUTPUT);
}
//-----------------------------------------------//