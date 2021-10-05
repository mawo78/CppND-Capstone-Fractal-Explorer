#pragma once
#include "MandelbrotFrac.h"

class MandelbrotFracParallel : public MandelbrotFrac
{
public:
	MandelbrotFracParallel(unsigned int, unsigned int);
	virtual void calculate(cv::Mat&) override;
};

