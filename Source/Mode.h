// Mode.h

#ifndef _MODE_h
#define _MODE_h

#include "arduino.h"

class Mode
{
public:

	static void Show ();
	static void Next ();
	static void ShowStar ();
	static void ClearStar ();
	static void Execute (void (*pulse)());
};

#endif

