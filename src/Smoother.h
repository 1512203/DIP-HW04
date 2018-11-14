#ifndef SMOOTHER_INCLUDED
#define SMOOTHER_INCLUDED

#include "common.h"
#include "BaseProcessor.h"

class Smoother: public BaseProcessor {
private:
protected:
    Mat processImage(argv_t kwargs);
public:
    Smoother(string pathToImage): BaseProcessor(pathToImage) {}
    ~Smoother() {}
};

#endif
