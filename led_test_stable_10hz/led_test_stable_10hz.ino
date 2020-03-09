
#include <stdio.h>

int led = 13;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.println("START");
}

void loop() {
  int num = 5;
  int count = 7;
  byte data[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  Serial.println();

  while (num > 0) {
    Serial.println();
    Serial.print("NUM: \t");
    Serial.print(num);
    data[count] = num >> 1;
    num = num >>1;
    count -= 1;
  }
  Serial.println();

  for (int i = 0; i < 8; i ++) {
    Serial.print(data[i]);
    Serial.print("\t");
  }
  
  for ( int i = 0; i < 8; i++) {
    if (data[i] == 1) {
      digitalWrite(led, HIGH);
      delay(200);
    } else {
      digitalWrite(led, LOW);
      delay(200);
    }
  }
  delay(2000);
}
