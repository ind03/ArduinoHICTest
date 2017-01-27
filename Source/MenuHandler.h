// MenuHandler.h

#ifndef _MENUHANDLER_h
#define _MENUHANDLER_h

#include "arduino.h"
#include "Menu.h"


class MenuHandler
{
private:
	Menu* actual;

 protected:


 public:
	MenuHandler (Menu &menu);

	void begin ();
	void HandleKeys ();
	void Execute ();

private:
	void ActivateMenu (Menu const *menu);
};

#endif

