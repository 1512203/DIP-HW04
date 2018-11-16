#ifndef BASE_FILTER
#define BASE_FILTER

#include "../common.h"

class BaseFilter {
private:
protected:
    int n, m;                  // Kernel size (n: y axis, m: x axis)
public:
    BaseFilter(int _n, int _m): n(_n), m(_m) { assert(this->n % 2 == 1 && this->m % 2 == 1); }
    virtual Mat applyOnImage(Mat* img) = 0;
    virtual ~BaseFilter() {}
};

#endif
