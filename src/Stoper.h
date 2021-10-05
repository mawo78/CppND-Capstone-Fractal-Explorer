#pragma once
#include <chrono> 

class Stoper
{
public:
	Stoper();
	~Stoper();
private:
	std::chrono::high_resolution_clock::time_point m_start;
};

