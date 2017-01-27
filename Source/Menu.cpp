// 
// 
// 

#include "Menu.h"

// ----------------------------------------------------------------------------
void Menu::Activate ()
{
}

void Menu::Select ()
{
}

void Menu::Execute ()
{
}

// ----------------------------------------------------------------------------
MainMenu::MainMenu ()
	: previous (nullptr), next (nullptr)
{
}

void MainMenu::Add (MainMenu & menu)
{
	if (next != nullptr)
		((MainMenu*)next)->Add (menu);
	else
	{
		next = &menu;
		menu.previous = this;
	}
}

const Menu * MainMenu::Up () const
{
	return previous;
}

const Menu * MainMenu::Down () const
{
	return next;
}

const Menu * MainMenu::Left () const
{
	return nullptr;
}

const Menu * MainMenu::Right () const
{
	return nullptr;
}


// ----------------------------------------------------------------------------

ParentMenu::ParentMenu (Menu const *_left, Menu const *_right)
: left (_left), right (_right)
{

}

const Menu * ParentMenu::Left () const
{
	return left;
}

const Menu * ParentMenu::Right () const
{
	return right;
}

SubMenu::SubMenu (ParentMenu const & _parent, SubMenu const *_previous, SubMenu const *_next)
	: parent (&_parent),
	  previous (_previous),
	  next (_next)
{
}

const Menu * SubMenu::Up () const
{
	return parent->Up ();
}

const Menu * SubMenu::Down () const
{
	return parent->Down ();
}

const Menu * SubMenu::Left () const
{
	return previous == nullptr ? parent : previous;
}

const Menu * SubMenu::Right () const
{
	return next == nullptr ? parent : next;
}

