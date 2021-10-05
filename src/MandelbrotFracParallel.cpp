#include "MandelbrotFracParallel.h"
#include <future>
#include "Stoper.h"

MandelbrotFracParallel::MandelbrotFracParallel(unsigned int uiResX, unsigned int uiResY) : 
    MandelbrotFrac(uiResX, uiResY) {
}

void MandelbrotFracParallel::calculate(cv::Mat& img) {
    Stoper stoper;

    std::vector<std::future<void>> tasks;
    for (unsigned int i = 0; i < m_uiResolutionY; i++) {
        auto future = std::async(&MandelbrotFracParallel::calcOneRow, this, img, i);
        tasks.emplace_back(std::move(future));
    }
    for (auto&& future : tasks) {
        future.wait();
    }
}
