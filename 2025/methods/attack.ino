
void attack(int direction) {
  if (direction == 1) { //F
    forward_attack();
    Serial.println("attacking forward");
  } else if (direction == 5) { //RF
    xmotion.Right0(50, 80);
    forward_attack();
    xmotion.StopMotors(30);
    Serial.println("attacking RF");
  } else if (direction == 4) {
    xmotion.Left0(50,80);
    forward_attack(); 
    xmotion.StopMotors(30);
    Serial.println("attacking LF");
  } else if (direction == 2) {
    xmotion.Left0(50, 220);
    forward_attack();
    xmotion.StopMotors(100);
    Serial.println("attacking L");
  } else if (direction == 3) {
    xmotion.Right0(50, 220);
    forward_attack();
    xmotion.StopMotors(100);
    Serial.println("attacking R");
  } else {
    xmotion.StopMotors(0);
    Serial.println("NO ACTION");
  }
  
  // After performing attack, check for edges
  int edgeState = checkEdge();
  if (edgeState != 0) {
    // If edge is detected, perform edge avoidance
    avoidEdge(edgeState);
  }
}
