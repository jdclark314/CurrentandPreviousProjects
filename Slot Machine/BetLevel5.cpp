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
#include "BetLevel5.h"

BetLevel5::BetLevel5()
{
	betMultiplier = 5; //define the bet multiplier
	setWager(500);
}

int BetLevel5::evaluateReels()
{
	return SlotMachine::evaluateReels() * betMultiplier; //1 is the bet level multiplier
}

void BetLevel5::setBetMultiplier(int value)
{
	betMultiplier = value;
}

void BetLevel5::setWager(int value)
{
	wager = 500;
}