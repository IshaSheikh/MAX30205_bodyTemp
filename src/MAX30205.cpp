/*

Arduino Library for Maxim Integrated MAX30205 Human Body Temperature Sensor
Written by IshaSheikh for LVLalpha
---


*/

#include <Wire.h>
#include "MAX30205.h"

MAX30205::MAX30205()
{
}

void MAX30205::begin() {
	_address = SLAVE_ADD;
	Wire.begin();

    /*
	Wire.beginTransmission(_address);
	Wire.write(CONFIGURATION);
	Wire.write(0x0);
	Wire.endTransmission();
    */
}

float MAX30205::readT() {
	return readTemperature();
}

float MAX30205::readTemperature() {
	uint16_t rawT = readData(TEMPERATURE);
	return (rawT * 0.00390625);
}

uint16_t MAX30205::readData(uint8_t pointer) {
	Wire.beginTransmission(_address);
	Wire.write(pointer);
	Wire.endTransmission();

	delay(10);
	Wire.requestFrom(_address, (uint8_t)2);

	byte msb = Wire.read();
	byte lsb = Wire.read();

	return msb << 8 | lsb;
}



