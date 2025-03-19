//inside void loop()
int DS1 = digitalRead(DipSwitch1);
  int DS2 = digitalRead(DipSwitch2);
  int DS3 = digitalRead(DipSwitch3);

if (DS1 == 0 && DS2 == 0 && DS3 == 0){ //program 0 (round 1 - maneuver) [switch towards front = 0]
maneuverX();
//maneuverARC();
forward_attack();

}

else if (DS1 == 0 && DS2 == 0 && DS3 == 1){ //program 1 (round 2 turn right 45) maneuver
xmotion.Left0(100, 50); // right 70 old
xmotion.Forward(100, 260);
xmotion.Right0(100, 180);
xmotion.Forward(100, 250);
xmotion.Backward(100, 50);
xmotion.Right0(100, 230);
}

else if (DS1 == 0 && DS2 == 1 && DS3 == 0){ //program 2 (round 2 turn left 45) maneuver
xmotion.Right0(100, 50);
xmotion.Forward(100, 260);
xmotion.Left0(100, 180);
xmotion.Forward(100, 250);
xmotion.Backward(100, 50);
xmotion.Left0(100, 230);
}

else if (DS1 == 0 && DS2 == 1 && DS3 == 1){ //program 3 (round 3 turn 180) maneuver
xmotion.Left0(100, 230); // left 330 for 180
xmotion.Forward(100, 260);
xmotion.Left0(100, 180);
xmotion.Forward(100, 250);
xmotion.Backward(100, 50);
xmotion.Left0(100, 230);
xmotion.Forward(100, 200);
}
else if (DS1 == 1 && DS2 == 0 && DS3 == 0){ //program 4 arcturn left - rnd 1 - op2
// xmotion.Left0(50, 250);
// xmotion.ArcTurn(100, 30, 600);
// xmotion.Right0(50, 50);
forward_attack();
}
else if (DS1 == 1 && DS2 == 0 && DS3 == 1){ //program 5forward attack direct
// forward_attack();
xmotion.Right0(100, 80);
}
else if (DS1 == 1 && DS2 == 1 && DS3 == 0){ //program 6 BACKWARD arcturn right- rnd 1 - op3 XXX replace
xmotion.Left0(100, 330);
}

else if (DS1 == 1 && DS2 == 1 && DS3 == 1){ //program 7 backward trick
xmotion.Forward(100, 140);
xmotion.Left0(100, 70);
xmotion.Backward(100, 200);
forward_attack();

}
