#ifndef GAUSSIAN_FILTER
#define GAUSSIAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class GaussianFilter: public BaseFilter {
private:
protected:
public:
    GaussianFilter(int _n, int _m): BaseFilter(_n, _m) {}
    Mat applyOnImage(Mat* img);
    ~GaussianFilter() {}
};

#endif
