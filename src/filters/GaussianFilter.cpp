#include "GaussianFilter.h"


Mat GaussianFilter::applyOnImage(Mat* img) {
    int k = this->n >> 1;
    int h = this->m >> 1;
    double **filter = new double*[this->n];
    for (int i = 0; i < n; ++i) 
        filter[i] = new double[this->m];

    for (int j = -k; j <= k; ++j)
        for (int i = -h; i <= h; ++i)
            filter[j+k][i+h] = (1 / (2 * PI)) * exp(-(pow(j, 2) + pow(i, 2)) / 2.0);

    Mat result = convolution(img, filter, this->n, this->m);

    for (int i = 0; i < this->n; ++i) 
        delete[] filter[i];
    delete[] filter;
    return result;
}

