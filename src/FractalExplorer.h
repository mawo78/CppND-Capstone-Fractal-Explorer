#pragma once
#include <string>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/opencv.hpp"
#include "AbstractFrac.h"

class FractalExplorer
{
public:
	FractalExplorer(int argc, char* argv[]);
	void show();
private:
	static cv::Mat m_img;
	static const unsigned int X_RES = 1024;
	static const unsigned int Y_RES = 768;

	bool m_bFullscreen;
	bool m_bJulia;
	bool m_bParallel;
	static std::unique_ptr<AbstractFrac> m_frac;
	static const char* FE_WINDOW_NAME;

	static void callBackFunc(int event, int x, int y, int flags, void* userdata);
	void printHelp();
};

