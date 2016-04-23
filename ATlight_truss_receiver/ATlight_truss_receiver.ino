#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 300

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int toneVal = 1;
int tonePin = 8;
int pingPrev[] = {9,0,0};

void setup() {
  
  // Setting segment display pins to output
  for(int x=22; x<40; x++){
    pinMode(x, OUTPUT);
  }
  pinMode(tonePin, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  // Start serial
  Serial.begin(9600);
  while(!Serial){
    ;
  }
}

void loop() {
  distance();
  beep();
  delay(1);
}

// Get the distance
void distance(){
  int pingDistance = sonar.ping_cm();
  int pingM = pingDistance/100;
  int pingDm = pingDistance/10;
  if(pingDm >= 10){
    pingDm = pingDm - 10;
  }else if(pingDm >= 20){
    pingDm = pingDm - 20;
  }else if(pingDm >= 30){
    pingDm = pingDm - 30;
  }else if(pingDm >= 50){
    pingDm = pingDm - 50;
  }
  pingPrev[2] = pingPrev[1];
  pingPrev[1] = pingPrev[0];
  pingPrev[0] = pingDistance;
  if(pingPrev[0] == pingPrev[1] && pingPrev[1] == pingPrev[2]){
    lightsOff();
    numberTranslate(pingM, pingDm);
  }
  Serial.println(pingDm);
  /*
  Serial.print("Prev 1:");
  Serial.print(pingPrev[0]);
  Serial.print("  Prev 2:");
  Serial.print(pingPrev[1]);
  Serial.print("  Prev 3:");
  Serial.println(pingPrev[2]);
  */
}

//Beep algorithm
void beep(){
  
}
// Test all the segments from the 2 segment displays. 
void testLights(){
  for(int testLightsInt=22; testLightsInt<40; testLightsInt++){
    digitalWrite(testLightsInt, HIGH);
    digitalWrite(testLightsInt-1, LOW);
    delay(200);
  }
  for(int testLightsFull=22; testLightsFull<40; testLightsFull++){
    digitalWrite(testLightsFull, HIGH);
  }
}

// Turns segments from display off
void lightsOff(){
  for(int numOff=22; numOff<40; numOff++){
   digitalWrite(numOff, LOW); 
  }
}

// Counts down from 9.9 to 0.0
void countdown(){
  for(int countNum=99; countNum>= 0; countNum--){
    int digit1 = countNum/10;
    int digit2 = countNum-(countNum/10)*10;
    numberTranslate(digit1, digit2);
    delay(100);
    lightsOff();
  }
  
}

// Translate the numbers to segment display. 
void numberTranslate(int num2, int num1){
  digitalWrite(29, HIGH);
  switch(num2){
    case 0:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 1:
      digitalWrite(24, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 2:
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      break;
    case 3:
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 4:
      digitalWrite(22, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 5:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 6:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 7:
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 8:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
    case 9:
      digitalWrite(22, HIGH);
      digitalWrite(23, HIGH);
      digitalWrite(24, HIGH);
      digitalWrite(25, HIGH);
      digitalWrite(27, HIGH);
      digitalWrite(28, HIGH);
      break;
  }
  switch(num1){
    case 0:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 1:
      digitalWrite(34, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 2:
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      break;
    case 3:
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 4:
      digitalWrite(32, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 5:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 6:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 7:
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 8:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
    case 9:
      digitalWrite(32, HIGH);
      digitalWrite(33, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(35, HIGH);
      digitalWrite(37, HIGH);
      digitalWrite(38, HIGH);
      break;
  }
}
