#include "stdafx.h"
#include "testClass.h"


void testClass::fun1(int i)
{
	printf("fun1 called\n");
}

void testClass::print()
{
	printf("i = %d, j = %d", i, j);
}

int testClass::ival()
{
	return i;
}

int testClass::jval()
{
	return j;
}



testClass::testClass(int i1, int i2) : k{ 6 }, m_array{}
{
	i = i1;
	j = i2;
}

testClass::testClass() : k{ 6 }, m_array{} // initializer list, c++11 style. needed for const member variables
{
	// no need to do anything to initialization in the body
	printf("constructor called\n");
}


testClass::~testClass()
{
	printf("destructor called\n");
}

