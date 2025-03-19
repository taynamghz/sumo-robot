
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
// int angleTurned = 0; // Track total rotation

// while (true) { // Infinite loop
//     xmotion.Left0(50, 100); // Small turn left
//     xmotion.StopMotors(100); // Pause briefly

//     checkOpponent(direction); // Check for opponent
//     edgeState = checkEdge();  // Check for edge

//     if (direction != 0 || edgeState) {
//         break; // Stop if opponent is found or edge detected
//     }

//     angleTurned += 10; // Increment turn by 10 degrees

//     if (angleTurned >= 360) {
//         angleTurned = 0; // Reset after full turn to keep looping
//     }
// }
