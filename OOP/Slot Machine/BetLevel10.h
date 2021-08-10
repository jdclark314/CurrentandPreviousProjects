/*
Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final Project
3/25/21

This program plays a slot machine game that demonstrates the polymorphic abilties of C++.

Author: Jamie Clark
*/

#pragma once

#include "SlotMachine.h"

class BetLevel10 : public SlotMachine
{

public:
	BetLevel10();
	virtual int evaluateReels();
	virtual void setBetMultiplier(int);
	virtual void setWager(int);

};