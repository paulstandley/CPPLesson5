// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11


void c_style_strings()
{
	char my_string[]{ "string" };
	const int length{ static_cast<int>(std::size(my_string)) };

	std::cout << "My string has a length of " << length << " characters.\n";

	for (int index = 0; index < length; index++)
	{
		std::cout << static_cast<int>(my_string[index]) << " ";
	}
	std::cout << '\n';

	my_string[1] = 'p';// change t for p
	std::cout << my_string << '\n';

	char name[20]{ "Paul" }; // only use 5 characters (4 letters + null terminator)
	std::cout << "My name is: " << name << '\n';
}


int main()
{
	c_style_strings();

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
