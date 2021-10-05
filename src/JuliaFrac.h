#pragma once
#include "MandelbrotFrac.h"
class JuliaFrac :
    public MandelbrotFrac
{
public:
    JuliaFrac(unsigned int, unsigned int);
protected:
    virtual void calcOneRow(cv::Mat&, unsigned int) override;
    int julia(const std::complex<double>&, const std::complex<double>&) const;
};

