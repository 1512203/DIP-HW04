#ifndef MEAN_FILTER
#define MEAN_FILTER

#include "../common.h"
#include "BaseFilter.h"

class MeanFilter: public BaseFilter {
private:
protected:
public:
    MeanFilter(int _n, int _m): BaseFilter(_n, _m) {}
    Mat applyOnImage(Mat* img);
    ~MeanFilter() {}
};

#endif
