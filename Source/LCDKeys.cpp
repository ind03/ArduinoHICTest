//	 
// DF Robot 16×2 LCD Keypad Shield Keys (analog). 
// 

#include "LCDKeys.h"

static LCDKeys lastRead;

LCDKeys LCDKey::Read ()
{
	unsigned adc_key_in = analogRead (0);       // read the value from the sensor 

									   // my buttons when read are centered at these valies: 0, 144, 329, 504, 741
									   // we add approx 50 to those values and check to see if we are close
									   // We make this the 1st option for speed reasons since it will be the most likely result

	if (adc_key_in > 1000) return LCDKeys::None;

	// For V1.1 us this threshold
	if (adc_key_in < 50)   return LCDKeys::Right;
	if (adc_key_in < 250)  return LCDKeys::Up;
	if (adc_key_in < 450)  return LCDKeys::Down;
	if (adc_key_in < 650)  return LCDKeys::Left;
	if (adc_key_in < 850)  return LCDKeys::Select;

	return LCDKeys::None;                // when all others fail, return this.

}

LCDKeys LCDKey::Pressed ()
{
	LCDKeys key = Read ();
	if (key == lastRead)
		return LCDKeys::None;

	return lastRead = key;
}

LCDKeys LCDKey::Released ()
{
	LCDKeys key = Read (), last;

	if (key == lastRead)
		last = LCDKeys::None;
	else
		last = lastRead;

	lastRead = key;
	return last;
}
