  void avoidEdge(int &edgeState) {
  while (edgeState!=0)
  {


  if (edgeState=4){
  xmotion.Backward(100,400); 
  xmotion.Left0(50,300);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);


  edgeState = checkEdge();
}

else if (edgeState =3){
  xmotion.Backward(100,400); 
  xmotion.Left0(50,200);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);
  edgeState = checkEdge();
}
else if (edgeState = 1){
  xmotion.Backward(100,400); 
  xmotion.Left0(50,200);
  //xmotion.Forward(50,150);
  xmotion.StopMotors(0);
  edgeState = checkEdge();

}
}
}
