/*
Jonathan S. Weissman
CIS 554-M401 Object Oriented Programming in C++
Syracuse University
Final Project
3/25/21

This program plays a slot machine game that demonstrates the polymorphic abilties of C++.

Author: Jamie Clark
*/

#include "SlotMachine.h"
#include <vector>
#include <iostream>
#include "BetLevel1.h"
#include "BetLevel2.h"
#include "BetLevel3.h"
#include "BetLevel5.h"
#include "BetLevel10.h"

int playTheGame(SlotMachine* value)
{
	int outCome{ value->evaluateReels() }; //polymorphism here
	if (outCome > 0) //win condition check
	{
		std::cout << "You won " << outCome << "! \n \n";
		return outCome;
	}
	else
	{ //player losses here
		std::cout << "Play Again! \n \n"; 
		return 0;
	}
}

int main()
{
	//std::cout << "hello";

	SlotMachine player1; //define player

	//adding bet level adding and usage
	BetLevel1 level1;
	BetLevel2 level2;
	BetLevel3 level3;
	BetLevel5 level5;
	BetLevel10 level10;
	std::vector<SlotMachine*> betLevels{ &level1, &level2, &level3, &level5, &level10 };
	std::vector<int> creditValues{ 100, 200, 300, 500, 1000 };

	int betLevelSelect{};
	player1.startGame(); //get the bet level user wants

	while (player1.getCredits() > 0) //plays as long as the player has credits
	{
		betLevelSelect = player1.gameOptionSelect(); //allows user to play again
		player1.setCredits(player1.getCredits() - creditValues[betLevelSelect - 1]); //subtract correct credits
		player1.setCredits(player1.getCredits() + playTheGame(betLevels[betLevelSelect - 1])); //polymorphism call here
		if (player1.getCredits() < 100) //player doens't have enough money to play again
		{
			break;
		}
	}

	std::cout << "Come back and see us real soon! \n";

	
}