#include "HBridge.h";

const int pinA = 6;
const int pinB = 7;
int counter = 0; 
int target = 100;
int state;
int prevState;  

HBridge motor(9, 11);

void setup() { 
    Serial.begin(115200);    
    pinMode(pinA, INPUT);
    pinMode(pinB, INPUT);
    prevState = digitalRead(pinA);   
} 

void loop() { 
    state = digitalRead(pinA);
    if (state != prevState){     
        if (digitalRead(outputB) != state) { 
            counter ++;
        } else {
            counter --;
        }
        Serial.println(counter);
    } 
    prevState = state;

    set_motor(); 
} 

void set_motor() { 
   if (target > counter) {
       motor.set_signal(1.0);   
   }
   if (target < counter) {
       motor.set_signal(-1.0);   
   } 
   if (target = counter) {
       motor.set_signal(0.0);   
   } 
}
