#include "Smoother.h"
#include "filters/BaseFilter.h"
#include "filters/GaussianFilter.h"
#include "filters/MeanFilter.h"
#include "filters/MedianFilter.h"


Mat Smoother::processImage(argv_t kwargs) {
    if (kwargs["grayscale"] == REQUIRE_GRAYSCALE && !isGrayscale(this->image)) {
        cerr << ERROR_MESS_INVALID_GRAYSCALE_IMAGE << endl;
        return Mat::zeros(this->image.size(), this->image.type());
    }
    BaseFilter* filter = NULL;
    int n = stoi(kwargs["height"]);
    int m = kwargs.find("width") != kwargs.end() ? stoi(kwargs["width"]) : n;

    if (kwargs["filter"] == MEAN_FILTER_LABEL) {
        filter = new MeanFilter(n, m);
    }
    else if (kwargs["filter"] == MEDIAN_FILTER_LABEL) {
        filter = new MedianFilter(n, m);
    }
    else if (kwargs["filter"] == GAUSSIAN_FILTER_LABEL) {
        filter = new GaussianFilter(n, m);
    }

    Mat result = filter->applyOnImage(&(this->image));

    if (filter) { 
        delete filter;
    }
    return result;
}
