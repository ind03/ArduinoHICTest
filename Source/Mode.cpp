// 
// 
// 

#include "Mode.h"
#include "LiquidCrystal.h"
#include "TimeOut.h"


extern LiquidCrystal lcd;


// ----------------------------------------------------------------------------
// Common Mode Handling
// ----------------------------------------------------------------------------
enum PBTMode
{
	Fast, Second, Millisecond
};


static PBTMode mode = Fast;
static TimeOut timeOut (0);

static void SetMode (PBTMode newMode)
{
	mode = newMode;
	lcd.setCursor (0, 1);
	switch (mode)
	{
		case Fast:
			lcd.print (F ("Fast      "));
			timeOut.Reset (0);
			break;
		case Second:
			lcd.print (F ("1 Second  "));
			timeOut.Reset (1000);
			break;
		case Millisecond:
			lcd.print (F ("0.1 Second"));
			timeOut.Reset (1);
			break;
	};
}


void Mode::Show ()
{
	SetMode (mode);
}

void Mode::Next ()
{
	if (mode == Fast)
		SetMode (Second);
	else if (mode == Second)
		SetMode (Millisecond);
	else
		SetMode (Fast);
}

void Mode::ShowStar ()
{
	lcd.setCursor (15, 1);
	lcd.write ('*');
}


void Mode::ClearStar ()
{
	lcd.setCursor (15, 1);
	lcd.write (' ');
}

void Mode::Execute (void (*pulse)())
{
	switch (mode)
	{
		case Fast:
			pulse ();
			break;
		case Second:
			if (timeOut)
			{
				ShowStar ();
				pulse ();
				delay (100);
				timeOut.Reset ();
				ClearStar ();
			}
			break;
		case Millisecond:
			if (timeOut)
			{
				ShowStar ();
				pulse ();
				timeOut.Reset ();
				ClearStar ();
			}
			break;
	};
}
