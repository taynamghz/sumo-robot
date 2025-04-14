 //comment these out if initialzied in the setup part
    int sensorML1 = analogRead(ML1);
    int sensorML2 = analogRead(ML2);
    int sensorML3 = analogRead(ML3);

    
    int sensorLFV = analogRead(sensorLF);
    int sensorFV  = analogRead(sensorF);
    int sensorRFV = analogRead(sensorRF);
    int sensorLV  = analogRead(sensorL);
    int sensorRV  = analogRead(sensorR);

   //linesesnors
    Serial.println("=== ML Sensors ===");
    Serial.print("ML1: "); Serial.print(sensorML1);
    Serial.print(" | ML2: "); Serial.print(sensorML2);
    Serial.print(" | ML3: "); Serial.println(sensorML3);

 
    Serial.println("-------------------");

    // IR sesnors
    Serial.println("=== Regular Sensors ===");
    Serial.print("LF: "); Serial.print(sensorLFV);
    Serial.print(" | F: "); Serial.print(sensorFV);
    Serial.print(" | RF: "); Serial.print(sensorRFV);
    Serial.print(" | L: "); Serial.print(sensorLV);
    Serial.print(" | R: "); Serial.println(sensorRV);

    Serial.println(); 
    delay(500); 
