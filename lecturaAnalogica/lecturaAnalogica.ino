#define pinGas 5
#define pinRef 28
// #define pinTemp 29

#include <bluefruit.h>

void setup() {
  Serial.begin(115200);
  while ( !Serial ) delay(10);

  Bluefruit.begin();
  println("//()()()()()()()()()()()\\");
  println("  Bluefruit inicializada");
  println("\\()()()()()()()()()()()//");
  println();
  println();
}

void loop() {
  float vGas = AnalogRead(pinGas);
  float vRef = AnalogRead(pinRef);

  print("vGas: ");
  println(vGas);  
  print("vRef: ")
  println(vRef);
  println();
  println("---------------------------------");
  println("---------------------------------");
  println();

  delay(2000);
}
