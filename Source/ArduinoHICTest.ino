/*************************************************************************************

Mark Bramwell, July 2010

This program will test the LCD panel and the buttons.When you push the button on the shield?
the screen will show the corresponding one.

Connection: Plug the LCD Keypad to the UNO(or other controllers)

**************************************************************************************/
#include "TimeTest.h"
#include "HelloTest.h"
#include "Mode.h"
#include "TimeOut.h"
#include "PulseBittest.h"
#include <LiquidCrystal.h>
#include "LCDKeys.h"
#include "Menu.h"
#include "MenuHandler.h"
#include "HIC.h"

LiquidCrystal lcd (8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel
												// define some values used by the panel and buttons


PulseBitTest mainMenu;
HelloTest helloMenu;
TimeTest timeMenu;
MenuHandler menuHandler (mainMenu);

int lcd_key = 0;


void setup ()
{
	Serial.begin (115200);
	Serial.println (F ("ArduinoHICTest"));

	lcd.begin (16, 2);               // start the library


	mainMenu.Add (helloMenu);
	mainMenu.Add (timeMenu);
	menuHandler.begin ();
}

void loop ()
{
	menuHandler.HandleKeys ();
	menuHandler.Execute ();
}