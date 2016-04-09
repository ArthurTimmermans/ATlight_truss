void setup() {
  for(int x=22; x<40; x++){
    pinMode(x, OUTPUT);
  }
  Serial.begin(9600);
  //testLights();
  //lightsOff();
}

void loop() {
  countdown();
}

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
void lightsOff(){
  for(int numOff=22; numOff<40; numOff++){
   digitalWrite(numOff, LOW); 
  }
}

void countdown(){
  for(int countNum=99; countNum>= 0; countNum--){
    int digit1 = countNum/10;
    int digit2 = countNum-(countNum/10)*10;
    numberTranslate(digit1, digit2);
    delay(100);
    lightsOff();
  }
  
}

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
