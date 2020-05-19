#include "pch.h"
#include <iostream>
#include "CppLesson5.h"

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

