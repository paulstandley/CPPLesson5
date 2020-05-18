// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"

void double_array()
{
    double array[3]; // allocate 3 doubles
    array[0] = 2.0;
    array[1] = 3.0;
    array[2] = 4.3;

    std::cout << "The average is " << (array[0] + array[1] + array[2]) / 3 << "\n";

	for (int count = 0; count < 3; count++)
	{
		std::cout << "The double array index is "
			<< count << " and the value is " << array[count] << std::endl;
	}
}


int main()
{
	
	double_array();

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
