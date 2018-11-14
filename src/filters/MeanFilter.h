#ifndef MEAN_FILTER
#define MEAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class MeanFilter: public BaseFilter {
private:
protected:
public:
    Mat applyOnImage(int n, Mat* img);
};

#endif
