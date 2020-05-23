// CPPLesson5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <cstring> // for std::strcpy strcpy_s

void c_style_name()
{
	char name[20]{ "Paul" }; // only use 5 characters (4 letters + null terminator)
	std::cout << "My name is: " << name << '\n';
	std::cout << name << " has " << std::strlen(name) << " letters.\n";
	std::cout << name << " has " << std::size(name) << " characters in the array.\n";
	// use sizeof(name) / sizeof(name[0]) if not C++17 capable
	/*
	Other useful functions:
	strcat() -- Appends one string to another (dangerous)
	strncat() -- Appends one string to another (with buffer length check)
	strcmp() -- Compare two strings (returns 0 if equal)
	strncmp() -- Compare two strings up to a specific number of characters (returns 0 if equal)
	*/
}




int main()
{
	

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
