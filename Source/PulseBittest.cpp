// 
// 
// 

#include "PulseBittest.h"
#include "LiquidCrystal.h"
#include "HIC.h"
#include "Mode.h"

extern LiquidCrystal lcd;





// ----------------------------------------------------------------------------
PulseBitTest::PulseBitTest ()
	: ParentMenu (&pulseBitLow, &pulseBitHigh),
	pulseBitLow (this, pulseBitHigh),
	pulseBitHigh (this, pulseBitLow)
{
}

void PulseBitTest::Activate ()
{
	lcd.clear ();
	lcd.print (F ("Pulse Bit Start"));
	Mode::Show ();
}

void PulseBitTest::Select ()
{
	Mode::Next ();
}

void PulseBitTest::Execute ()
{
	Mode::Execute (hic.StartPulse);
}

// ----------------------------------------------------------------------------
PulseBitTest::PulseBitLow::PulseBitLow (ParentMenu const *parent, SubMenu const &right)
	: SubMenu (*parent, &right, nullptr)
{
}

void PulseBitTest::PulseBitLow::Activate ()
{
	lcd.clear ();
	lcd.print (F ("Pulse Bit Low"));
	Mode::Show ();
}

void PulseBitTest::PulseBitLow::Select ()
{	
	Mode::Next ();
}

void PulseBitTest::PulseBitLow::Execute ()
{
	Mode::Execute (hic.LowPulse);
}

// ----------------------------------------------------------------------------
PulseBitTest::PulseBitHigh::PulseBitHigh (ParentMenu const *parent, SubMenu const &left)
	: SubMenu (*parent, nullptr, &left)
{
}

void PulseBitTest::PulseBitHigh::Activate ()
{
	lcd.clear ();
	lcd.print (F ("Pulse Bit High"));
	Mode::Show ();
}

void PulseBitTest::PulseBitHigh::Select ()
{
	Mode::Next ();
}

void PulseBitTest::PulseBitHigh::Execute ()
{
	Mode::Execute (hic.HighPulse);
}

