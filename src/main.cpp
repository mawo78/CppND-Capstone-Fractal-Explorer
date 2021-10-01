#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

int main() {
    std::cout << "Hello World!" << "\n";

    cv::Mat image; // create an empty image
    image = cv::imread("../data/241543970_2038651729643849_1459651278087057352_n_160.jpg");
    std::cout << "This image is " << image.rows << " x " << image.cols << std::endl;
    // define the window (optional)
    cv::namedWindow("Original Image");
    // show the image
    cv::imshow("Original Image", image);
    cv::waitKey(0);

    return 0;
}