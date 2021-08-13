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
#include "BetLevel2.h"

BetLevel2::BetLevel2()
{
	betMultiplier = 2; //define the bet multiplier
	setWager(200);
}

int BetLevel2::evaluateReels()
{
	return SlotMachine::evaluateReels() * betMultiplier; //1 is the bet level multiplier
}

void BetLevel2::setBetMultiplier(int value)
{
	betMultiplier = value;
}

void BetLevel2::setWager(int value)
{
	wager = 200;
}