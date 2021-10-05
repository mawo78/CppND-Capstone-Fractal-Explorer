#include "MandelbrotFrac.h"
#include "Stoper.h"

using cv::Scalar;
using cv::Rect;

MandelbrotFrac::MandelbrotFrac(unsigned int uiResX, unsigned int uiResY) : 
    m_uiResolutionX(uiResX),  m_uiResolutionY(uiResY), m_dZoomLvl(1), m_uiZoomLogLevel(0) {
    calcBounds(0, 0, m_dZoomLvl);
}

void MandelbrotFrac::calcBounds(double dCenterReal, double dCenterImg, double dZoomLvl) {
    m_dImgPlaneX[0] = dCenterReal - (DELTA_X / dZoomLvl);
    m_dImgPlaneX[1] = dCenterReal + (DELTA_X / dZoomLvl);

    double xscale = abs(m_dImgPlaneX[1] - m_dImgPlaneX[0]);
    double yscale = 0.5 * xscale * Y_RESIZE;
    m_dImgPlaneY[0] = dCenterImg + yscale;
    m_dImgPlaneY[1] = dCenterImg - yscale;
}

// uniform transformation from screen coordinate to imaginary plane coordinate
double MandelbrotFrac::transform(double x, double dScreenMin, double dScreenMax, double dImgMin, double dImgMax) const {
    double deltaA = dImgMax - dImgMin;
    double deltaB = dScreenMax - dScreenMin;
    return dImgMin + (x - dScreenMin) * deltaA / deltaB;
}

// Calculate pixel color based on number of iteration
cv::Scalar MandelbrotFrac::findColor(unsigned int it) const {
    double p = double(it % COLOR_STEPS) / COLOR_STEPS;
    cv::Scalar color(0);
    if (it < MAX_ITER) {
        color = Scalar(int(255 * (1 - p * p)), 0, int(255 * p));
    }
    return color;
}

// Calculate and paint one row of pixels
void MandelbrotFrac::calcOneRow(cv::Mat& img, unsigned int i) {
    double x, y, x0, y0, pom;
    for (unsigned int j = 0; j < m_uiResolutionX; j++) {
        x = 0.0, y = 0.0;
        unsigned int it = 0;
        x0 = transform(j, 0, m_uiResolutionX, m_dImgPlaneX[0], m_dImgPlaneX[1]);
        y0 = transform(i, 0, m_uiResolutionY, m_dImgPlaneY[0], m_dImgPlaneY[1]);

        while (x * x + y * y <= 4 && it++ < MAX_ITER) {
            pom = x * x - y * y + x0;
            y = 2 * x * y + y0;
            x = pom;
        }

        img(Rect(j, i, 1, 1)) = findColor(it);
    }
}

// main drawing function
void MandelbrotFrac::calculate(cv::Mat& img) {
    Stoper stoper;

    for (unsigned int i = 0; i < m_uiResolutionY; i++) {
        calcOneRow(img, i);
    }
}

// Zoom in to selected point of interest
void MandelbrotFrac::zoomIn(int x, int y)
{
    m_uiZoomLogLevel++;
    m_dZoomLvl = pow(10, m_uiZoomLogLevel);
    calcBounds(transform(x, 0, m_uiResolutionX, m_dImgPlaneX[0], m_dImgPlaneX[1]), 
        transform(y, 0, m_uiResolutionY, m_dImgPlaneY[0], m_dImgPlaneY[1]), m_dZoomLvl);
}

// Zoom out 
void MandelbrotFrac::zoomOut(int x, int y)
{
    if (m_uiZoomLogLevel > 1) {
        m_dZoomLvl = pow(10, m_uiZoomLogLevel);
        m_uiZoomLogLevel--;
        calcBounds(transform(m_uiResolutionX / 2, 0, m_uiResolutionX, m_dImgPlaneX[0], m_dImgPlaneX[1]), 
            transform(m_uiResolutionY / 2, 0, m_uiResolutionY, m_dImgPlaneY[0], m_dImgPlaneY[1]), m_dZoomLvl);
    }
    else {
        m_dZoomLvl = 1;
        calcBounds(0, 0, m_dZoomLvl);
    }
}
