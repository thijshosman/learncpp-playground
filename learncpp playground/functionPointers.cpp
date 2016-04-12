#include "stdafx.h"
#include "functionPointers.h"
#include <utility>
#include <iostream>

int foo()
{
	return 1;
}

int goo(int i)
{
	printf("goo called with %d\n",i);
	return 2;
}

// Note our user-defined comparison is the third parameter
void selectionSort(int *array, int size, bool(*comparisonFcn)(int, int))
{
	// Step through each element of the array
	for (int startIndex = 0; startIndex < size; ++startIndex)
	{
		// smallestIndex is the index of the smallest element we've encountered so far.
		int smallestIndex = startIndex;

		// Look for smallest element remaining in the array (starting at startIndex+1)
		for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
		{
			// If the current element is smaller than our previously found smallest
			if (comparisonFcn(array[smallestIndex], array[currentIndex])) // COMPARISON DONE HERE
																		  // This is the new smallest number for this iteration
				smallestIndex = currentIndex;
		}

		// Swap our start element with our smallest element
		std::swap(array[startIndex], array[smallestIndex]);
	}
}

bool ascending(int x, int y)
{
	return x > y; // swap if the first element is greater than the second
}

// Here is a comparison function that sorts in descending order
bool descending(int x, int y)
{
	return x < y; // swap if the second element is greater than the first
}

void printArray(int *array, int size)
{
	for (int index = 0; index < size; ++index)
		std::cout << array[index] << " ";
	std::cout << '\n';
}

