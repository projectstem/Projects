const int pinA = 6;
const int pinB = 7;
int counter = 0; 
int state;
int prevState;  

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
}
