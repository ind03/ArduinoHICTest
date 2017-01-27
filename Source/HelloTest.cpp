// 
// 
// 

#include "HelloTest.h"
#include "LiquidCrystal.h"
#include "HIC.h"
#include "Mode.h"

extern LiquidCrystal lcd;


static void PrintHello ()
{
	hic.print (F ("Hello\n"));
}

void HelloTest::Activate ()
{
	lcd.clear ();
	lcd.print (F ("Print Hello"));
	Mode::Show ();
}

void HelloTest::Select ()
{
	Mode::Next ();
}

void HelloTest::Execute ()
{
	Mode::Execute (PrintHello);
}
