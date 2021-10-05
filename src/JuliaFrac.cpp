#include "JuliaFrac.h"
using cv::Scalar;
using cv::Rect;

JuliaFrac::JuliaFrac(unsigned int uiResX, unsigned int uiResY) : MandelbrotFrac(uiResX, uiResY) {
}

int JuliaFrac::julia(const std::complex<double>& c, const std::complex<double>& z0) const {
    std::complex<double> z = z0;
    unsigned int n = 0;
    while (std::abs(z) <= 2 && n++ < MAX_ITER) {
        z = z * z + c;
    }

    if (n == MAX_ITER)
        return MAX_ITER;
    else
        return static_cast<unsigned int>(n + 1.0 - log(log2(abs(z))));
}

void JuliaFrac::calcOneRow(cv::Mat& img, int i) {
    //arbitrary chosen parameter
    std::complex<double> C(0.285, 0.01);

    for (unsigned int j = 0; j < m_uiResolutionX; j++) {

        double x0 = transform(j, 0, (m_uiResolutionX - 1), m_dImgPlaneX[0], m_dImgPlaneX[1]);
        double y0 = transform(i, 0, (m_uiResolutionY - 1), m_dImgPlaneY[0], m_dImgPlaneY[1]);
        
        unsigned int it = julia(C, std::complex<double>(x0, y0));

        img(Rect(j, i, 1, 1)) = findColor(it);
    }
}
