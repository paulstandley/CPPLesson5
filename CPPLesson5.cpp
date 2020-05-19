// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size

/*
1) Declare an array to hold the high temperature (to the nearest tenth of a degree) for 
each day of a year (assume 365 days in a year). 
Initialize the array with a value of 0.0 for each day.

2) Set up an enum with the names of the following animals: chicken, dog, cat, elephant, 
duck, and snake.
Put the enum in a namespace. 
Define an array with an element for each of these animals, 
and use an initializer list to initialize each element to hold the number of legs that 
animal has.
*/

namespace Animals
{
	enum Animals
	{
		chicken,
		dog,
		cat,
		elephant,
		duck,
		snake,
		ARRAY_SIZE
	};
}

void animal_legs_array()
{
	int animal[Animals::ARRAY_SIZE] = { 2, 4, 4, 4, 2, 0 };
	for (int count = 0; count < Animals::ARRAY_SIZE; count++)
	{
		std::cout << "Index " << count << " value " << animal[count] << std::endl;
	}
}

void days_high_temperature()
{
	double temperature_array[365] = { };
	for (int count = 0; count < std::size(temperature_array); count++)
	{
		std::cout << "Count index: " << count << " array value: " << temperature_array[count] << std::endl;
	}
}


int main()
{
    
	days_high_temperature();
	animal_legs_array();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
