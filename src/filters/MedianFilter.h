#ifndef MEDIAN_FILTER
#define MEDIAN_FILTER

#include "../common.h"
#include "BaseFilter.h"
#include "../helpers/MedianFinder.h"

class MedianFilter: public BaseFilter {
private:
protected:
public:
    MedianFilter(int _n, int _m): BaseFilter(_n, _m) {}
    Mat applyOnImage(Mat* img);
    ~MedianFilter() {}
};

#endif

