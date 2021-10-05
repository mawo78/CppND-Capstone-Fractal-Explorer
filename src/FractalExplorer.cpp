#include "FractalExplorer.h"

#include <iostream>
#include "FractalExplorer.h"
#include "MandelbrotFrac.h"
#include "MandelbrotFracParallel.h"
#include "JuliaFrac.h"
#include "JuliaFracParallel.h"

const char* FractalExplorer::FE_WINDOW_NAME = "FractalExplorer";
std::unique_ptr<AbstractFrac> FractalExplorer::m_frac;
cv::Mat FractalExplorer::m_img(Y_RES, X_RES, CV_8UC3);

FractalExplorer::FractalExplorer(int argc, char* argv[]) : m_bFullscreen(false), 
m_bJulia(false), m_bParallel(false) {
    for (int i = 1; i < argc; i++) {
        std::string pom = argv[i];
        if ("-h" == pom || "--help" == pom) {
            printHelp();
        }
        else if("-f" == pom ||"--fullscreen" == pom) {
            m_bFullscreen = true;
        }
        else if ("-p" == pom || "--parallel" == pom) {
            m_bParallel = true;
        }
        else if ("-j" == pom || "--julia" == pom) {
            m_bJulia = true;
        }
        else {
            std::cout << "Unknown param - " << pom << std::endl;
        }
    }
}

void FractalExplorer::printHelp() {
    std::cout << "Usage: " << std::endl;
    std::cout << "FractalExplorer [-h|--help][-f|--fullscreen][-p|--parallel][-j|--julia]," << std::endl;
    std::cout << "[-h|--help] this help," << std::endl;
    std::cout << "[-f|--fullscreen] fullscreen mode," << std::endl;
    std::cout << "[-p|--parallel] multithreaded version," << std::endl;
    std::cout << "[-j|--julia] Julia fractal, default: Mandelbrot," << std::endl;
    std::cout << "LMB: zoom in, RMB: zoom out." << std::endl;
}

void FractalExplorer::callBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == cv::EVENT_LBUTTONDOWN) {
        m_frac->zoomIn(x, y);
        m_frac->calculate(m_img);
        cv::imshow(FE_WINDOW_NAME, m_img);
    }
    else if (event == cv::EVENT_RBUTTONDOWN) {
        m_frac->zoomOut(x, y);
        m_frac->calculate(m_img);
        cv::imshow(FE_WINDOW_NAME, m_img);
    }
}

void FractalExplorer::show() {

    if (m_bFullscreen) {
        cv::namedWindow(FE_WINDOW_NAME, cv::WINDOW_NORMAL);
        cv::setWindowProperty(FE_WINDOW_NAME, cv::WND_PROP_FULLSCREEN, cv::WINDOW_FULLSCREEN);
    }
    else {
        cv::namedWindow(FE_WINDOW_NAME, cv::WINDOW_AUTOSIZE);
    }

    if (m_bParallel) {
        std::cout << "Starting parallel version of ";
        if (m_bJulia) {
            std::cout << "Julia fractal" << std::endl;
            m_frac.reset(new JuliaFracParallel(X_RES, Y_RES));
        }
        else {
            std::cout << "Mandelbrot fractal" << std::endl;
            m_frac.reset(new MandelbrotFracParallel(X_RES, Y_RES));
        }
    }
    else {
        std::cout << "Starting single-threaded version of ";
        if (m_bJulia) {
            std::cout << "Julia fractal" << std::endl;
            m_frac.reset(new JuliaFrac(X_RES, Y_RES));
        }
        else {
            std::cout << "Mandelbrot fractal" << std::endl;
            m_frac.reset(new MandelbrotFrac(X_RES, Y_RES));
        }
    }

    cv::setMouseCallback(FE_WINDOW_NAME, (cv::MouseCallback)FractalExplorer::callBackFunc, NULL);
    m_frac->calculate(m_img);

    cv::imshow(FE_WINDOW_NAME, m_img);

    cv::waitKey(0);
    cv::destroyAllWindows();
}