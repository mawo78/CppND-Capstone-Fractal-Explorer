#pragma once
#include "MandelbrotFracParallel.h"
#include "JuliaFrac.h"

class JuliaFracParallel :
    public JuliaFrac
{
public:
    JuliaFracParallel(unsigned int, unsigned int);
    virtual void calculate(cv::Mat&) override;
};

