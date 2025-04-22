const int pirPin = 2;       // PIR sensor pin
const int ledPin = 13;      // LED pin
const int switchPin = 3;    // Switch pin (interrupt)

volatile bool ledOverride = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);  // Use internal pull-up resistor

  attachInterrupt(digitalPinToInterrupt(switchPin), turnOffLED, FALLING); // Interrupt on button press

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(pirPin) == HIGH) {
    Serial.println("Motion detected!");
    ledOverride = false;               // Reset override flag
    digitalWrite(ledPin, HIGH);        // Turn LED on

    unsigned long startTime = millis();
    while (millis() - startTime < 5000) { // Keep LED on for 5 seconds
      if (ledOverride) {
        Serial.println("LED turned off by switch.");
        break;
      }
    }

    digitalWrite(ledPin, LOW);         // Turn LED off after 5 seconds or override
  }
}

// Interrupt Service Routine
void turnOffLED() {
  ledOverride = true;
}
