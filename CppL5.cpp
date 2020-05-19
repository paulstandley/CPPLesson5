#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size


void prime_array_int()
{
	int prime[5];

	prime[0] = 2;
	prime[1] = 3;
	prime[2] = 5;
	prime[3] = 7;
	prime[4] = 11;

	std::cout << "The lowest prime number is: "
		<< prime[0] << "\n";
	std::cout << "The sum of the first 5 primes is: "
		<< prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << "\n";

	for (int count = 0; count < 4; count++)
	{
		std::cout << "Prime array index " << count << " is " << prime[count] << std::endl;
	}
}

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

struct Rectangle
{
	int length;
	int width;
};

void select_struct_array()
{
	Rectangle rects[5]; // declare an array of 5 Rectangle
	rects[0].length = 24;
	rects[0].width = 18;
	std::cout << rects[0].length << '\t' << rects[0].width << std::endl;
}

void array_subscripts()
{
    int array_0[5]; // declare an array of length 5

    // using a literal (constant) index:
    array_0[1] = 7; // ok

    // using an enum (constant) index
    enum Animals
    {
        ANIMAL_CAT = 2
    };
    array_0[ANIMAL_CAT] = 4; // ok

    // using a variable (non-constant) index:
    short index = 3;
    array_0[index] = 7; // ok

    // using an expression that evaluates to an integer index:
    array_0[1 + 2] = 7; // ok
}

void fixed_array_declarations()
{
    // using a literal constant
    int array_0[5]; // Ok

    // using a macro symbolic constant
#define ARRAY_LENGTH 5
    int array_1[ARRAY_LENGTH]; // Syntactically okay, but don't do this

    // using a symbolic constant
    const int arrayLength = 5;
    int array_2[arrayLength]; // Ok

    // using an enumerator
    enum ArrayElements
    {
        MAX_ARRAY_LENGTH = 5
    };
    int array_3[MAX_ARRAY_LENGTH]; // Ok

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

void fixed_array_initialization()
{
	// use initializer list to initialize the fixed array
	int prime_0[5] = { 2, 3, 5, 7, 11 };

	// Initialize all elements to 0
	int array_0[5] = { };

	// Initialize all elements to 0.0
	double array_1[5] = { };

	int prime_1[5]{ 2, 3, 5, 7, 11 };
	// use uniform initialization to initialize the fixed array
	// note the lack of the equals sign in this syntax

	// explicitly define length of the array
	int array_2[5] = { 0, 1, 2, 3, 4 };

	// let initializer list set length of the array
	int array_3[] = { 0, 1, 2, 3, 4 };
}

namespace StudentNames
{
    enum StudentNames
    {
        KENNY, // 0
        KYLE, // 1
        STAN, // 2
        BUTTERS, // 3
        CARTMAN, // 4
        WENDY, // 5
        MAX_STUDENTS // 6
    };
}

void arrays_and_enums()
{
    int testScores[StudentNames::MAX_STUDENTS]; // allocate 6 integers
    testScores[StudentNames::STAN] = 76;

    //use a static_cast to convert the enumerator to an integer
    int testScores_0[static_cast<int>(StudentNames::MAX_STUDENTS)]; // allocate 6 integers
    testScores_0[static_cast<int>(StudentNames::STAN)] = 76;
}

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




