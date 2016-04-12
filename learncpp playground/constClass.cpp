#include "stdafx.h"
#include "constClass.h"


void constClass::print() const // const after method name, before body
{
	printf("m_value: %d, m_pr_value %d\n", m_value, m_pr_value);
}

constClass::constClass(): m_value{0}, m_pr_value{0} // c++11 initialization list, NB: only allowed in constructor

{
	printf("constclass constructor called");
}


constClass::~constClass()
{
}
