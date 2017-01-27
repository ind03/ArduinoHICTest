// 
// 
// 

#include "TimeOut.h"

TimeOut::TimeOut (unsigned _ms)
	: ms (_ms), overflow (millis()+ms)
{
}

void TimeOut::Reset ()
{
	overflow = millis () + ms;
}

void TimeOut::Reset (unsigned _ms)
{
	ms = _ms;
	overflow = millis () + ms;
}
