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
#include <vector>
#include <random>
#include <ctime>
#include "SlotMachine.h"

using std::cout;
using std::cin;

SlotMachine::SlotMachine()
{
	credits = 5000;
	wager = 1;
	betMultiplier = 1;
	win = 0;
	//no function here yet
}

void SlotMachine::startGame()
{
	cout << "Welcome to the OOP Casino! \n";
	cout << "You have been awarded with 5,000 Credits! \n";
	cout << "Let's play a game to win fabulous prizes! \n";
	cout << "In order to start winning, you must get 8 or more S's! \n \n";
	//return gameOptionSelect(); //get the game selection going

} //end startGame()


int SlotMachine::gameOptionSelect()
{
	cout << "You currently have " << credits << " credits!\n";
	cout << "Choose one of the following bet levels to play: \n"; 
	cout << "1 (100 credits)   2 (200 credits)   3 (300 credits)   4 (500 credits)   5 (1000 credits)\n";
	int userSelection{ 0 };
	userSelection = userInputValidation();
	//this will keep track of the credit values to show the player
	std::vector<int> creditValues{ 100, 200, 300, 500, 1000 }; 

	cout << "You have choosen " << userSelection << " for " << creditValues[userSelection - 1] << " credits!\n";
	return userSelection;
} //end gameOptionSelect()

int SlotMachine::userInputValidation()
{
	int num{ 0 };
	while (!(cin >> num)) //goes until the user inters an int
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid Number! \n";
		cout << "Please Try Again with a number between 1-5! \n";
		cout << "Enter the Number Again: ";
		cin.clear();
	}

	if (num < 1 || num > 5) //checks that the int is now within range
	{
		cout << "Invalid Number! \n";
		cout << "Please Try Again with a number between 1-5! \n";
		cout << "Enter the Number Again: ";
		num = userInputValidation(); //run this function again if not in range
	}

	return num;
} //end userInputValidation()

void SlotMachine::setWager()
{
	wager = 0;
}

int SlotMachine::getWager()
{
	return wager;
}

void SlotMachine::setBetMultiplier(int value)
{
	betMultiplier = value;
}

int SlotMachine::getBetMultiplier()
{
	return betMultiplier;
}

void SlotMachine::setWin(int value)
{
	win = value;
}

int SlotMachine::getWin()
{
	return win;
}

void SlotMachine::setCredits(int value)
{
	credits = value;
}

int SlotMachine::getCredits()
{
	return credits;
}

int SlotMachine::evaluateReels()
{
	setCredits(credits - wager);
	//steps
	//create reel strips
	int rows{ 3 }; //3 rows to be used
	int cols{ 5 }; //5 columns
	int winCounter{ 0 }; //adds up the number of win symbols displayed
	//generate the array of reels to display
	std::vector<std::vector<std::string>> reels(rows, std::vector<std::string>(cols));
	std::cout << "\n"; //for spacing of display of reels
	//this will loop through the array for value selection, display and win counting
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int rando{ randomNum(rng) % 2 }; //call the rng
			rando = abs(rando); //sometimes we got negative values
			if (rando == 0)
			{
				reels[i][j] = '-'; //lose value
			}
			else if (rando == 1)
			{
				reels[i][j] = 'S'; //win value
				winCounter++;
			} 
			cout << reels[i][j] << " ";
		} //end internal for loop
		cout << "\n";
	}
	cout << "\n";
	//evaulate wins
	std::vector<int> payTable{ 0,0,0,0,0,0,0,0,100,150,200,300, 500, 600, 1000 };
	return payTable[winCounter];	
} //end evaluateReels()
