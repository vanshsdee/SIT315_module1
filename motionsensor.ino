// Define pins
const int pirPin = 2;  // PIR motion sensor connected to digital pin 2
const int ledPin = 3;  // LED connected to digital pin 3

void setup() {
    pinMode(pirPin, INPUT);  // Set PIR sensor as input
    pinMode(ledPin, OUTPUT); // Set LED as output
    Serial.begin(9600);      // Start serial communication for debugging
}

void loop() {
    int motionDetected = digitalRead(pirPin); // Read PIR sensor state
    
    if (motionDetected == HIGH) { // If motion is detected
        digitalWrite(ledPin, HIGH); // Turn on LED
        Serial.println("Motion detected! LED ON");
    } else {
        digitalWrite(ledPin, LOW); // Turn off LED
        Serial.println("No motion. LED OFF");
    }
    
    delay(100); // Small delay to avoid rapid changes
}
