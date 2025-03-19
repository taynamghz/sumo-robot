#include <xmotionV3.h>
#define DipSwitch1 7 // Dipswitch 1 tied to Digital 5
#define DipSwitch2 6 // Dipswitch 2 tied to Digital 6
#define DipSwitch3 5 // Dipswitch 3 tied to Digital 7

int ML1 = A2; // lf
//int ML2 = 0; // BACK
int ML3 = A1;// Micro Line Sensor Connected to Analog 1

bool sensorV[2] = {0, 0};

int sensorLF = 1;
int sensorF = 2;
int sensorRF = 4;
int sensorL = A4;
int sensorR = A5;

int direction = 0;
int edgeState;

void setup() {
  // Initialize Serial communication
  Serial.begin(9600);

  // Initialize setup if needed
  pinMode(ML1, INPUT);
  pinMode(ML3, INPUT);
  pinMode(sensorLF, INPUT);
  pinMode(sensorF, INPUT);
  pinMode(sensorRF, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(sensorR, INPUT);

  pinMode(DipSwitch1, INPUT); //Dipswitch 1 Declared as Input
  pinMode(DipSwitch2, INPUT); //Dipswitch 2 Declared as Input
  pinMode(DipSwitch3, INPUT); //Dipswitch 3 Declared as Input

  digitalWrite(DipSwitch1, HIGH); // Dipswitch Inputs are High (Pull-up made)
  digitalWrite(DipSwitch2, HIGH);
  digitalWrite(DipSwitch3, HIGH);

  Serial.begin(9600); //Serial Interface started with 9600 bits per sec.
}

void loop() {

  int DS1 = digitalRead(DipSwitch1);
  int DS2 = digitalRead(DipSwitch2);
  int DS3 = digitalRead(DipSwitch3);

  delay(5000);
  Serial.println("STARTED");

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

while (true){
int edgeState = checkEdge();
check_sensors(direction); // Update direction based on sensor readings
  if (edgeState == 0 && direction !=0 ) {
    Serial.println("NO EDGE & opponent detected");
    do {
      attack(direction); 
      edgeState = checkEdge(); // Check for edges again
        if (edgeState != 0){
        break;
         }
        check_sensors(direction); // Update direction based on sensor readings
    } while (direction != 0); // Exit loop if opponent is detected or edge is detected
    Serial.println("EXIT MAIN LOOP");
    avoidEdge(edgeState);
    check_sensors(direction); // Update direction based on sensor readings 
}
if (direction == 0) {
    //hunt();
    edgeState = checkEdge();
    while (edgeState == 0 && direction == 0){
      xmotion.Forward(50, 10);
      check_sensors(direction);
      if (direction != 0){
        break;
      }
      check_sensors(direction);
      edgeState = checkEdge();
    }
    avoidEdge(edgeState);
    int time = 0;
    while(direction==0 && edgeState == 0)
    {  xmotion.Left0(60, 10);
    time = time + 10;
    if (time == 2000) {break;}
        //xmotion.ArcTurn(15, 30, 20);
         check_sensors(direction); // Update direction based on sensor readings
         edgeState = checkEdge();
      }    
   avoidEdge(edgeState);
  }
}
}

void hunt(){
check_sensors(direction); // Update direction based on sensor readings

 while (direction == 0){
  xmotion.Left0(50, 100);
  xmotion.StopMotors(100);
  check_sensors(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
  xmotion.Right0(50, 100);
  xmotion.StopMotors(100);
  check_sensors(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
  xmotion.Right0(50, 100);
  xmotion.StopMotors(100);
  check_sensors(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
      xmotion.Left0(50, 100);
  xmotion.StopMotors(100);
  check_sensors(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;
  }
      xmotion.Forward(50, 100);
      xmotion.StopMotors(100);
  check_sensors(direction); // Update direction based on sensor readings
  edgeState = checkEdge(); // Check for edges again

  if (direction != 0 || edgeState != 0){
    break;

  }
 }



}

void check_sensors(int &direction) {
  int sensorFv = digitalRead(sensorF);
  int sensorLv = digitalRead(sensorL);
  int sensorRv = digitalRead(sensorR);
  int sensorLFv = digitalRead(sensorLF);
  int sensorRFv = digitalRead(sensorRF);

  if (sensorFv == 1) {
    Serial.println("detected front");
    direction = 1;
  } else if (sensorLv == 1) {
    Serial.println("detected left");
    direction = 2;
  } else if (sensorRv == 1) {
    Serial.println("detected right");
    direction = 3;
  } else if (sensorLFv == 1) {
    Serial.println("detected LF");
    direction = 4;
  } else if (sensorRFv == 1) {
    Serial.println("detected RF");
    direction = 5;
  } else {
    direction = 0; // No detection, reset direction
  }
}

void attack(int direction) {
  if (direction == 1) { //F
    forward_attack();
    Serial.println("attacking forward");
  } else if (direction == 5) { //RF
    xmotion.Right0(50, 80);
    forward_attack();
    xmotion.StopMotors(30);
    Serial.println("attacking RF");
  } else if (direction == 4) {
    xmotion.Left0(50,80);
    forward_attack(); 
    xmotion.StopMotors(30);
    Serial.println("attacking LF");
  } else if (direction == 2) {
    xmotion.Left0(50, 220);
    forward_attack();
    xmotion.StopMotors(100);
    Serial.println("attacking L");
  } else if (direction == 3) {
    xmotion.Right0(50, 220);
    forward_attack();
    xmotion.StopMotors(100);
    Serial.println("attacking R");
  } else {
    xmotion.StopMotors(0);
    Serial.println("NO ACTION");
  }
  
  // After performing attack, check for edges
  int edgeState = checkEdge();
  if (edgeState != 0) {
    // If edge is detected, perform edge avoidance
    avoidEdge(edgeState);
  }
}

void forward_attack() {
  int edgeState = checkEdge();
  // xmotion.Forward(100, 50); // %100 Speed, both motor forward 100mS.
  // xmotion.StopMotors(0);
  check_sensors(direction);
if (direction == 1){
   xmotion.Forward(100, 50); // %100 Speed, both motor forward 100mS.
   //xmotion.Backward(100, 50); //                                          *** new (forward was 30 and no bw)
  check_sensors(direction);

}
  // Continue forward while not crossing the edge and facing a front obstacle
  while (direction == 1 ) {
    // Read sensor values and update direction
    check_sensors(direction);
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


int checkEdge() {
  delay(10);
  sensorV[0] = analogRead((ML1));
  //sensorV[1] = digitalRead((ML2));
  sensorV[2] = analogRead((ML3));
//RF
if(analogRead(ML1)>800){
  sensorV[0] =1;
}
else{
  sensorV[0] =0;
}

//LF
if(analogRead(ML3)>800){
  sensorV[2] =1;
}
else{
  sensorV[2]=0;
}

  int state = 0; // white/clear
 
  if (sensorV[0] == 0 && sensorV[1] == 0 && sensorV[2] == 0)  {
    state = 0;
        Serial.println(" all are 0");

  } else if (sensorV[0] == 1 && sensorV[2] == 0) {
    state = 1;
        Serial.println(" RF IS 1 ");

  // } else if (sensorV[1] == 1) {
  //   state = 2;
  //       Serial.println(" back sesnor ONLY 1");

  // 
  } 
  else if (sensorV[2] == 1 && sensorV[0] == 0) {
    state = 3;
        Serial.println(" LF IS 1");

  } else if (sensorV[0] == 1 && sensorV[2] == 1) {
    state = 4;
        Serial.println(" BOTH FRONT ARE 1");

  }

  // sensorV[0] = analogRead(ML1);
  // //sensorV[1] = digitalRead(ML2);
  // sensorV[2] = analogRead(ML3);
  return state;
}

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



void maneuverX(){
xmotion.Right0(100, 180);
xmotion.Forward(100, 260);
xmotion.Left0(100, 180);

check_sensors(direction);
if (direction != 0)
{return(0);}

xmotion.Forward(100, 250);
xmotion.Backward(100, 50);
xmotion.Left0(100, 230);
xmotion.Forward(100, 200);
}



void maneuverARC(){
xmotion.Left0(100, 180);
xmotion.ArcTurn(100, 40, 350);
xmotion.Right0(100, 250);

}

  


  // switch(edgeState) {
  //   case 0: // No edge detected, continue normal operation
  //     check_sensors(direction); // Update direction based on sensor readings
  //     if (direction != 0) {
  //       attack(direction); // Perform an attack based on the updated direction
  //     }
  //     break;
  //   case 1: // FR ONLY edge detected 
  //     xmotion.ArcTurn(-30, -50, 200);
  //     Serial.println("avoiding front");      
  //     break;
  //   case 2: // Back edge detected
  //     xmotion.Forward(100, 100);
  //     xmotion.StopMotors(100);
  //     Serial.println("avoiding back"); // 10ms Stop Both Motors     
  //     break;
  //   case 3: // LF only
  //     xmotion.ArcTurn(-50, -30, 200);
  //     break;
  //   case 4: // Both front detected
  //     xmotion.Backward(100, 100);
  //     break;
  //   default:
  //     Serial.println("Unknown edge state");
  //     break;
