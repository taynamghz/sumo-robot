
void attack(int direction) {
  if (direction == 1) { // Opponent is in front
    forward_attack();
    Serial.println("Attacking forward");
  } else if (direction == 5) { // Right forward
    xmotion.Right0(50, 70);
            xmotion.StopMotors(stop);

    forward_attack();
    xmotion.StopMotors(30);
    Serial.println("Attacking RF");
  } else if (direction == 4) { // Left forward
    xmotion.Left0(50, 70);
        xmotion.StopMotors(stop);
    forward_attack();
    xmotion.StopMotors(30);
    Serial.println("Attacking LF");
  } else if (direction == 2) { // Left
    xmotion.Left0(50, 150);
    xmotion.StopMotors(stop);

    forward_attack();
    xmotion.StopMotors(100);
    Serial.println("Attacking L");
  } else if (direction == 3) { // Right
    xmotion.Right0(50, 150);
            xmotion.StopMotors(stop);

    forward_attack();
    xmotion.StopMotors(100);
    Serial.println("Attacking R");
  } else {
    xmotion.StopMotors(0);
    Serial.println("No action");
  }
  delay(20);
  int edgeState = checkEdge();
  if (edgeState != 0) {
    avoidEdge(edgeState);
  }
}
