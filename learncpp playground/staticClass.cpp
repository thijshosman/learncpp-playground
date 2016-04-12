#include "stdafx.h"
#include "staticClass.h"

static const int s_c_value = 4; // a static const int can be declared and initialized directly in the body of the class
// NB: this is a member of the class, same for all objects
// NB2: needs to be declared outside of class definition

staticClass::staticClass()
{
	m_id = s_idGenerator++;
	s_value++;
}

const int staticClass::getID()
{
	return m_id;
}

staticClass::~staticClass()
{
}

