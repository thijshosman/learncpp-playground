// learncpp playground.cpp : Defines the entry point for the console application.
// CTRL F5 to build without debugging

#include "stdafx.h"
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include "pqueue.h"

int aSort()
{

		const int size = 5;
		int array[size] = { 30, 50, 20, 10, 40 };

		// Step through each element of the array
		for (int startIndex = 0; startIndex < size; ++startIndex)
		{
			// smallestIndex is the index of the smallest element we've encountered so far.
			int smallestIndex = startIndex;

			// Look for smallest element remaining in the array (starting at startIndex+1)
			for (int currentIndex = startIndex + 1; currentIndex < size; ++currentIndex)
			{
				// If the current element is smaller than our previously found smallest
				if (array[currentIndex] < array[smallestIndex])
					// This is the new smallest number for this iteration
					smallestIndex = currentIndex;
			}

			// Swap our start element with our smallest element
			std::swap(array[startIndex], array[smallestIndex]);
		}

		// Now print our sorted array as proof it works
		for (int index = 0; index < size; ++index)
			std::cout << array[index] << ' ';

		return 0;
}

void pointertest()
{
	// dynamically allocate an int
	int *pnValue = new int; // dynamically allocate an integer, always initialize to something
	*pnValue = 7; // assign 7 to this integer
	if (pnValue)
		*pnValue = 5;
	printf("pnvalue: %d \n", *pnValue);
	delete pnValue; // unallocate memory assigned to pnValue
	pnValue = 0; // explicitly set to 0

	// dynamically allocate an array of ints
	int nSize = 12;
	int *pnArray = new int[nSize]; // note: nSize does not need to be constant!
	pnArray[4] = 7;
	printf("pnarray: %d \n", pnArray[4]);
	delete[] pnArray;




}


int main()
{
	aSort();
	pointertest();

	//printf("hello world\n");
	//system("pause");
	return 0;
	
}

