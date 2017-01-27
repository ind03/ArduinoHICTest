// 
// 
// 

#include "TimeTest.h"
#include "LiquidCrystal.h"
#include "HIC.h"
#include "Mode.h"

extern LiquidCrystal lcd;


static void PrintTime ()
{
	unsigned time = (unsigned)(millis () / 1000);

	hic.print (F ("Time "));
	hic.print (time);
	hic.print ('\n');

	lcd.setCursor (10, 1);
	lcd.print (time);
}


void TimeTest::Activate ()
{
	lcd.clear ();
	lcd.print (F ("Print Time"));
	Mode::Show ();
}

void TimeTest::Select ()
{
	Mode::Next ();
}

void TimeTest::Execute ()
{
	Mode::Execute (PrintTime);
}
