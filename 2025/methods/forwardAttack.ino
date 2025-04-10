
void forward_attack() {
  int edgeState = checkEdge();
  int direction = 0;  // Local variable to check real-time opponent detection

  checkOpponent(direction); 
  // if (direction == 1) {
  //   xmotion.Forward(100, 50);  // Move forward
  // } else {
  //   xmotion.StopMotors(0);  // Stop if no opponent is detected
  // }
  
  while (direction == 1) {
    checkOpponent(direction);  // Continuously check for opponent
    // if (direction == 0) { 
    //   xmotion.StopMotors(0);
    //   Serial.println("No opponent, stopping.");
    //   break;
    // }

    Serial.println("Before attacking");
    xmotion.Forward(50, 10);  // Move forward in small steps
    Serial.println("After attacking");

    edgeState = checkEdge();
    if (edgeState != 0) {
      break;
    }
  }
  
  edgeState = checkEdge();
  if (edgeState != 0) {
    avoidEdge(edgeState);
  }
}
