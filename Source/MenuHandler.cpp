// 
// 
// 

#include "MenuHandler.h"
#include "LCDKeys.h"


MenuHandler::MenuHandler (Menu &menu)
	: actual(&menu)
{
}

void MenuHandler::begin ()
{
	actual->Activate ();
}

void MenuHandler::HandleKeys ()
{
	// depending on which button was pushed, we perform an action
	switch (LCDKey::Pressed ())
	{
		//  push button "RIGHT"
		case LCDKeys::Right:
		{
			ActivateMenu (actual->Right ());
			break;
		}
		//  push button "LEFT"
		case LCDKeys::Left:
		{
			ActivateMenu (actual->Left ());
			break;
		}
		// push button "UP"
		case LCDKeys::Up:
		{
			ActivateMenu (actual->Up ());
			break;
		}
		//  push button "DOWN"
		case LCDKeys::Down:
		{
			ActivateMenu (actual->Down ());
			break;
		}
		//  push button "SELECT"
		case LCDKeys::Select:
		{
			actual->Select ();
			break;
		}
		default:
			break;
	}

}

void MenuHandler::Execute ()
{
	if (actual)
		actual->Execute ();
}

void MenuHandler::ActivateMenu (Menu const* menu)
{
	if (!menu)
		return;

	actual = (Menu*) menu;
	actual->Activate ();
}
