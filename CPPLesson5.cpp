// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"

void array_subscripts()
{
    int array[5]; // declare an array of length 5

    // using a literal (constant) index:
    array[1] = 7; // ok

    // using an enum (constant) index
    enum Animals
    {
        ANIMAL_CAT = 2
    };
    array[ANIMAL_CAT] = 4; // ok

    // using a variable (non-constant) index:
    short index = 3;
    array[index] = 7; // ok

    // using an expression that evaluates to an integer index:
    array[1 + 2] = 7; // ok
}

void fixed_array_declarations()
{
    // using a literal constant
    int array[5]; // Ok

    // using a macro symbolic constant
#define ARRAY_LENGTH 5
    int array[ARRAY_LENGTH]; // Syntactically okay, but don't do this

    // using a symbolic constant
    const int arrayLength = 5;
    int array[arrayLength]; // Ok

    // using an enumerator
    enum ArrayElements
    {
        MAX_ARRAY_LENGTH = 5
    };
    int array[MAX_ARRAY_LENGTH]; // Ok

    /*
    // using a non-const variable
    int length;
    std::cin >> length;
    int array[length]; // Not ok -- length is not a compile-time constant!
    // using a runtime const variable
    int temp = 5;
    const int length = temp; // the value of length isn't known until runtime, so this is a runtime constant, not a compile-time constant!
    int array[length]; // Not ok        
    */
}

int main()
{
    array_subscripts();
	

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
