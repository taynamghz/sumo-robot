
while (true){
int edgeState = checkEdge();
check_sensors(direction); // Update direction based on sensor readings
  if (edgeState == 0 && direction !=0 ) {
    Serial.println("NO EDGE & opponent detected");
    do {
      attack(direction); 
      edgeState = checkEdge(); // Check for edges again
        if (edgeState != 0){
        break;
         }
        check_sensors(direction); // Update direction based on sensor readings
    } while (direction != 0); // Exit loop if opponent is detected or edge is detected
    Serial.println("EXIT MAIN LOOP");
    avoidEdge(edgeState);
    check_sensors(direction); // Update direction based on sensor readings 
}
if (direction == 0) {
    //hunt();
    edgeState = checkEdge();
    while (edgeState == 0 && direction == 0){
      xmotion.Forward(50, 10);
      check_sensors(direction);
      if (direction != 0){
        break;
      }
      check_sensors(direction);
      edgeState = checkEdge();
    }
    avoidEdge(edgeState);
    int time = 0;
    while(direction==0 && edgeState == 0)
    {  xmotion.Left0(60, 10);
    time = time + 10;
    if (time == 2000) {break;}
        //xmotion.ArcTurn(15, 30, 20);
         check_sensors(direction); // Update direction based on sensor readings
         edgeState = checkEdge();
      }    
   avoidEdge(edgeState);
  }
}
}
