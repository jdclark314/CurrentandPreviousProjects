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
#include "BetLevel1.h"

BetLevel1::BetLevel1()
{
	betMultiplier = 1; //define the bet multiplier
	setWager(100);
}

int BetLevel1::evaluateReels()
{
	return SlotMachine::evaluateReels() * betMultiplier; //1 is the bet level multiplier
}

void BetLevel1::setBetMultiplier(int value)
{
	betMultiplier = value;
}

void BetLevel1::setWager(int value)
{
	wager = 100;
}