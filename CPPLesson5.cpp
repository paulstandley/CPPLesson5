// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <cstring> // for std::strcpy strcpy_s

#define __STDC_WANT_LIB_EXT1__ 1


void c_style_strings_cin()
{
	char name[255]; // declare array large enough to hold 255 characters
	std::cout << "Enter your name: ";
	std::cin.getline(name, std::size(name));
	std::cout << "You entered: " << name << '\n';
}

void c_style_strings_manipulation()
{
	char source_1[]{ "Copy this!" };
	char dest_1[5]; // note that the length of dest_1 is only 5 chars!
	std::strcpy(dest_1, source_1); // overflow!
	std::cout << dest_1 << '\n';
}

void c_style_strings_manipulation_strcpy_s()
{
	// #define __STDC_WANT_LIB_EXT1__ 1
	char source[]{ "Copy this!" };
	char dest[5]; // note that the length of dest is only 5 chars!
	strcpy_s(dest, 5, source); // A runtime error will occur in debug mode
	std::cout << dest << '\n';
}




int main()
{
	c_style_strings_manipulation();

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
