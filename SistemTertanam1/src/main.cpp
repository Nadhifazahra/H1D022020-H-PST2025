#include <Arduino.h>

int ALED = D0;
int BLED = D1;
int CLED = D3;

void setup()
{
  pinMode(ALED, OUTPUT);
  pinMode(BLED, OUTPUT);
  pinMode(CLED, OUTPUT);
}

void loop()
{
  digitalWrite(ALED, HIGH);
  delay(2000);
  digitalWrite(ALED, LOW);
  digitalWrite(BLED, HIGH);
  delay(2000);
  digitalWrite(BLED, LOW);
  digitalWrite(CLED, HIGH);
  delay(2000);
  digitalWrite(CLED, LOW);
}