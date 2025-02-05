//code for HC-SR05 sensor,Led, and Arduino nano
#define MOTION_SENSOR_PIN 2  // HC-SR505 output connected to pin 2
#define LED_PIN 13           // External LED connected to pin 13

void setup() {
    pinMode(MOTION_SENSOR_PIN, INPUT);  // Set motion sensor as input
    pinMode(LED_PIN, OUTPUT);           // Set external LED as output
    Serial.begin(9600);                 // Start serial communication
}

void loop() {
    int motionStatus = digitalRead(MOTION_SENSOR_PIN);  // Read sensor value

    if (motionStatus == HIGH) {
        digitalWrite(LED_PIN, HIGH);   // Turn on LED when motion is detected
        Serial.println("Motion detected! LED ON");
    } else {
        digitalWrite(LED_PIN, LOW);    // Turn off LED when no motion
        Serial.println("No motion. LED OFF");
    }

    delay(500);  // Short delay for stability
}
