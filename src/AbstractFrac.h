#pragma once
#include "opencv2/core/core.hpp"

class AbstractFrac
{
public:
	virtual void calculate(cv::Mat&) = 0;
	virtual void zoomIn(int, int) = 0;
	virtual void zoomOut(int, int) = 0;
};

