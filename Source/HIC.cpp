#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#include "HIC.h"

#define	SPACE_TIME		(100)
#define LOW_TIME		(SPACE_TIME/2)
#define	HIGH_TIME		((3*SPACE_TIME)/2)
#define	STOP_TIME		(2*SPACE_TIME)

// Open Collector Output, output register assumed to be low.
#define HIC_DDR		__CONCAT(DDR, HIC_Port)
#define HIC_PORT	__CONCAT(PORT, HIC_Port)

#define HIC_Clear()		HIC_PORT &= ~BS(HIC_Pin)
#define HIC_SetLow()	HIC_DDR |=   BS(HIC_Pin)
#define HIC_SetHigh()	HIC_DDR  &= ~BS(HIC_Pin)


//================================================================================
HIC hic;

//================================================================================
/// <summary>
/// Initializes the HIC.
/// </summary>
HIC::HIC ()
{
	CLIPUSH ();

	// Set the pin to tri-state high;
	HIC_SetHigh ();
	HIC_Clear ();

	SEIPOP ();
}

void HIC::StartPulse ()
{
	CLIPUSH ();

	// Start bit
	HIC_SetLow ();
	_delay_us (SPACE_TIME);
	HIC_SetHigh ();
	_delay_us (SPACE_TIME);

	SEIPOP ();
}

void HIC::LowPulse ()
{
	CLIPUSH ();

	// Start the bit
	HIC_SetLow ();

	// Low part of Bit
	_delay_us (LOW_TIME);

	// High part of bit
	HIC_SetHigh ();
	_delay_us (SPACE_TIME);

	SEIPOP ();
}

void HIC::HighPulse ()
{
	CLIPUSH ();
	// Start the bit
	HIC_SetLow ();

	// Low part of Bit
	_delay_us (HIGH_TIME);

	// High part of bit
	HIC_SetHigh ();
	_delay_us (SPACE_TIME);

	SEIPOP ();
}

//______________________________________________________
void HIC::print (char c)
{
	byte mask;

	// Start bit
	CLIPUSH ();
	HIC_SetLow ();
	_delay_us (SPACE_TIME);
	HIC_SetHigh ();
	SEIPOP ();
	_delay_us (SPACE_TIME);

	// Send bits, MSF first
	for (mask = 0x80; mask; mask >>= 1)
	{
		CLIPUSH ();
		// Start the bit
		HIC_SetLow ();

		// High Bit
		if (c & mask)
			_delay_us (HIGH_TIME);
		else
			_delay_us (LOW_TIME);

		// Hich part of bit
		HIC_SetHigh ();
		SEIPOP ();
		_delay_us (SPACE_TIME);
	}

	// Send stop bit
	_delay_us (STOP_TIME);
}

//______________________________________________________
static char HexDigit (byte b)
{
	if (b <= 9)
		return '0' + b;
	else
		return ('A' - 10) + b;
}

//______________________________________________________
void HIC::print (const char *record)
{
	while (*record)
		print (*(record++));
}

//______________________________________________________
void HIC::print (const __FlashStringHelper * record)
{
	char c, *r = (char*)record;
	while (c = pgm_read_byte (r++))
		print (c);
}

//______________________________________________________
void HIC::print (unsigned char b, byte mode)
{
	if (mode == HEX)
	{
		print (HexDigit (b >> 4));
		print (HexDigit (b & 0x0F));
	}
	else
	{
		char bfr[8];

		itoa (b, bfr, 10);
		print (bfr);
	}
}

void HIC::print (int i, byte mode)
{
	char bfr[8];

	itoa (i, bfr, mode);
	print (bfr);
}

void HIC::print (unsigned int u, byte mode)
{
	char bfr[8];

	utoa (u, bfr, mode);
	print (bfr);
}