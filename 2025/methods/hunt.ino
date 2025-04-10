 void standStill(int stillTime){
      checkOpponent(direction);
  int time = 0;
    while(direction==0 )
    {      xmotion.StopMotors(10);

    time = time + 10;
    if (time == stillTime) {break;}
 }
 }
void hunt(){
    edgeState = checkEdge(); // Check for edges again
       
        checkOpponent(direction); // Update direction based on sensor readings
  while(edgeState == 0 && direction ==0 ){
    xmotion.Forward(30,20);
     edgeState = checkEdge(); // Check for edges again
       
        checkOpponent(direction);
  }
}
