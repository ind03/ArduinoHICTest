// PulseBittest.h

#ifndef _PULSEBITTEST_h
#define _PULSEBITTEST_h

#include "arduino.h"
#include "Menu.h"


class PulseBitTest : public ParentMenu
{
private:
	class PulseBitLow : public SubMenu
	{
		friend class PulseBitTest;

	private:
		PulseBitLow (ParentMenu const *parent, SubMenu const &right);

	public:
		virtual void Activate ();
		virtual void Select ();
		virtual void Execute ();
	};

	class PulseBitHigh : public SubMenu
	{
		friend class PulseBitTest;

	private:
		PulseBitHigh (ParentMenu const *parent, SubMenu const &left);

	public:
		virtual void Activate ();
		virtual void Select ();
		virtual void Execute ();
	};

private:
	PulseBitLow pulseBitLow;
	PulseBitHigh pulseBitHigh;

public:
	PulseBitTest ();

	virtual void Activate ();
	virtual void Select ();
	virtual void Execute ();
};



#endif

