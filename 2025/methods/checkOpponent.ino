void checkOpponent(int &direction) {
  int sensorFv = digitalRead(sensorF);
  int sensorLv = digitalRead(sensorL);
  int sensorRv = digitalRead(sensorR);
  int sensorLFv = digitalRead(sensorLF);
  int sensorRFv = digitalRead(sensorRF);

  if (sensorFv == 1) {
    Serial.println("Detected front");
    direction = 1;
  } else if (sensorLv == 1) {
    Serial.println("Detected left");
    direction = 2;
  } else if (sensorRv == 1) {
    Serial.println("Detected right");
    direction = 3;
  } else if (sensorLFv == 1) {
    Serial.println("Detected left front");
    direction = 4;
  } else if (sensorRFv == 1) {
    Serial.println("Detected right front");
    direction = 5;
  } else {
    direction = 0; // None detected
  }
}
