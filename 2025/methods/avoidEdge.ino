  void avoidEdge(int &edgeState) {
  while (edgeState!=0)
  {

//move backward because both front sesnors are at edge 
  if (edgeState=4){
  xmotion.Backward(100,400); 
  xmotion.Left0(50,300);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);


  edgeState = checkEdge();
}
//front right at edge 
else if (edgeState =3){
  xmotion.Backward(100,400); 
  xmotion.Left0(50,200);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);
  edgeState = checkEdge();
}
  // back sesnor at edge
else if (edgeState =2){
  // xmotion.Left0(50,200);
  xmotion.Forward(100,400);
  xmotion.StopMotors(0);
  edgeState = checkEdge();
}
  //front left at edge 
else if (edgeState = 1){
  xmotion.Backward(100,400); 
  xmotion.Left0(50,200);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);
  edgeState = checkEdge();

}
}
}




//_______________
// to test: switch case 
void avoidEdge(int &edgeState) {
    while (edgeState != 0) {
        switch (edgeState) {
            case 4: // Both front 
                xmotion.Backward(100, 400);
                xmotion.Left0(50, 300);
                xmotion.StopMotors(0);
                break;

            case 3: // Front right 
                xmotion.Backward(100, 400);
                xmotion.Left0(50, 200);
                xmotion.StopMotors(0);
                break;

            case 2: // Back 
                xmotion.Forward(100, 400);
                xmotion.StopMotors(0);
                break;

            case 1: // Front left 
                xmotion.Backward(100, 400);
                xmotion.Right0(50, 200);
                xmotion.StopMotors(0);
                break;
        }

       
        edgeState = checkEdge();
    }
}


