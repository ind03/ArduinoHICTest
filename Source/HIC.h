// HIC.h

#ifndef _HIC_h
#define _HIC_h

#include "arduino.h"

#include <avr/pgmspace.h>
#include <Heiko.h>



#define HIC_Port	D
#define HIC_Pin		2

class __FlashStringHelper;

//================================================================================
class HIC
{
public:
	HIC ();

	static void StartPulse ();
	static void LowPulse ();
	static void HighPulse ();

	static void print (const char *record);
	static void print (const __FlashStringHelper * record);
	static void print (char c);
	static void print (unsigned char b, byte mode = HEX);
	static void print (int i, byte mode = DEC);
	static void print (unsigned int u, byte mode = DEC);
};

extern HIC hic;

#endif

