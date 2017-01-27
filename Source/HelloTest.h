// HelloTest.h

#ifndef _HELLOTEST_h
#define _HELLOTEST_h

#include "arduino.h"
#include "Menu.h"

class HelloTest : public MainMenu
{
public:
	virtual void Activate ();
	virtual void Select ();
	virtual void Execute ();
};


#endif

