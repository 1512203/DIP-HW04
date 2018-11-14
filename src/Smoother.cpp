#include "Smoother.h"
#include "filters/BaseFilter.h"
#include "filters/GaussianFilter.h"
#include "filters/MeanFilter.h"
#include "filters/MedianFilter.h"


Mat Smoother::processImage(argv_t kwargs) {
    BaseFilter* filter = NULL;
    int kernelSize = stoi(kwargs["kernel_size"]);
    if (kwargs["filter"] == MEAN_FILTER_LABEL) {
        filter = new MeanFilter(kernelSize);
    }
    else if (kwargs["filter"] == MEDIAN_FILTER_LABEL) {
        filter = new MedianFilter(kernelSize);
    }
    else if (kwargs["filter"] == GAUSSIAN_FILTER_LABEL) {
        filter = new GaussianFilter(kernelSize);
    }

    Mat result = filter->applyOnImage(&(this->image));

    if (filter) {
        delete filter;
    }

    return result;
}
