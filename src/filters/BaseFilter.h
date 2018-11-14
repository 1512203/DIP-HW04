#ifndef BASE_FILTER
#define BASE_FILTER

#include "../common.h"

class BaseFilter {
private:
protected:
public:
    virtual Mat applyOnImage(int n, Mat* img) = 0;
};

#endif
