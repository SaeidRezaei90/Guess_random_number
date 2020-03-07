// Guess_random_number.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <vector>
#include <array>

using std::cout;
using std::cin;
using std::endl;
void Play_Game(); //declare

void Print_array(int guess_array[], int array_size)
{
	std::cout << "You entered the following numbers:\n";
	for (int i = 0; i < array_size; i++)
	{
		std::cout << guess_array[i] << "\t";
	}
	std::cout <<std::endl << "You guessed " << array_size << " numbers and " << guess_array[array_size - 1] << " is the right choice\n \n";
}



bool Play_or_Not()
{
	int choice;
	std::cout << "Please enter 0 to exit or 1 to play the game:\n";
	do
	{
		if (std::cin >> choice)
		{
			switch (choice)
			{
			case 0:
				std::cout << "See you later\n.";
				return false;

			case 1:
				Play_Game();
				break;

			default:
				std::cout << "Please enter 0 or 1:\n";
				break;
			}
		}
		else
		{
			std::cout << "Please enter 0 or 1:\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	} while (choice != 0);

	return true;
}

void Play_Game()
{
	std::cout << "\n \n \nYou are playing the game... \n";
	int random = rand() % 21; //generate a random number between 0 to 20
	std::cout << "random number generated is: " << random << std::endl;
	std::cout << "Please guess the random number between 0 to 20:\n";
	int random_guess_array[10];
	int array_size = 0;
	do
	{
		if (std::cin >> random_guess_array[array_size])
		{
			if (random_guess_array[array_size] == random)
				std::cout << "\n \n Congratulation, You win\n";
			else if (random_guess_array[array_size] < random)
				std::cout << "You enter a low number\n";
			else
				std::cout << "You enter a high number\n";
			
			array_size++;
		}
		else
		{
			std::cout << "Please enter a valid number:\n";
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

	} while (random_guess_array[array_size - 1] != random && array_size < 10);

	if (random_guess_array[array_size - 1] == random)
		Print_array(random_guess_array, array_size);
	else
		std::cout << "I'm sorry, you had 10 guesses but you didn't guess correctly" << std::endl;

	if (Play_or_Not() == false)
		exit(0);

}

int main()
{
	srand(time(NULL));

	if (Play_or_Not() == false)
		return 0;

	
	_getch();
	return 0;
}



