// Define pins
const int pirPin = 2;     
const int ledPin = 3;     
const int buttonPin = 4;  

volatile bool motionDetected = false;   // Flag for motion detection
bool ledState = false;                  // Tracks LED state
unsigned long motionStartTime = 0;      // Stores time when motion is detected

void motionISR() {
    motionDetected = true; // Interrupt triggered when motion is detected
}

void setup() {
    pinMode(pirPin, INPUT);     
    pinMode(buttonPin, INPUT_PULLUP); 
    pinMode(ledPin, OUTPUT);   
    Serial.begin(9600);      

    // Attach interrupt: Interrupt on RISING edge (motion detected)
    attachInterrupt(digitalPinToInterrupt(pirPin), motionISR, RISING);
}

void loop() {
    // If motion is detected, turn on the LED for 5sec
    if (motionDetected) {
        ledState = true;  // LED ON
        digitalWrite(ledPin, HIGH);
        Serial.println("Motion detected! LED ON");
        motionStartTime = millis();  // Record time
        motionDetected = false;  // Reset motion flag
    }

    // Interrupttion- If LED is ON due to motion, turn OFF when button is pressed
    if (ledState && (millis() - motionStartTime < 5000)) 
    {
        if (digitalRead(buttonPin) == LOW) {  
            while (digitalRead(buttonPin) == LOW);  
            ledState = false;  // Turn off LED
            digitalWrite(ledPin, LOW);
        }
    }
    // After 5 seconds, automatically turn off LED 
    else if (ledState && (millis() - motionStartTime >= 5000)) 
    {
        ledState = false;
        digitalWrite(ledPin, LOW);
    }
}
