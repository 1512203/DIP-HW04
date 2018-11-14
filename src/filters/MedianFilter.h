#ifndef MEDIAN_FILTER
#define MEDIAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class MedianFilter: public BaseFilter {
private:
protected:
public:
    Mat applyOnImage(int n, Mat* img);
};

#endif

