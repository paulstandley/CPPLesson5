// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size



void loop_array_function()
{
    // First, read in valid input from user
    int number{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        // if the user entered an invalid character
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags

        std::cin.ignore(32767, '\n'); // ignore any extra characters in the input buffer (regardless of whether we had an error or not)

    } while (number < 1 || number > 9);

    // Next, print the array
    int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int arrayLength{ static_cast<int>(std::size(array)) };

    for (int index{ 0 }; index < arrayLength; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    // Then, search the array to find the matching number and print the index
    for (int index{ 0 }; index < arrayLength; ++index)
    {
        if (array[index] == number)
        {
            std::cout << "The number " << number << " has index " << index << "\n";
            break; // since each # in the array is unique, no need to search rest of array
        }
    }
}



int main()
{
    loop_array_function();

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
