#include "MedianFilter.h"


Mat MedianFilter::applyOnImage(Mat* img) {
    int k = this->n >> 1;
    int h = this->m >> 1;

    Mat result = Mat::zeros(img->size(), img->type());
    if (this->n * this->m > 10000) {
        for (int c = 0; c < 3; ++c) {
            MedianFinder finder;

            for (int j = 0; j < k; ++j) 
                for (int i = 0; i < h; ++i) 
                    if (j < img->rows && i < img->cols) 
                        finder.push(j, i, img->at<Vec3b>(j, i)[c]);

            for (int y = 0, x = -1, veloc = 1; y < img->rows; ++y, veloc = -veloc) {

                for (int i = -h; i <= h; ++i) 
                    if (x-i >= 0 && x-i < img->cols) {
                        if (y+k < img->rows) 
                            finder.push(y+k, x-i, img->at<Vec3b>(y+k, x-i)[c]);
                        if (y-k-1 >= 0) 
                            finder.extract(y-k-1, x-i);
                    }

                do {
                    x += veloc;
                    for (int j = -k; j <= k; ++j) 
                        if (y-j >= 0 && y-j < img->rows) {
                            if (x+veloc*h >= 0 && x+veloc*h < img->cols) 
                                finder.push(y-j, x+veloc*h, img->at<Vec3b>(y-j, x+veloc*h)[c]);
                            if (x-veloc*(h+1) >= 0 && x-veloc*(h+1) < img->cols) 
                                finder.extract(y-j, x-veloc*(h+1));
                        }
                    result.at<Vec3b>(y, x)[c] = finder.getMedian();
                } while (x >= 0 && x < img->cols);
            }
        }
    }
    else {
        for (int y = 0; y < img->rows; ++y) 
            for (int x = 0; x < img->cols; ++x) 
                for (int c = 0; c < 3; ++c) {
                    vector<int> valueArray;
                    for (int j = -k; j <= k; ++j)
                        for (int i = -h; i <= h; ++i)
                            if (y-j >= 0 && y-j < img->rows && x-i >= 0 && x-i < img->cols)
                                valueArray.push_back(img->at<Vec3b>(y-j, x-i)[c]);
                    sort(valueArray.begin(), valueArray.end());
                    int len = valueArray.size();
                    if (len % 2 == 0) 
                        result.at<Vec3b>(y, x)[c] = (valueArray[len/2] + valueArray[(len/2)-1]) / 2;
                    else 
                        result.at<Vec3b>(y, x)[c] = valueArray[len/2];
                }
    }
    return result;
}

