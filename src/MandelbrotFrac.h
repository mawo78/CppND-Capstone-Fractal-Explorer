#pragma once
#include "AbstractFrac.h"

class MandelbrotFrac : public AbstractFrac
{
public:
	MandelbrotFrac(unsigned int, unsigned int);
	// Derived from AbstractFrac
	virtual void calculate(cv::Mat&) override;
	virtual void zoomIn(int, int) override;
	virtual void zoomOut(int, int) override;
protected:
	const unsigned int MAX_ITER = 1024;
	const unsigned int COLOR_STEPS = 16;
	const unsigned int DELTA_X = 2;
	const double Y_RESIZE = 0.7; //arbitrary constant for resizing in Y axis

	double m_dImgPlaneX[2];
	double m_dImgPlaneY[2];
	unsigned int m_uiResolutionX;
	unsigned int m_uiResolutionY;

	void calcBounds(double, double, double);
	double transform(double, double, double, double, double) const;
	cv::Scalar findColor(unsigned int) const;
	virtual void calcOneRow(cv::Mat&, int);

private:
	double m_dZoomLvl;
	int m_uiZoomLogLevel;
};
