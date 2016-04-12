#pragma once
class constClass
{
private:
	int m_pr_value;

public:
	int m_value;

	void print() const; // const after method name, before definition
	// since this class is going to be instantiated as const, all method also have to be const

	
	constClass();
	~constClass();
};

