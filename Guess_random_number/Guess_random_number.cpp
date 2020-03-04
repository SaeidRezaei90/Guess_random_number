// Guess_random_number.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>


using std::cout;
using std::cin;
using std::endl;
void Play_Game();


bool Play_or_Not()
{
	int choice;
	std::cout << "Please enter 0 to exit or 1 to play the game:\n";
	do
	{
		std::cin >> choice;
		switch (choice)
		{
		case 0:
			std::cout << "See you later.";
			return false;
			

		case 1:
			Play_Game();
			break;

		default:
			std::cout << "You enterd a wrong number, Please enter 0 or 1:\n";
			break;
		}
	} while (choice != 0);
	return true;
}

void Play_Game()
{
	std::cout << "\n \n \nYou are playing the game... \n";
	int random = rand() % 100; //generate a random number between 0 to 99
	std::cout <<"random number generated is: " << random << std::endl;
	std::cout << "Please guess the random number between 0 to 99:\n";
	int random_guess;
	int times_of_played = 0;
	do
	{
		std::cin >> random_guess;

		times_of_played++;

	} while (random_guess != random && times_of_played < 10);

	if (random_guess == random)
		std::cout << "you entered " << times_of_played << " numbers to guess the random numeber correctly." << std::endl;
	else
		std::cout << "Sorry, you are not allowed to guess more than 10 times." << std::endl;
	
	Play_or_Not();
	
}

int main()
{
	srand(time(NULL));
	if(Play_or_Not() == false)
		return 0;


	_getch();
	return 0;
}



