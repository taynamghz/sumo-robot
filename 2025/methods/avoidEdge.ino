

 void avoidEdge(int &edgeState) {
while (edgeState!=0)
  {

//move backward because both front sesnors are at edge 
  if (edgeState==4){
  xmotion.Backward(100,400); 
  xmotion.Left0(100,200);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);
          Serial.println("avoiding backward");


  edgeState = checkEdge();
}
//front right at edge 
else if (edgeState ==3){
  xmotion.Backward(100,50); 
  xmotion.Right0(100,30);
  xmotion.Backward(100,300); 
    xmotion.Left0(100,150);


  //xmotion.Forward(50,150);
            Serial.println("avoiding FR");

  xmotion.StopMotors(0);
  edgeState = checkEdge();

}
  // back sesnor at edge
 else if (edgeState ==2){
  // xmotion.Left0(50,200);
  xmotion.Forward(100,400);
  
  xmotion.StopMotors(0);
  edgeState = checkEdge();
            Serial.println("avoiding FORWARD");

}
  //front left at edge 
 else if (edgeState == 1){
  xmotion.Backward(100,50); 
  xmotion.Left0(100,30);
  xmotion.Backward(100,300); 
    xmotion.Right0(100,150);

  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);
  edgeState = checkEdge();
            Serial.println("avoiding FL");


}
}
 }

