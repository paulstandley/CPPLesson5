// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11

/*
Manually show how selection sort works on the following array: { 30, 60, 20, 50, 40, 10 }. 
Show the array after each swap that takes place.
*/

void array_quiz_1()
{
	constexpr int length{ 6 };
	int array[length]{ 30, 60, 20, 50, 40, 10 };
	// Step through each element of the array
	// (except the last one, which will already be sorted by the time we get there)
	for (int start_index = 0; start_index < length - 1; start_index++)
	{
		// smallestIndex is the index of the smallest element we’ve encountered this iteration
		// Start by assuming the smallest element is the first element of this iteration
		int smallest_index{ start_index };
		// Then look for a smaller element in the rest of the array
		for (int current_index = start_index + 1; current_index < length; current_index++)
		{
			// If we've found an element that is smaller than our previously found smallest
			if (array[current_index] < array[smallest_index])
			{					// > decending
				// then keep track of it
				smallest_index = current_index;
			}
			// smallestIndex is now the smallest element in the remaining array
			// swap our start element with our smallest element (this sorts it into the correct place)
			std::swap(array[start_index], array[smallest_index]);
		}
		// print on each interation
		for (int index = 0; index < length; index++)
		{
			std::cout << array[index] << ' ';
		}
		std::cout << '\n';
	}
}

int main()
{
	array_quiz_1();

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
