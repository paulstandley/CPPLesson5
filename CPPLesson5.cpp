// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11

/*
Question #3
This one is going to be difficult, so put your game face on.
Another simple sort is called “bubble sort”. 
Bubble sort works by comparing adjacent pairs of elements, and swapping them if the criteria 
is met, so that elements “bubble” to the end of the array. 
Although there are quite a few ways to optimize bubble sort, 
in this quiz we’ll stick with the unoptimized version here because it’s simplest.

Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:

A) Compare array element 0 with array element 1. 
If element 0 is larger, swap it with element 1.

B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you 
hit the end of the array. At this point, the last element in the array will be sorted.

C) Repeat the first two steps again until the array is sorted.

Write code that bubble sorts the following array according to the rules above:

int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
Print the sorted array elements at the end of your program.

Hint: If we’re able to sort one element per iteration, that means we’ll need to iterate roughly 
as many times as there are numbers in our array to guarantee that the whole array is sorted.
Hint: When comparing pairs of elements, be careful of your array’s range.
*/

void bubble_sort()
{
	int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
	constexpr int length{ static_cast<int>(std::size(array)) };

    // Step through each element of the array (except the last, which will already be sorted by the time we get to it)
    for (int iteration{ 0 }; iteration < length - 1; ++iteration)
    {
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it, swap them
            if (array[currentIndex] > array[currentIndex + 1])
                std::swap(array[currentIndex], array[currentIndex + 1]);
        }
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

}

int main()
{
	bubble_sort();

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
