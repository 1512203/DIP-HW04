#include "MedianFilter.h"


Mat MedianFilter::applyOnImage(Mat* img) {
    int k = this->n >> 1;
    int h = this->m >> 1;

    Mat result = Mat::zeros(img->size(), img->type());
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
    return result;
}

