#include <Arduino.h>
#include <Wire.h>

// Tetapkan pin I2C kustom
#define SDA_PIN D5 // GPIO16
#define SCL_PIN D4 // GPIO5

void setup()
{
  Serial.begin(9600);
  Wire.begin(SDA_PIN, SCL_PIN); // Mulai komunikasi I2C pada pin kustom
  Serial.println("Memulai I2C Scanner...");
}

void loop()
{
  byte error, address;
  int nDevices;
  nDevices = 0;

  Serial.println("Mencari perangkat I2C...");

  for (address = 1; address < 127; address++)
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("Perangkat I2C ditemukan di alamat 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4)
    {
      Serial.print("Kesalahan tak dikenal di alamat 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }

  if (nDevices == 0)
    Serial.println("Tidak ada perangkat I2C ditemukan.\n");
  else
    Serial.println("Pencarian selesai.\n");

  delay(5000); // Tunggu 5 detik sebelum scan ulang
}