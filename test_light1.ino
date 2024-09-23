const int tachPin = 2; // Pin to read RPM signal
const int ledPin = 13; // Pin to control LED

unsigned long ighigh, iglow, igfreq;
unsigned int rpm = 0;
const int pulsesPerRevolution = 2; // Adjust based on tachometer specs

void setup() {
  pinMode(tachPin, INPUT); // Set tachPin as input
  pinMode(ledPin, OUTPUT); // Set ledPin as output
  Serial.begin(9600); // Start serial communication

    // Light the LED for 1.5 seconds at startup
  digitalWrite(ledPin, HIGH); // Turn LED on
  delay(1500); // Wait for 1.5 seconds
  digitalWrite(ledPin, LOW); // Turn LED off
  
  // Blink the LED twice with 250ms delay
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin, HIGH); // Turn LED on
    delay(250); // Wait 250 milliseconds
    digitalWrite(ledPin, LOW); // Turn LED off
    delay(250); // Wait 250 milliseconds
  }
}

void loop() {
  // Measure the high and low times of the pulse
  ighigh = pulseIn(tachPin, HIGH); // Time the pin stays high (microseconds)
  iglow = pulseIn(tachPin, LOW); // Time the pin stays low (microseconds)
  
  // Calculate the frequency in Hz (cycles per second)
  if (ighigh > 0 && iglow > 0) {
    igfreq = 1000000 / (ighigh + iglow); // Frequency = 1 / period (both high + low)
    
    // Convert frequency to RPM (multiply by 60 for minutes, and adjust for pulses per revolution)
    rpm = (igfreq * 60) / pulsesPerRevolution;
    
    // Output RPM for debugging
    Serial.print("RPM: ");
    Serial.println(rpm);
    
    // LED control based on RPM
    if (rpm >= 6000 && rpm < 8000) {
      int flashRate = map(rpm, 6000, 7800, 500, 100); // Map RPM to flash rate
      digitalWrite(ledPin, HIGH);
      delay(flashRate);
      digitalWrite(ledPin, LOW);
      delay(flashRate);
    } else if (rpm >= 7800) {
      digitalWrite(ledPin, HIGH); // LED stays lit at 7800 RPM or above
    } else {
      digitalWrite(ledPin, LOW); // LED off below 7000 RPM
    }
  } else {
    // If no valid signal detected, turn off the LED
    digitalWrite(ledPin, LOW);
  }
}
