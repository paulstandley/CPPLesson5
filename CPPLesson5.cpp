// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11

void two_dimensional_arrays()
{
    
    constexpr int num_row{ 3 };
    constexpr int num_col{ 5 };

    int dimensional_array[num_row][num_col]
    {
      { 1, 2 }, // row 0 = 1, 2, 0, 0, 0
      { 6, 7, 8 }, // row 1 = 6, 7, 8, 0, 0
      { 11, 12, 13, 14 } // row 2 = 11, 12, 13, 14, 0
    };

    // step through the rows in the array
    for (int row{ 0 }; row < num_row; ++row)
    {
        // step through each element in the row
        for (int col = 0; col < num_col; ++col)
        {
            std::cout << dimensional_array[row][col];
        }
        std::cout << '\n';
    }

}


int main()
{
    two_dimensional_arrays();

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
