/**************************************************************************************

This is example for MAX30205 Human Body Temperature Sensor Breakout


Hardware connections for Arduino Uno:
	VDD to 3.3V DC
	SCL to A5
	SDA to A4
	GND to common ground

Written by IshaSheikh for LVLalpha


**************************************************************************************/

#include <Wire.h>
#include "MAX30205.h"

MAX30205 max30205;

void setup()
{
	Serial.begin(9600);
	Serial.println("ClosedCube MAX30205 Arduino Demo");
	/*instruction------
	go the header file and change the SLAVE_ADD value according to how the IC's A0, A1, A2 are connected accoeding to the follwing table

A2 		A1 		A0		SLAVE_ADD
GND 	GND 	GND 	90h
GND 	GND 	VDD 	92h
GND 	GND 	SCL 	82h
GND 	GND 	SDA 	80h
GND 	VDD 	GND 	94h
GND 	VDD 	VDD 	96h
GND 	VDD 	SCL 	86h
GND 	VDD 	SDA 	84h
GND 	SCL 	GND 	B4h
GND 	SCL 	VDD 	B6h
GND 	SCL 	SCL 	A6h
GND 	SCL 	SDA 	A4h
GND 	SDA 	GND 	B0h
GND 	SDA 	VDD 	B2h
GND 	SDA 	SCL 	A2h
GND 	SDA 	SDA 	A0h
VDD 	GND 	GND 	98h
VDD 	GND 	VDD 	9Ah
VDD 	GND 	SCL 	8Ah
VDD 	GND 	SDA 	88h
VDD 	VDD 	GND 	9Ch
VDD 	VDD 	VDD 	9Eh
VDD 	VDD 	SCL 	8Eh
VDD 	VDD 	SDA 	8Ch
VDD 	SCL 	GND 	BCh
VDD 	SCL 	VDD 	BEh
VDD 	SCL 	SCL 	AEh
VDD 	SCL 	SDA 	ACh
VDD 	SDA 	GND 	B8h
VDD 	SDA 	VDD 	BAh
VDD 	SDA 	SCL 	AAh
VDD 	SDA 	SDA 	A8h
	*/


	max30205.begin();
}

void loop()
{
	Serial.print("T=");
	Serial.print(max30205.readTemperature());
	Serial.println("C");
	delay(300);
}

