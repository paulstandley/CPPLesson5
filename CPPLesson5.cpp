// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"

void fixed_array()
{
	// use initializer list to initialize the fixed array
	int prime_0[5] = { 2, 3, 5, 7, 11 }; 

	// Initialize all elements to 0
	int array_0[5] = { };

	// Initialize all elements to 0.0
	double array_1[5] = { };

	int prime_1[5]{ 2, 3, 5, 7, 11 }; 
	// use uniform initialization to initialize the fixed array
	// note the lack of the equals sign in this syntax

	// explicitly define length of the array
	int array_2[5] = { 0, 1, 2, 3, 4 }; 

	// let initializer list set length of the array
	int array_3[] = { 0, 1, 2, 3, 4 }; 
}

int main()
{
    
	

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
