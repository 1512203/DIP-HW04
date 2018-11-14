#ifndef GAUSSIAN_FILTER
#define GAUSSIAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class GaussianFilter: public BaseFilter {
private:
protected:
public:
    Mat applyOnImage(int n, Mat* img);
};

#endif
