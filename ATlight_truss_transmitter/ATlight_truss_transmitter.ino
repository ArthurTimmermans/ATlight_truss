#include <NewPing.h>

#define TRIGGER 12
#define ECHO 11
#define MAX_DISTANCE 999

NewPing sonar(TRIGGER, ECHO, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(500);
  int uS = sonar.ping();
  int CM = (uS/US_ROUNDTRIP_CM);
  Serial.println(CM);
}
