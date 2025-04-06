int checkEdge() {
    delay(10);
    int sensorV[3]; 

    sensorV[0] = analogRead(ML2); // BACK
    sensorV[1] = analogRead(ML1); // FRONT LEFT
    sensorV[2] = analogRead(ML3); // FRONT RIGHT

   
    int threshold = 200;

    // 1 = robot is at edge, 0 = safe)
    sensorV[0] = (sensorV[0] < threshold) ? 1 : 0; // Back
    sensorV[1] = (sensorV[1] < threshold) ? 1 : 0; // Front Left
    sensorV[2] = (sensorV[2] < threshold) ? 1 : 0; // Front Right

    int state = 0; // Default: robot is safe

    if (sensorV[0] == 0 && sensorV[1] == 0 && sensorV[2] == 0) {
        state = 0;
        Serial.println("Robot is safe - No edge detected");
    } else if (sensorV[1] == 1 && sensorV[2] == 0) {
        state = 1;
        Serial.println("Front left is at edge");
    } else if (sensorV[0] == 1) {
        state = 2;
        Serial.println("Back  is at edge");
    } else if (sensorV[2] == 1 && sensorV[1] == 0) {
        state = 3;
        Serial.println("Front right is at edge");
    } else if (sensorV[1] == 1 && sensorV[2] == 1) {
        state = 4;
        Serial.println("Both front sensors are at edge");
    }

    // Print sensor values for debugging
    printSensorValues();

    return state;
}

void printSensorValues() {
    int sensorFL = analogRead(ML1); // Front Left
    int sensorB  = analogRead(ML2); // Back
    int sensorFR = analogRead(ML3); // Front Right

    Serial.print("FL: "); Serial.print(sensorFL);
    Serial.print(" | B: "); Serial.print(sensorB);
    Serial.print(" | FR: "); Serial.println(sensorFR);
    delay(800);
}

