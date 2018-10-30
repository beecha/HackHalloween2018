#ifndef HALLOWEEN_H
#define HALLOWEEN_H

#include <Servo.h>

//========== GLOBAL VARIABLE DECLARATIONS ===========//
// Ultrasonic
extern int SENSOR_TRIG_PIN;
extern int SENSOR_ECHO_PIN;
extern int MAXIMUM_TRIGGER_DISTANCE;
extern long DURATION, CM, INCHES;

// LEDs
extern int LED_PIN;
extern int READY_LED;
extern int EYES_LED;
extern long int FLASH_INTERVAL;

// Servo
extern Servo MY_SERVO;
extern int SERVO_PIN;
//--------------------------------------------------//


//============= FUNCTION PROTOTYPES ================//
void flashLED(int, int);
void sonicSensor(void);
//-------------------------------------------------//

#endif
