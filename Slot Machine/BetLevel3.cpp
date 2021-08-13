/*
Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final Project
3/25/21

This program plays a slot machine game that demonstrates the polymorphic abilties of C++.

Author: Jamie Clark
*/

#include <iostream>
#include "BetLevel3.h"

BetLevel3::BetLevel3()
{
	betMultiplier = 3; //define the bet multiplier
	setWager(300);
}

int BetLevel3::evaluateReels()
{
	return SlotMachine::evaluateReels() * betMultiplier; //1 is the bet level multiplier
}

void BetLevel3::setBetMultiplier(int value)
{
	betMultiplier = value;
}

void BetLevel3::setWager(int value)
{
	wager = 300;
}