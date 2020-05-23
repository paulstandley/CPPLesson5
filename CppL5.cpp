#include "pch.h"
#include <iostream>
#include "CppLesson5.h"
#include <iterator> // for std::size
#include <algorithm> // for std::swap, use <utility> instead if C++11


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

namespace Animals
{
    enum Animals
    {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        ARRAY_SIZE
    };
}

void animal_legs_array()
{
    int animal[Animals::ARRAY_SIZE] = { 2, 4, 4, 4, 2, 0 };
    for (int count = 0; count < Animals::ARRAY_SIZE; count++)
    {
        std::cout << "Index " << count << " value " << animal[count] << std::endl;
    }
}

void days_high_temperature()
{
    double temperature_array[365] = { };
    for (int count = 0; count < std::size(temperature_array); count++)
    {
        std::cout << "Count index: " << count << " array value: " << temperature_array[count] << std::endl;
    }
}

void loop_array_function()
{
    // First, read in valid input from user
    int number{};
    do
    {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        // if the user entered an invalid character
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags

        std::cin.ignore(32767, '\n'); // ignore any extra characters in the input buffer (regardless of whether we had an error or not)

    } while (number < 1 || number > 9);

    // Next, print the array
    int array[]{ 4, 6, 7, 3, 8, 2, 1, 9, 5 };
    int arrayLength{ static_cast<int>(std::size(array)) };

    for (int index{ 0 }; index < arrayLength; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

    // Then, search the array to find the matching number and print the index
    for (int index{ 0 }; index < arrayLength; ++index)
    {
        if (array[index] == number)
        {
            std::cout << "The number " << number << " has index " << index << "\n";
            break; // since each # in the array is unique, no need to search rest of array
        }
    }
}

void best_score_array()
{
    int scores[]{ 84, 92, 76, 81, 56 };
    int numStudents{ static_cast<int>(std::size(scores)) };

    int maxScore{ 0 }; // keep track of our largest score
    int maxIndex{ 0 };

    // now look for a larger score
    for (int student{ 0 }; student < numStudents; ++student)
    {
        if (scores[student] > maxScore)
        {
            maxScore = scores[student];
            maxIndex = student;
        }
    }

    std::cout << "The best score was " << maxScore << " at index " << maxIndex << '\n';
}

void array_swap()
{
    int x{ 2 };
    int y{ 4 };
    std::cout << "Before swap: x = " << x << ", y = " << y << '\n';
    std::swap(x, y); // swap the values of x and y
    std::cout << "After swap:  x = " << x << ", y = " << y << '\n';
}

void array_selection_swap()
{
    constexpr int length{ 5 };
    int array[length]{ 30, 50, 20, 10, 40 };

    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (int startIndex{ 0 }; startIndex < length - 1; ++startIndex)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        int smallestIndex{ startIndex };

        // Then look for a smaller element in the rest of the array
        for (int currentIndex{ startIndex + 1 }; currentIndex < length; ++currentIndex)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[currentIndex] < array[smallestIndex])
                // then keep track of it
                smallestIndex = currentIndex;
        }

        // smallestIndex is now the smallest element in the remaining array
                // swap our start element with our smallest element (this sorts it into the correct place)
        std::swap(array[startIndex], array[smallestIndex]);
    }

    // Now that the whole array is sorted, print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';
}

void array_selection_sort()
{
    int array[]{ 30, 50, 20, 10, 40 };

    std::sort(std::begin(array), std::end(array));

    for (int i{ 0 }; i < static_cast<int>(std::size(array)); ++i)
        std::cout << array[i] << ' ';

    std::cout << '\n';
}

/*
Manually show how selection sort works on the following array: { 30, 60, 20, 50, 40, 10 }.
Show the array after each swap that takes place.
*/

void array_quiz_1()
{
    constexpr int length{ 6 };
    int array[length]{ 30, 60, 20, 50, 40, 10 };
    // Step through each element of the array
    // (except the last one, which will already be sorted by the time we get there)
    for (int start_index = 0; start_index < length - 1; start_index++)
    {
        // smallestIndex is the index of the smallest element we’ve encountered this iteration
        // Start by assuming the smallest element is the first element of this iteration
        int smallest_index{ start_index };
        // Then look for a smaller element in the rest of the array
        for (int current_index = start_index + 1; current_index < length; current_index++)
        {
            // If we've found an element that is smaller than our previously found smallest
            if (array[current_index] < array[smallest_index])
            {					// > decending
                // then keep track of it
                smallest_index = current_index;
            }
            // smallestIndex is now the smallest element in the remaining array
            // swap our start element with our smallest element (this sorts it into the correct place)
            std::swap(array[start_index], array[smallest_index]);
        }
        // print on each interation
        for (int index = 0; index < length; index++)
        {
            std::cout << array[index] << ' ';
        }
        std::cout << '\n';
    }
}

/*
Question #3
This one is going to be difficult, so put your game face on.
Another simple sort is called “bubble sort”.
Bubble sort works by comparing adjacent pairs of elements, and swapping them if the criteria
is met, so that elements “bubble” to the end of the array.
Although there are quite a few ways to optimize bubble sort,
in this quiz we’ll stick with the unoptimized version here because it’s simplest.

Unoptimized bubble sort performs the following steps to sort an array from smallest to largest:

A) Compare array element 0 with array element 1.
If element 0 is larger, swap it with element 1.

B) Now do the same for elements 1 and 2, and every subsequent pair of elements until you
hit the end of the array. At this point, the last element in the array will be sorted.

C) Repeat the first two steps again until the array is sorted.

Write code that bubble sorts the following array according to the rules above:

int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
Print the sorted array elements at the end of your program.

Hint: If we’re able to sort one element per iteration, that means we’ll need to iterate roughly
as many times as there are numbers in our array to guarantee that the whole array is sorted.
Hint: When comparing pairs of elements, be careful of your array’s range.
*/


void bubble_sort()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };

    // Step through each element of the array (except the last, which will already be sorted by the time we get to it)
    for (int iteration{ 0 }; iteration < length - 1; ++iteration)
    {
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it, swap them
            if (array[currentIndex] > array[currentIndex + 1])
                std::swap(array[currentIndex], array[currentIndex + 1]);
        }
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';

}

void optimization_bubble_sort()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) };
    int keep_count{ 0 };
    int highest_number{ 0 };
    int highest_index{ 0 };

    // Step through each element of the array (except the last, which will already be sorted by the time we get to it)
    for (int iteration{ 0 }; iteration < length; ++iteration)
    {
        keep_count++;
        bool count_swaps{ false };
        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < length - 1; ++currentIndex)
        {
            keep_count++;

            // If the current element is larger than the element after it, swap them
            if (array[currentIndex] > array[currentIndex + 1])
            {
                std::swap(array[currentIndex], array[currentIndex + 1]);
                count_swaps = true;
                highest_index = currentIndex;
                highest_number = array[currentIndex];
            }
            ++currentIndex;
        }
        if (!count_swaps)
        {
            std::cout << "Early termination on iteration " << keep_count << '\n';
            break;
        }
        ++iteration;
        std::cout << highest_number << '\t' << highest_index << '\n';
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n' << keep_count << '\n';

}

void learnCPP()
{
    int array[]{ 6, 3, 2, 9, 7, 1, 5, 4, 8 };
    constexpr int length{ static_cast<int>(std::size(array)) }; // C++17
//  constexpr int length{ sizeof(array) / sizeof(array[0]) }; // use instead if not C++17 capable

    // Step through each element of the array except the last
    for (int iteration{ 0 }; iteration < length - 1; ++iteration)
    {
        // Account for the fact that the last element is already sorted with each subsequent iteration
        // so our array "ends" one element sooner
        int endOfArrayIndex{ length - iteration };

        bool swapped{ false }; // Keep track of whether any elements were swapped this iteration

        // Search through all elements up to the end of the array - 1
        // The last element has no pair to compare against
        for (int currentIndex{ 0 }; currentIndex < endOfArrayIndex - 1; ++currentIndex)
        {
            // If the current element is larger than the element after it
            if (array[currentIndex] > array[currentIndex + 1])
            {
                // Swap them
                std::swap(array[currentIndex], array[currentIndex + 1]);
                swapped = true;
            }
        }

        // If we haven't swapped any elements this iteration, we're done early
        if (!swapped)
        {
            // iteration is 0 based, but counting iterations is 1-based.  So add 1 here to adjust.
            std::cout << "Early termination on iteration: " << iteration + 1 << '\n';
            break;
        }
    }

    // Now print our sorted array as proof it works
    for (int index{ 0 }; index < length; ++index)
        std::cout << array[index] << ' ';

    std::cout << '\n';
}

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
            std::cout << dimensional_array[row][col] << '\t';
        }
        std::cout << '\n';
    }
}

void times_tables()
{
    std::cout << "The 1 to 12 time table" << '\n' << '\n';
    // compile time variable constant :-)
    constexpr int num_rows{ 13 };
    constexpr int num_cols{ 13 };
    // declare an 13X13 array with 0 as all values
    int product[num_rows][num_cols]{};

    // calculate the 12 times table first array elements are 0
    for (int row{ 1 }; row < num_rows; ++row)
        for (int col{ 1 }; col < num_cols; ++col)
            product[row][col] = row * col;

    // print value
    for (int row{ 1 }; row < num_rows; ++row)
    {
        for (int col{ 1 }; col < num_cols; ++col)
        {
            std::cout << row << "*" << col <<  "=" << product[row][col] << "|";
        }
        std::cout << '\n';
    }
}




