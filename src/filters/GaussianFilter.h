#ifndef GAUSSIAN_FILTER
#define GAUSSIAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class GaussianFilter: public BaseFilter {
private:
protected:
public:
    GaussianFilter(int _n): BaseFilter(_n) {}
    Mat applyOnImage(Mat* img);
    ~GaussianFilter() {}
};

#endif
