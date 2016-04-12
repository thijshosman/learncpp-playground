#pragma once
class staticMemberClass
{
private: 
	static int s_nextID;
public:
	static int getNextID();
	staticMemberClass();
	~staticMemberClass();
};

