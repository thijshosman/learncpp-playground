#pragma once
class staticClass
{
private: 
	static int s_idGenerator;
	int m_id;
public:
	static int s_value; // static, so the same for each instance
	static const int s_c_value; // const static
	staticClass();
	~staticClass();

	const int getID();

};

