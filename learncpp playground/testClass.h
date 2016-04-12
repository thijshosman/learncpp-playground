#pragma once
class testClass
{
private:
	int i;
	int j;
	const int k;
	const int m_array[5];

public:
	void fun1(int i);
	void print();
	int ival();
	int jval();
	testClass(int i1=3, int i2=4); // special constructor
	testClass(); // default constructor
	~testClass();
};

