#include <AFMotor.h>
#include <Servo.h> 
#include <FlySkyIBus.h>

const int THROTTLE_CHANNEL = 1;
const int STEERING_CHANNEL = 0;
int direction = 0;

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo servo;

void setup() {
    Serial.begin(115200);
    IBus.begin(Serial);
    servo.attach(9);  
}

void loop() {
    IBus.loop();
    int throttle = IBus.readChannel(THROTTLE_CHANNEL);
    int steering = IBus.readChannel(STEERING_CHANNEL);

    if (IBus.millisSinceUpdate() > 500) {
        throttle = 1500;
        steering = 1500;
     }
  
    throttle = mapfloat(throttle, 1000, 2000, -255, 255);
    steering = mapfloat(steering, 1000, 2000, 0, 255);
  
   if (throttle > 0) {
       direction = FORWARD;
   } else {
       direction = BACKWARD;
   }
   motor1.run(direction);
   motor2.run(direction);
   motor3.run(direction);
   motor4.run(direction);
   motor1.setSpeed(throttle);
   motor2.setSpeed(throttle);
   motor3.setSpeed(throttle);
   motor4.setSpeed(throttle);
   servo.write(steering);
}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
