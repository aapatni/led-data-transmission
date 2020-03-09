
#include <stdio.h>

int led = 13;
void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  Serial.println();
  Serial.println("START");
}

void loop() {
  int num = random(1, 128);
  int count = 7;
  byte data[8] = {0, 0, 0, 0, 0, 0, 0, 0};
  Serial.println();
  Serial.print("NUM: \t");
  Serial.print(num);
  Serial.println();

  while (num > 0) {
    if (num % 2 == 1) {
      data[count] = 1;
    }
    else {
      data[count]  = 0;
    }
    num = num >> 1;
    count -= 1;
  }
  data[0] = 1;
  Serial.println();

  for (int i = 0; i < 8; i ++) {
    Serial.print(data[i]);
    Serial.print("\t");
  }
  Serial.println();
  for ( int i = 0; i < 8; i++) {
    if (data[i] == 1) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
    delay(100);
  }
  delay(1000);
}
