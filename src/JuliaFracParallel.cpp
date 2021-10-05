#include "JuliaFracParallel.h"
#include <future>
#include "Stoper.h"

JuliaFracParallel::JuliaFracParallel(unsigned int uiResX, unsigned int uiResY) : JuliaFrac(uiResX, uiResY) {
}

void JuliaFracParallel::calculate(cv::Mat& img) {
    Stoper stoper;

    std::vector<std::future<void>> tasks;
    for (unsigned int i = 0; i < m_uiResolutionY; i++) {
        auto future = std::async(&JuliaFracParallel::calcOneRow, this, img, i);
        tasks.emplace_back(std::move(future));
    }
    for (auto&& future : tasks) {
        future.wait();
    }
}


