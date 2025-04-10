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
