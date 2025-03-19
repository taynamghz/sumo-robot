
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

// while (angleTurned < 360) {
//     xmotion.Left0(50, 100); // Turn left slightly (adjust timing if needed)
//     xmotion.StopMotors(100); // Pause briefly
//     checkOpponent(direction); // Update direction based on sensors
//     edgeState = checkEdge(); // Check if near edge

//     if (direction != 0) {
//         break; // Stop if opponent is found
//     }

//     angleTurned += 10; // Increment by 10 degrees per loop (adjust as needed)
// }
