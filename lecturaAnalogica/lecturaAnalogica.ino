#define pinGas 5
#define pinRef 28
// #define pinTemp 29

#include <bluefruit.h>

void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(10);

  Bluefruit.begin();
  Serial.println("//()()()()()()()()()()()\\");
  Serial.println("  Bluefruit inicializada");
  Serial.println("\\()()()()()()()()()()()//");
  Serial.println();
  Serial.println();
}

void loop() {
  float vGas = analogRead(pinGas);
  float vRef = analogRead(pinRef);

  float voltios = abs((vGas - vRef) / pow(2, 10) * 3.3);

  Serial.print("vGas = ");
  Serial.println(vGas);  
  Serial.print("vRef = ");
  Serial.println(vRef);
  Seria.print("Voltios: ")
  Serial.println(voltios);
  Serial.println();
  Serial.println("---------------------------------");
  Serial.println("---------------------------------");

  delay(2000);
}
