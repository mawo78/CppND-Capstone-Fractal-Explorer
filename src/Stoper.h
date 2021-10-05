#pragma once
#include <chrono> 

class Stoper
{
public:
	Stoper();
	~Stoper();
private:
	std::chrono::steady_clock::time_point m_start;
};

