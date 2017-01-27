// TimeOut.h

#ifndef _TIMEOUT_h
#define _TIMEOUT_h

#include "arduino.h"


class TimeOut
{
	unsigned ms;
	unsigned long overflow;

public:
	TimeOut (unsigned ms);

	inline operator bool () const { return millis() >= overflow; };

	void Reset ();
	void Reset (unsigned ms);

private:
	// No copy possible.
	TimeOut (const TimeOut &c);
	TimeOut& operator = (const TimeOut &c);
};

#endif

