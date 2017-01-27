// Menu.h

#ifndef _MENU_h
#define _MENU_h

#include <arduino.h>

class Menu
{
public:
	virtual const Menu* Up () const = 0;
	virtual const Menu* Down () const = 0;
	

	virtual const Menu* Left () const = 0;
	virtual const Menu* Right () const = 0;

	virtual void Activate ();
	virtual void Select ();
	virtual void Execute ();
};

class MainMenu : public Menu
{
	Menu *previous;
	Menu *next;

public:
	MainMenu ();
	
	void Add (MainMenu &menu);

	virtual const Menu* Up () const;
	virtual const Menu* Down () const;


	virtual const Menu* Left () const;
	virtual const Menu* Right () const;
};


class ParentMenu : public MainMenu
{
	Menu const *left;
	Menu const *right;

protected:
	ParentMenu (Menu const *left, Menu const *right);

public:
	virtual const Menu* Left () const;
	virtual const Menu* Right () const;
};


class SubMenu : public Menu
{
	ParentMenu const *parent;
	Menu const *previous;
	Menu const *next;

public:
	SubMenu (ParentMenu const &parent, SubMenu const *previous, SubMenu const *next);

	virtual const Menu* Up () const;
	virtual const Menu* Down () const;


	virtual const Menu* Left () const;
	virtual const Menu* Right () const;
};

#endif

