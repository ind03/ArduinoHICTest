// TimeTest.h

#ifndef _TIMETEST_h
#define _TIMETEST_h

#include "arduino.h"
#include "Menu.h"

class TimeTest : public MainMenu
{
public:
	virtual void Activate ();
	virtual void Select ();
	virtual void Execute ();
};



#endif

