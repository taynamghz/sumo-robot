
void forward_attack() {
  int edgeState = checkEdge();
  // xmotion.Forward(100, 50); // %100 Speed, both motor forward 100mS.
  // xmotion.StopMotors(0);
  checkOpponent(direction);
if (direction == 1){
   xmotion.Forward(100, 50); // %100 Speed, both motor forward 100mS.
   //xmotion.Backward(100, 50); //                                          *** new (forward was 30 and no bw)
  checkOpponent(direction);

}
  // Continue forward while not crossing the edge and facing a front obstacle
  while (direction == 1 ) {
    // Read sensor values and update direction
    checkOpponent(direction);
    Serial.println(" before attacking");

    // Move forward
    xmotion.Forward(100, 10); // %100 Speed, both motor forward 100mS.
    Serial.println(" after attacking");

    // After performing attack, check for edges
    edgeState = checkEdge();
    if (edgeState != 0){
      // mayy not use may use 
     // xmotion.Backward(100, 200);
      break;
    }
  }
  edgeState = checkEdge();
  if (edgeState != 0) {
      // If edge is detected, perform edge avoidance
      avoidEdge(edgeState);
      edgeState = checkEdge();
      
      }
      
      //avoidEdge(edgeState);
    }
