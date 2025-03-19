
void hunt(){
checkOpponent(direction); // Update direction based on sensor readings

 while (direction == 0){
  xmotion.Left0(50, 100);
  xmotion.StopMotors(100);
  checkOpponent(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
  xmotion.Right0(50, 100);
  xmotion.StopMotors(100);
  checkOpponent(direction);  // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
  xmotion.Right0(50, 100);
  xmotion.StopMotors(100);
 checkOpponent(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
      xmotion.Left0(50, 100);
  xmotion.StopMotors(100);
  checkOpponent(direction);  // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
      xmotion.Forward(50, 100);
      xmotion.StopMotors(100);
checkOpponent(direction);  // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;

  }
 }



}
