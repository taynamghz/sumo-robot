#include <xmotionV3.h>
#include "xmotionV3.h"


int ML1 = A4; // fl Micro Line Sensor
int ML2 = A1; // back
int ML3 = A2; // right  Micro Line Sensor

int sensorV[3] = {0, 0, 0};

int sensorLF = 0;
int sensorF = 1;
int sensorRF = 2;
int sensorL = 4;
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

  Serial.begin(9600); //Serial Interface started with 9600 bits per sec.
}

void loop() {
  
int edgeState = checkEdge();
if (edgeState != 0){
avoidEdge(edgeState);    }
  
while (true){
int edgeState = checkEdge();
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
    Serial.println("EXIT MAIN LOOP");
    avoidEdge(edgeState);
    checkOpponent(direction); // Update direction based on sensor readings 
}
if (direction == 0) {
    //hunt();
    edgeState = checkEdge();
    while (edgeState == 0 && direction == 0){
      xmotion.Forward(50, 10);
      checkOpponent(direction);
      if (direction != 0){
        break;
      }
      checkOpponent(direction);
      edgeState = checkEdge();
    }
    avoidEdge(edgeState);
    int time = 0;
    while(direction==0 && edgeState == 0)
    {  xmotion.Left0(60, 10);
    time = time + 10;
    if (time == 2000) {break;}
        //xmotion.ArcTurn(15, 30, 20);
         checkOpponent(direction); // Update direction based on sensor readings
         edgeState = checkEdge();
      }    
   avoidEdge(edgeState);
  }
}
}
}

int checkEdge() {
    delay(10);
    int sensorV[3]; // Array to store sensor values

    sensorV[0] = analogRead(ML2); // BACK
    sensorV[1] = analogRead(ML1); // FRONT LEFT
    sensorV[2] = analogRead(ML3); // FRONT RIGHT

    // Threshold for detecting an edge
    int threshold = 200;

    // Assign sensor states (1 = edge detected, 0 = safe)
    sensorV[0] = (sensorV[0] < threshold) ? 1 : 0; // Back
    sensorV[1] = (sensorV[1] < threshold) ? 1 : 0; // Front Left
    sensorV[2] = (sensorV[2] < threshold) ? 1 : 0; // Front Right

    int state = 0; // Default: robot is safe

    if (sensorV[0] == 0 && sensorV[1] == 0 && sensorV[2] == 0) {
        state = 0;
        Serial.println("Robot is safe - No edge detected");
    } else if (sensorV[1] == 1 && sensorV[2] == 0) {
        state = 1;
        Serial.println("Front left is at edge");
    } else if (sensorV[0] == 1) {
        state = 2;
        Serial.println("Back sensor is at edge");
    } else if (sensorV[2] == 1 && sensorV[1] == 0) {
        state = 3;
        Serial.println("Front right is at edge");
    } else if (sensorV[1] == 1 && sensorV[2] == 1) {
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
    delay(800);
}


void avoidEdge(int &edgeState) {
    while (edgeState != 0) {
        switch (edgeState) {
            case 4: // Both front sensors detected an edge
                xmotion.Backward(100, 400);
                xmotion.Left0(50, 300);
                xmotion.StopMotors(0);
                break;

            case 3: // Front right detected an edge
                xmotion.Backward(100, 400);
                xmotion.Left0(50, 200);
                xmotion.StopMotors(0);
                break;

            case 2: // Back sensor detected an edge
                xmotion.Forward(100, 400);
                xmotion.StopMotors(0);
                break;

            case 1: // Front left detected an edge
                xmotion.Backward(100, 400);
                xmotion.Right0(50, 200);
                xmotion.StopMotors(0);
                break;
        }

        // Re-check edge state
        edgeState = checkEdge();
    }
}
