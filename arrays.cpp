// arrays.cpp : Defines the entry point for the console application.
//
// Justin Balogh
// 3/26/18
#include "stdafx.h"
#include <iostream>
using namespace std;

void storeMonkey(int monkeySet[][5]);
int calcMax(int monkeySet[][5]);
int calcMin(int monkeySet[][5]);
int calcAvg(int monkeySet[][5]);
void reportMonkeys(int monkeySet[][5]);

int main()
{
	const int weekLength = 5; // columns
	const int monkeyCount = 3; // rows

	int zooMonkeys[monkeyCount][weekLength] = 
	{
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	}; // sets values to zero.
	
	storeMonkey(zooMonkeys); // runs store monkey func, which takes input and store the values to the 2d array
	reportMonkeys(zooMonkeys); // runs a report using avg, min, and max functions to create a report that displays the calculated information.

	system("pause"); // pauses so the window doesnt close out
}

void storeMonkey(int monkeySet[][5])
{
	int input = 0; // input holder
	int monkeyNumber = 0; // row in 3x5 array
	while (monkeyNumber < 3) // limits to 3 rows so no going outside array
	{
		for (int day = 0; day < 5; day++) // limits loop to 5 columns
		{
			cout << "Pounds of food eaten for monkey number " << monkeyNumber + 1 << " on day: " << day << endl; // output what the program wants input for
			cin >> input;

			if (input < 1) // error validation
				cout << "Not a valid number." << endl;

			while (input < 1) // trigger to reinput for error
			{
				cout << "Pounds of food eaten for monkey number " << monkeyNumber + 1 << " on day: " << day + 1 << endl;
				cin >> input;
			}
			monkeySet[monkeyNumber][day] = input;

		}
		monkeyNumber++; // increase to next row!
	}
		
	
}

int calcAvg(int monkeySet[][5]) // calculates average by reading each array value
{
	int accumulator = 0; // accum to add up for avg
	int avg = 0; // holds avg at the end of calc for return
	int rows; // row or monkey
	int cols; // column or day

	for (rows = 0; rows < 3; rows++) // loops and counts up after 3 monkeys or rows
	{
		for (cols = 0; cols < 5; cols++) // loops from 0-4, days 1-5, cols 
		{
			accumulator += monkeySet[rows][cols]; // reads each array value at each row, col
		}
	}

	avg = accumulator / 15; // simple math for average all 15 days
	return avg; // returns avg
}

int calcMax(int monkeySet[][5]) // very similar to calcAvg, but finds Max number
{
	int max = monkeySet[0][0]; // defaults max value at the first value in array, gets changed in loop
	int rows;
	int cols;

	for (rows = 0; rows < 3; rows++) 
	{
		for (cols = 0; cols < 5; cols++) // scrolls through all 15 values
		{
			if (monkeySet[rows][cols] > max) // checks for if the read data in array is more than the current max
			{
				max = monkeySet[rows][cols]; // sets current max to the read data in the if logic
			}
		}
	}

	return max; // returns the max value in array!
}

int calcMin(int monkeySet[][5]) // same as Max except finds min
{
	int min = monkeySet[0][0];
	int rows;
	int cols;

	for (rows = 0; rows < 3; rows++)
	{
		for (cols = 0; cols < 5; cols++)
		{
			if (monkeySet[rows][cols] < min) // does the same, except finds values smaller than min
			{
				min = monkeySet[rows][cols]; // sets a new min
			}
		}
	}

	return min; // returns min
}


void reportMonkeys(int monkeySet[][5]) 
{
	cout << "The average amount of food consumed by the monkeys is: " << calcAvg(monkeySet) << endl; // reports avg
	cout << "The minimum amount of food consumed by the monkeys is: " << calcMin(monkeySet) << endl; // reports min
	cout << "The maximum amout of food consumed by the monkeys is: " << calcMax(monkeySet) << endl; // reports min
}