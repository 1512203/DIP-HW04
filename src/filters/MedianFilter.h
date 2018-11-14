#ifndef MEDIAN_FILTER
#define MEDIAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class MedianFilter: public BaseFilter {
private:
protected:
public:
    MedianFilter(int _n): BaseFilter(_n) {}
    Mat applyOnImage(Mat* img);
    ~MedianFilter() {}
};

#endif

