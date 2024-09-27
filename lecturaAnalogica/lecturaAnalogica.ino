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
  
  float cGas = (vGas - vRef) / (-35,35 * 499 * pow(10, 6));

  Serial.print("vGas = ");
  Serial.println(vGas);  
  Serial.print("vRef = ");
  Serial.println(vRef);
  Seria.print("Voltios: ")
  Serial.println(voltios);
  Serial.print("cGas = ");
  Serial.print(cGas);
  Serial.println(" ppm");
  Serial.println();
  Serial.println("---------------------------------");
  Serial.println("---------------------------------");

  delay(2000);
}
