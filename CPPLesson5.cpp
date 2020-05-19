// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"

void passValue(int value) // value is a copy of the argument
{
    value = 99; // so changing it here won't change the value of the argument
}

void passArray(int prime[5]) // prime is the actual array
{
    prime[0] = 11; // so changing it here will change the original argument!
    prime[1] = 7;
    prime[2] = 5;
    prime[3] = 3;
    prime[4] = 2;
}

void passing_arrays_to_functions()
{
    int value = 1;
    std::cout << "before passValue: " << value << "\n";
    passValue(value);
    std::cout << "after passValue: " << value << "\n";

    int prime[5] = { 2, 3, 5, 7, 11 };
    std::cout << "before passArray: " << prime[0] << " " << prime[1] << " " 
        << prime[2] << " " << prime[3] << " " << prime[4] << "\n";

    passArray(prime);
    std::cout << "after passArray: " << prime[0] << " " << prime[1] << " " 
        << prime[2] << " " << prime[3] << " " << prime[4] << "\n";
    /*
    In the example, value is not changed in main() because the parameter value in function
    passValue() was a copy of variable value in function main(), not the actual variable.
    However, because the parameter array in function passArray() is the actual array, 
    passArray() is able to directly change the value of the elements!

    To ensure a function does not modify the array elements passed into it,
    you can make the array const
    */
}


int main()
{
    
    passing_arrays_to_functions();


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
