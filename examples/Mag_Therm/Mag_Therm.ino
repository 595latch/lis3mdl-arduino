/*
The sensor outputs provided by the library are the raw 16-bit values
obtained by concatenating the 8-bit high and low magnetometer data registers.
They can be converted to units of gauss using the
conversion factors specified in the datasheet for your particular
device and full scale setting (gain).

Example: An LIS3MDL gives a magnetometer X axis reading of 1292 with its
default full scale setting of +/- 4 gauss. The GN specification
in the LIS3MDL datasheet (page 8) states a conversion factor of 6842
LSB/gauss (where LSB means least significant bit) at this FS setting, so the raw
reading of 1292 corresponds to 1292 / 6842 = 0.1888 gauss.

modified from Pololu's Serial example to read the themometer inside the magnetometer
By Joel Murphy, Winter 2020
*/

#include <Wire.h>
#include <LIS3MDL.h>

LIS3MDL compass;


void setup()
{
  Serial.begin(9600);
  Wire.begin();

  if (!compass.init())
  {
    Serial.println("Failed to detect and initialize magnetometer!");
    while (1);
  }

  compass.enableDefault();
}

void loop()
{
  compass.read();

  Serial.print("X: "); Serial.print(compass.m.x,3);
	Serial.print("\tY: "); Serial.print(compass.m.y,3);
	Serial.print("\tZ: "); Serial.println(compass.m.z,3);

  delay(100);
}
