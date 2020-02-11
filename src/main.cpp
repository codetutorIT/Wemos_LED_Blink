#include <Arduino.h>

const unsigned int LED_PIN = D1;
const unsigned int TIME_WAIT = 1000;

unsigned long millis_current;
unsigned long millis_previous = 0;

bool isOn;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  isOn = false;
}

void loop() {
  millis_current = millis();
  if(millis_current - millis_previous >= TIME_WAIT) {
    Serial.print("Schalte LED ");
    if(isOn) {
      Serial.println("aus.");
      digitalWrite(LED_PIN, LOW);      
    } 
    else {
      Serial.println("ein.");
      digitalWrite(LED_PIN, HIGH); 
    }
    isOn = !isOn;
    millis_previous = millis_current;
  }
}