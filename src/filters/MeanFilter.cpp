#include "MeanFilter.h"

Mat MeanFilter::applyOnImage(Mat* img) {
    int k = n >> 1;
    double **filter = new double*[n];
    for (int i = 0; i < n; ++i) {
        filter[i] = new double[n];
    }

    for (int u = -k; u <= k; ++u) {
        for (int v = -k; v <= k; ++v) {
            filter[u+k][v+k] = 1.0 / (n * n);
        }
    }

    Mat result = convolution(img, filter, n);

    for (int i = 0; i < n; ++i) {
        delete[] filter[i];
    }
    delete[] filter;
    return result;
}

