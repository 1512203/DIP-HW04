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


Mat convolution(Mat* img, double** filter, int kernelSize) {
    assert(kernelSize % 2 == 1);

    Mat result = Mat::zeros(img->size(), img->type());
    int k = kernelSize >> 1;

    for (int y = 0; y < img->rows; ++y) 
        for (int x = 0; x < img->cols; ++x) 
            for (int j = -k; j <= k; ++j) 
                for (int i = -k; i <= k; ++i) 
                    if (y-j >= 0 && y-j < img->rows && x-i >= 0 && x-i < img->cols) 
                        for (int c = 0; c < 3; ++c) 
                            result.at<Vec3b>(y, x)[c] += img->at<Vec3b>(y-j, x-i)[c] * filter[j+k][i+k];
    return result;
}

