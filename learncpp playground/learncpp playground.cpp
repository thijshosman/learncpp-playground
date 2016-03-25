// learncpp playground.cpp : Defines the entry point for the console application.
// CTRL F5 to build without debugging

#include "stdafx.h"
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include "pqueue.h"
#include "array_sum.h"

void memberSelection()
{

	struct Something
	{
		int nValue;
		float fValue;
	};
	
	Something sSomething;
	
	// Member selection using actual struct variable
	sSomething.nValue = 5;

	// Member selection using reference to struct
	Something &rsSomething = sSomething;
	rsSomething.nValue = 5;

	// Member selection using pointer to struct
	Something *psSomething = &sSomething;
	(*psSomething).nValue = 5;
	// or
	psSomething->nValue = 5;

}

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

	// const pointers and pointers to const values
	// const pointer; pointer cannot change to different value, but the value itself can change
	int nValue = 5;
	int nValue2 = 2;
	int *const pnPtr = &nValue;
	*pnPtr = 6; // allowed
	// pnPtr = &nValue2; // not allowed

	// pointer to const value; pointer can change but value it points to cannot
	// ie: does not actually have to point to constant value, just treats it as such
	int nValue1 = 5;
	const int *pnPtr1 = &nValue1;
	pnPtr1 = &nValue2;
	// *pnPtr1 = 3; // not allowed

	// can have const pointer to const value
	const int *const pnPtr2 = &nValue;

}

void referencetest()
{
	// references give us a handle to change a variable
	int nValue = 3;
	int &rnRef = nValue; // reference to nValue
	nValue = 6; // nValue is now 6
	rnRef = 7; // nValue is now 7
	
	std::cout << "nvalue: " << nValue << "\n";

	// const ref possible as well; now we cannot change the reference
	const int &rnRef1 = nValue;
	// rnRef1 = 3; // illegal since this ref is const

}

void statictest()
{
	// static variables 
	using namespace std;
	static int s_val = 0; // needs to be called in order for this function to address s_val
	s_val++; // increments s_val, despite going out of scope
	cout << "s_val: " << s_val << "\n";
}

void staticloop()
{
	for (int i = 0; i < 10; i++)
	{
		statictest();
	}
	static int s_val;
	statictest();
}




int main()
{
	aSort();
	pointertest();
	referencetest();
	staticloop();

	int foo[] = { 4, 6, -7, 30 };

	int a;
	a = foo[0];

	// since foo is an array, we need to use this
	int *pa = foo;
	// pointers are referenced the same ways as arrays, so a[4] is the same is *a(4)

	printf("%d\n",*(pa+1));

	// find max sum
	a = max_sum(foo, 3);
	printf("%d\n", a);




	printf("hello world\n");
	//system("pause");
	// press ctrl + F5 to run without closing console
	return 0;
	
}

