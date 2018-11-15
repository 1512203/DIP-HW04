#ifndef BASE_FILTER
#define BASE_FILTER

#include "../common.h"

class BaseFilter {
private:
protected:
    int n;                  // Kernel size
public:
    BaseFilter(int _n): n(_n) { assert(this->n % 2 == 1); }
    virtual Mat applyOnImage(Mat* img) = 0;
    virtual ~BaseFilter() {}
};

#endif
