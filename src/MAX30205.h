/*

Arduino Library for Maxim Integrated MAX30205 Human Body Temperature Sensor
Written by IshaSheikh for LVLalpha
---



*/

#ifndef MAX30205_h

#define MAX30205_h
#include <Arduino.h>

typedef enum {
	TEMPERATURE = 0x00,
	CONFIGURATION = 0x01,
	T_HYST = 0x02,
	T_OS = 0x03,
	SLAVE_ADD=0x00,
} MAX30205_Registers;

class MAX30205 {
public:
	MAX30205();

	void begin();

	float readTemperature();
	float readT(); // short-cut for readTemperature

private:
	uint8_t _address;
	uint16_t readData(uint8_t pointer);
};

#endif

