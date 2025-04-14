#include <xmotionV3.h>


int ML1 = A4; // fl Micro Line Sensor
int ML2 = A1; // back
int ML3 = A2; // right  Micro Line Sensor

int sensorV[3] = {0, 0, 0};

int sensorLF = 0;
int sensorF = 1;
int sensorRF = 2;
int sensorL = 4;
int sensorR = A5;

const int THRESHOLD = 200;
int edgeState;
int direction;
int stop = 150;
void setup() {
  Serial.begin(9600);

  pinMode(ML1, INPUT);
  pinMode(ML3, INPUT);
  pinMode(sensorLF, INPUT);
  pinMode(sensorF, INPUT);
  pinMode(sensorRF, INPUT);
  pinMode(sensorL, INPUT);
  pinMode(sensorR, INPUT);

  Serial.begin(9600);
}


void loop() {
  delay(1500);
  // int direction = 0; 

  // checkOpponent(direction);
  // Serial.print("Opponent direction: ");
  // Serial.println(direction);
  //   // delay(200); 

  // if (direction != 0) {
  //   Serial.println("Attacking");
  //   attack(direction);
  //     //  delay(100); 

  // } else {
  //   Serial.println("No opponent detected.");
  //   xmotion.StopMotors(0); 
  // }

  // checkEdgeAndAvoid(); 
  // delay(100); 

  //main test2:
  checkOpponent(direction); // Update direction based on sensor readings

  if (direction == 0) {
    //hunt();
    edgeState = checkEdge();
    xmotion.Right0(100, 95);

    while (edgeState == 0 && direction == 0){
    xmotion.ArcTurn(14, 42, 15);
      if (direction != 0){
        break;
      }
      checkOpponent(direction);
      edgeState = checkEdge();
        if (edgeState != 0){
        break;
         }
      break;
    }
     avoidEdge(edgeState);
}
  while (true){
edgeState = checkEdge();
checkOpponent(direction); // Update direction based on sensor readings

  if (edgeState == 0 && direction !=0 ) {
  
    Serial.println("NO EDGE & opponent detected");
    do {
      attack(direction); 
      edgeState = checkEdge(); // Check for edges again
        if (edgeState != 0){
        break;
         }
        checkOpponent(direction); // Update direction based on sensor readings
    } while (direction != 0); // Exit loop if opponent is detected or edge is detected
    // standStill(700);
    hunt();
    Serial.println("EXIT MAIN LOOP");
    avoidEdge(edgeState);
    checkOpponent(direction); // Update direction based on sensor readings 
}

}
}
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
void checkOpponent(int &direction) {
  int sensorFv = digitalRead(sensorF);
  int sensorLv = digitalRead(sensorL);
  int sensorRv = digitalRead(sensorR);
  int sensorLFv = digitalRead(sensorLF);
  int sensorRFv = digitalRead(sensorRF);

  if (sensorFv == 1) {
    Serial.println("Detected front");
    direction = 1;
  } else if (sensorLv == 1) {
    Serial.println("Detected left");
    direction = 2;
  } else if (sensorRv == 1) {
    Serial.println("Detected right");
    direction = 3;
  } else if (sensorLFv == 1) {
    Serial.println("Detected left front");
    direction = 4;
  } else if (sensorRFv == 1) {
    Serial.println("Detected right front");
    direction = 5;
  } else {
    direction = 0; // None detected
  }
}

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

void forward_attack() {
  int edgeState = checkEdge();
  int direction = 0;  // Local variable to check real-time opponent detection

  checkOpponent(direction); 
  // if (direction == 1) {
  //   xmotion.Forward(100, 50);  // Move forward
  // } else {
  //   xmotion.StopMotors(0);  // Stop if no opponent is detected
  // }
  
  while (direction == 1) {
    checkOpponent(direction);  // Continuously check for opponent
    // if (direction == 0) { 
    //   xmotion.StopMotors(0);
    //   Serial.println("No opponent, stopping.");
    //   break;
    // }

    Serial.println("Before attacking");
    xmotion.Forward(50, 10);  // Move forward in small steps
    Serial.println("After attacking");

    edgeState = checkEdge();
    if (edgeState != 0) {
      break;
    }
  }
  
  edgeState = checkEdge();
  if (edgeState != 0) {
    avoidEdge(edgeState);
  }
}

void checkEdgeAndAvoid() {
  int edgeState = checkEdge();
  if (edgeState != 0) {
    avoidEdge(edgeState);
  }
}int checkEdge() {
    delay(10);
    int sensorV[3]; 

    sensorV[0] = analogRead(ML1); // FL
    sensorV[1] = analogRead(ML2); // back
    sensorV[2] = analogRead(ML3); // FRONT RIGHT

   
    int threshold = 350;
    int thresholdB = 500;


    // 1 = robot is at edge, 0 = safe)
    sensorV[0] = (sensorV[0] < threshold) ? 1 : 0; // FL
    sensorV[1] = (sensorV[1] < thresholdB) ? 1 : 0; // B
    sensorV[2] = (sensorV[2] < threshold) ? 1 : 0; // Front Right

    int state = 0; // Default: robot is safe

    if (sensorV[0] == 0 && sensorV[1] == 0 && sensorV[2] == 0) {
        state = 0;
        Serial.println("Robot is safe - No edge detected");
    } else if (sensorV[0] == 1 && sensorV[2] == 0) {
        state = 1;
        Serial.println("Front left is at edge");
    } else if (sensorV[1] == 1) {
        state = 2;
        Serial.println("Back  is at edge");
    } else if (sensorV[2] == 1 && sensorV[0] == 0) {
        state = 3;
        Serial.println("Front right is at edge");
    } else if (sensorV[0] == 1 && sensorV[2] == 1) {
        state = 4;
        Serial.println("Both front sensors are at edge");
    }

    // Print sensor values for debugging
    printSensorValues();

    return state;
}

void printSensorValues() {
    int sensorFL = analogRead(ML1); // Front Left
    int sensorB  = analogRead(ML2); // Back
    int sensorFR = analogRead(ML3); // Front Right

    Serial.print("FL: "); Serial.print(sensorFL);
    Serial.print(" | B: "); Serial.print(sensorB);
    Serial.print(" | FR: "); Serial.println(sensorFR);
   
}
 

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

