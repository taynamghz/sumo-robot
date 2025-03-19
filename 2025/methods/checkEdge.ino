
int checkEdge() {
  delay(10);
  sensorV[0] = analogRead((ML2)); //BACK
  sensorV[1] = digitalRead((ML1)); //FRONT LEFT
  sensorV[2] = analogRead((ML3)); //FRONT RIGHT
//fl
if(analogRead(ML1)<200){
  sensorV[0] =1; //edge
}
else{
  sensorV[0] =0;
}
//back
if(analogRead(ML2)<200){
  sensorV[1] =1;
}
else{
  sensorV[1]=0;
}
//fr
if(analogRead(ML3)<200){
  sensorV[2] =1;
}
else{
  sensorV[2]=0;
}


  int state = 0; // black/clear
 
  if (sensorV[0] == 0 && sensorV[1] == 0 && sensorV[2] == 0)  {
    state = 0;
        Serial.println("robot is safe"); //bot is in field

  } else if (sensorV[0] == 1 && sensorV[2] == 0) {
    state = 1;
        Serial.println(" front left is at edge");

   } else if (sensorV[1] == 1) {
    state = 2;
      Serial.println(" back sesnor is at edge ");

  
  } 
  else if (sensorV[2] == 1 && sensorV[0] == 0) {
    state = 3;
        Serial.println(" ffront right is at  edge");

  } else if (sensorV[0] == 1 && sensorV[2] == 1) {
    state = 4;
        Serial.println(" BOTH FRONT ARE at edge");

  }

  // sensorV[0] = analogRead((ML2)); //BACK
  // sensorV[1] = digitalRead((ML1)); //FRONT LEFT
  // sensorV[2] = analogRead((ML3)); //FRONT RIGHT
  return state;
}
