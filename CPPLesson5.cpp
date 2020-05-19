// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size


void printSize(int array[])
{
    // prints the size of a pointer, not the size of the array! 4
    std::cout << sizeof(array) << '\n'; 
}

void sizeof_array() 
{
    int array_0[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << sizeof(array_0) << '\n'; // will print the size of the array 32
    printSize(array_0);

    /*
    Determining the length of a fixed array prior to C++17

    One neat trick: we can determine the length of a fixed array by 
    dividing the size of the entire array by the size of an array element

    Note that this will only work if the array is a fixed-length array, 
    and you’re doing this trick in the same function that array is declared in
    */
    int array_1[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << sizeof(array_1) / sizeof(array_1[0]) << " elements\n";

    // Determining the length of a fixed array in C++17/C++20 
    // #include <iterator> // for std::size
    int array[] = { 1, 1, 2, 3, 5, 8, 13, 21 };
    std::cout << "The array has: " << std::size(array) << " elements\n";
}




int main()
{
    
    sizeof_array();


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
