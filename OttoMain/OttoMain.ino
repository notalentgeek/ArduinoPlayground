//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-- Otto DIY PLUS APP Firmware version 9 (V9)
//-- Otto DIY invests time and resources providing open source code and hardware,  please support by purchasing kits from (https://www.ottodiy.com)
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
//-- If you wish to use this software under Open Source Licensing, you must contribute all your source code to the community and all text above must be included in any redistribution
//-- in accordance with the GPL Version 2 when your application is distributed. See http://www.gnu.org/copyleft/gpl.html
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <Otto9.h> // Otto Library Version 9
Otto9 Otto;        // This is Otto!

//---------------------------------------------------------
//-- First step: Configure the pins where the servos are attached
/*             -------- 
              |  O  O  |
              |--------|
  RIGHT LEG 3 |        | LEFT LEG 2
               -------- 
               ||    ||
RIGHT FOOT 5 |---    ---| LEFT FOOT 4  
*/
// SERVO PINS //////////////////////////////////////////////////////////////////////////////
#define PIN_YL 2 // `servo[0]` left leg
#define PIN_YR 3 // `servo[1]` right leg
#define PIN_RL 4 // `servo[2]` left foot
#define PIN_RR 5 // `servo[3]` right foot

// ULTRASONIC PINS /////////////////////////////////////////////////////////////////////////
#define PIN_TRIGGER 8 // TRIGGER pin (8)
#define PIN_ECHO    9 // ECHO pin (9)

// BUZZER PIN //////////////////////////////////////////////////////////////////////////////
#define PIN_BUZZER 13 // BUZZER pin (13)

// SERVO ASSEMBLY PIN //////////////////////////////////////////////////////////////////////
// To help assemble Otto's feet and legs, wire link between pin 7 and GND
#define PIN_ASSEMBLY 7 // ASSEMBLY pin (7) LOW = assembly; HIGH  = normal operation

///////////////////////////////////////////////////////////////////
//-- Global Variables -------------------------------------------//
///////////////////////////////////////////////////////////////////
bool obstacleDetected = false; // Logic state for when object detected is at the distance we set.
int  distance;                 // Variable to store distance read from ultrasonic range finder module.

///////////////////////////////////////////////////////////////////
//-- Setup ------------------------------------------------------//
///////////////////////////////////////////////////////////////////
void setup() {
    // Start Serial Communication
    Serial.begin(9600);

    Otto.init(PIN_YL, PIN_YR, PIN_RL, PIN_RR, true, A6, PIN_BUZZER, PIN_TRIGGER, PIN_ECHO); // Set the servo pins and ultrasonic pins and Buzzer pin
    pinMode(PIN_ASSEMBLY, INPUT_PULLUP); // Easy assembly pin - LOW is assembly Mode

    // Otto wakes up!
    Otto.sing(S_connection);// Otto makes a sound.
    Otto.home();            // Otto moves to its ready position.
    delay(500);             // Wait for 500 milliseconds to allow Otto to stop

    // If pin 7 is LOW then place Otto's servos in home mode to enable easy assembly, 
    // when you have finished assembling Otto, remove the link between pin 7 and GND.
    while (digitalRead(PIN_ASSEMBLY) == LOW) {
        Otto.home();              // Otto moves to its ready position.
        Otto.sing(S_happy_short); // Sing every 5 seconds so we know OTTO is still working
        delay(5000);              // Wait for 5 seconds
    }
}

///////////////////////////////////////////////////////////////////
//-- Principal Loop ---------------------------------------------//
///////////////////////////////////////////////////////////////////
void loop() {
    distance = Otto.getDistance(); // Get the distance from the object. The value will be between 99 cm and 4 cm.
    Serial.println(distance);

    if (obstacleDetected == true){ // If we have nothing close to Otto, he will stop. He will walk, if you place an object close to it.
        Otto.walk(2, 500, 1);      // Change the ` for lower value to run faster!
    }
                              
    delay(100); // Wait for 100 milliseconds to allow Otto to settle
         
    // Read distance sensor and to actualize `obstacleDetected` variable.

    distance = Otto.getDistance(); // Get the distance from the object. The value will be between 99 cm and 4 cm.

    // From the comment below I know that `getDistance()` returns Otto distance to the nearest object in cm.
    if(distance < 15){  // If the distance detected is closer than 15 cm then do something, Otto will walk forward
        obstacleDetected = true;
    }
    else
    {
        obstacleDetected = false; // No object closer than 15 cm so we stop Otto from walking.
        Otto.home();              // Here we stop Otto walking and place it in its ready position.
    }
}
