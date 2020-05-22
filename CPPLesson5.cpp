// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11


void optimization_bubble_sort()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };
    int keep_count{ 0 };
    int highest_number{ 0 };
    int highest_index{ 0 };

    // Step through each element of the array (except the last, which will already be sorted by the time we get to it)
    for (int iteration{ 0 }; iteration < length; ++iteration)
    {
        keep_count++;
        bool count_swaps{ false };
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex)
        {
            keep_count++;

            // If the current element is larger than the element after it, swap them
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                count_swaps = true;
                highest_index = currentIndex;
                highest_number = array[currentIndex];
            }
            ++currentIndex;
        }
        if (!count_swaps)
        {
            std::cout << "Early termination on iteration " << keep_count << '\n';
            break;
        }
        ++iteration;
        std::cout << highest_number << '\t' << highest_index << '\n';
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n' << keep_count << '\n';

}

void learnCPP()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) }; // C++17
//  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable

    // Step through each element of the array except the last
    for (int iteration{ 0 }; iteration < length - 1; ++iteration)
    {
        // Account for the fact that the last element is already sorted with each subsequent iteration
        // so our array "ends" one element sooner
        int endOfArrayIndex{ length - iteration };

        bool swapped{ false }; // Keep track of whether any elements were swapped this iteration

        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it
            if (array[currentIndex] > array[currentIndex + 1])
            {
                // Swap them
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }

        // If we haven't swapped any elements this iteration, we're done early
        if (!swapped)
        {
            // iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
            std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
            break;
        }
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';
}


int main()
{
    optimization_bubble_sort();

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
