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
#include <random>
#include <ctime>

class SlotMachine
{
	
	int credits; //how much money player has
	int win; //how much player won
	std::default_random_engine rng{ static_cast<unsigned int>(time(0)) }; //creates rng seeded at current time
	std::uniform_int_distribution<unsigned int> randomNum; //uniformly distributes the rng


public:
	int betMultiplier; //what to multiplier win amount by
	int wager; //bet amount

	void startGame(); //display starting screen options
	int gameOptionSelect(); //allow player to select bet level to play
	int userInputValidation(); //validate input

	SlotMachine(); //constructor

	virtual void setWager(); //derived classes need to modify
	int getWager(); //only base

	virtual void setBetMultiplier(int); //derived classes need to modify
	int getBetMultiplier(); //only base

	void setWin(int); //only base
	int getWin(); //only base

	void setCredits(int); //only base
	int getCredits(); //only base
	
	void spin(); //gets the rng result of the reels, only base

	virtual int evaluateReels(); //verifies to see if anything won
};