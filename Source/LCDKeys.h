// LCDKeys.h

#ifndef _LCDKEYS_h
#define _LCDKEYS_h

#include "arduino.h"


enum LCDKeys
{
	None, Select, Left, Down, Up, Right
};

class LCDKey
{
public:
	static LCDKeys Read ();
	static LCDKeys Pressed ();
	static LCDKeys Released ();
};

#endif

