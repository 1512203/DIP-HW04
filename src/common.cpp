#include "common.h"


void displayImage(string windowName, Mat img) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, img);
}


Mat readImage(string pathToImage) {
    return imread(pathToImage, IMREAD_COLOR);
}


bool isGrayscale(Mat img) {
    for (int y = 0; y < img.rows; ++y)
        for (int x = 0; x < img.cols; ++x)
            for (int c = 0; c < 2; ++c)
                if (img.at<Vec3b>(y, x)[c] != img.at<Vec3b>(y, x)[c+1])
                    return false;
    return true;
}


bool isEqualDouble(double a, double b) {
    double delta = a - b;
    return delta <= EPSILON && delta >= -EPSILON;
}


bool isLessDouble(double a, double b) {
    return a + EPSILON < b;
}


Mat convolution(Mat* img, double** filter, int n, int m) {  // n: rows (y axis), m: cols (x axis)
    assert(n % 2 == 1 && m % 2 == 1);

    Mat result = Mat::zeros(img->size(), img->type());
    int k = n >> 1;         // y axis
    int h = m >> 1;         // x axis

    for (int y = 0; y < img->rows; ++y) 
        for (int x = 0; x < img->cols; ++x) 
            for (int c = 0; c < 3; ++c) {
                double value = 0.0;
                for (int j = -k; j <= k; ++j)           // y axis
                    for (int i = -h; i <= h; ++i)       // x axis
                        if (y-j >= 0 && y-j < img->rows && x-i >= 0 && x-i < img->cols) 
                            value += img->at<Vec3b>(y-j, x-i)[c] * filter[j+k][i+h];
                result.at<Vec3b>(y, x)[c] = min(max(cvRound(value), 0), 255);
            }
    return result;
}

