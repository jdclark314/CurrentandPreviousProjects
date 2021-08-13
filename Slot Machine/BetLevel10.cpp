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
#include "BetLevel10.h"

BetLevel10::BetLevel10()
{
	betMultiplier = 10; //define the bet multiplier
	setWager(1000);
}

int BetLevel10::evaluateReels()
{
	return SlotMachine::evaluateReels() * betMultiplier; //1 is the bet level multiplier
}

void BetLevel10::setBetMultiplier(int value)
{
	betMultiplier = value;
}

void BetLevel10::setWager(int value)
{
	wager = 1000;
}