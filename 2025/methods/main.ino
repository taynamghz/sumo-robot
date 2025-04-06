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
