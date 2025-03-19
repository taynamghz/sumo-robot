
int checkEdge() {
  delay(10);
  sensorV[0] = analogRead((ML1));
  //sensorV[1] = digitalRead((ML2));
  sensorV[2] = analogRead((ML3));
//RF
if(analogRead(ML1)>800){
  sensorV[0] =1;
}
else{
  sensorV[0] =0;
}

//LF
if(analogRead(ML3)>800){
  sensorV[2] =1;
}
else{
  sensorV[2]=0;
}

  int state = 0; // white/clear
 
  if (sensorV[0] == 0 && sensorV[1] == 0 && sensorV[2] == 0)  {
    state = 0;
        Serial.println(" all are 0");

  } else if (sensorV[0] == 1 && sensorV[2] == 0) {
    state = 1;
        Serial.println(" RF IS 1 ");

  // } else if (sensorV[1] == 1) {
  //   state = 2;
  //       Serial.println(" back sesnor ONLY 1");

  // 
  } 
  else if (sensorV[2] == 1 && sensorV[0] == 0) {
    state = 3;
        Serial.println(" LF IS 1");

  } else if (sensorV[0] == 1 && sensorV[2] == 1) {
    state = 4;
        Serial.println(" BOTH FRONT ARE 1");

  }

  // sensorV[0] = analogRead(ML1);
  // //sensorV[1] = digitalRead(ML2);
  // sensorV[2] = analogRead(ML3);
  return state;
}
