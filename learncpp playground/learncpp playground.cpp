// learncpp playground.cpp : Defines the entry point for the console application.
// CTRL F5 to build without debugging

#include "stdafx.h"
#include <algorithm> // for std::swap, use <utility> instead if C++11
#include <iostream>
#include "pqueue.h"
#include "array_sum.h"
#include "testClass.h"
#include "constClass.h"
#include "staticClass.h"
#include "staticMemberClass.h"
#include "functionPointers.h"

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


void lesson810() // const classes
{
	// 3 ways to initialize const classes
	const int value1 = 5; // explicit initialization
	const int value2(7); // implicit initialization
	const int value3{ 9 }; // uniform initialization (C++11)

	const constClass something; // calls default constructor
	something.print();
}

int staticClass::s_value = 1; // have to define static members once, outside of class definition or functions
//const int staticClass::s_c_value; // not needed, since const static ints/enums can be declared inside definition
int staticClass::s_idGenerator = 0; // initialize idGenerator with id 0

void lesson811() // static values 
{
	
	staticClass astaticClass1; // constructor adds 1 to s_value
	printf("s_value class 1: %d\n", astaticClass1.s_value);

	printf("s_value class: %d\n", staticClass::s_value);

	staticClass astaticClass2; // idem
	printf("s_value class 2: %d\n", astaticClass2.s_value);

	staticClass first;
	staticClass second;
	
	//std::cout << first.getID() << '\n';
	//std::cout << second.getID() << '\n';

}

int staticMemberClass::s_nextID = 1;
int staticMemberClass::getNextID() { return s_nextID++; }


void lesson812() // static member functions
{
	for (int count = 0; count< 5; ++count)
	{
		std::cout << "the next ID is: " << staticMemberClass::getNextID() << "\n";
	}
}

void lesson78() // function pointers
{
	// fcnPtr is a pointer to a function that takes no arguments and returns an integer
	int(*fcnPtr)(); //function pointer with no arguments that returns int
	int(*fcnPtr1)(int); //function pointer with int argument that returns int

	// assign function to pointer
	//NB1: don't use foo(), but foo
	//NB2: function signnature (arguments and return type) have to match
	fcnPtr = foo;
	fcnPtr1 = goo;
	
	// call function
	(*fcnPtr1)(5); // call function foo(5) through fcnPtr explicitly
	fcnPtr1(5); // or implicitly

	printf("functionpointer: %d\n",fcnPtr());

	// function pointers an be used for callback

	int array[9] = { 3, 7, 9, 5, 6, 1, 8, 2, 4 };

	// Sort the array in descending order using the descending() function
	selectionSort(array, 9, descending);
	printArray(array, 9);

	// Sort the array in ascending order using the ascending() function
	selectionSort(array, 9, ascending);
	printArray(array, 9);


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

	// ## classes and objects ##

	// create object on the stack
	testClass myClass1(1,1);
	myClass1.fun1(1); // fun1 is member of myClass1
	
	// create pointer
	testClass *myClass2= new testClass(2,1); // on the heap
	myClass2->fun1(1); // fun1 is member of class pointed t oby myClass2
	(*myClass2).fun1(1); // same, but ugly

	// or create array of objects, since an array is just a pointer
	testClass *objArr = new testClass[2]{ { 2,5 },{ 3,6 } };
	
	// const testClass 
	//lesson810();

	// static member variables
	//lesson811(); 

	// static methods
	//lesson812();

	// function pointers
	lesson78();


	printf("hello world\n");
	//system("pause");
	// press ctrl + F5 to run without closing console
	return 0;
	
}

