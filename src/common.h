#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED



/* Include libraries */

// C Library
#include <cstring>

// C++ Standard Libraries
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// OpenCV Libraries
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



/* Include elements in namespace std */

// Std input/output
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

// Std data structures
using std::map;
using std::string;
using std::vector;

// Std utility functions
using std::max;
using std::min;
using std::stof;
using std::sort;


/* Include elements in namespace cv */

// OpenCV Constants 
using cv::IMREAD_COLOR;
using cv::WINDOW_AUTOSIZE;

// OpenCV data structures
using cv::Mat;
using cv::Point;
using cv::Scalar;
using cv::Vec3b;

// OpenCV utility functions
using cv::imshow;
using cv::imread;
using cv::imwrite;
using cv::namedWindow;
using cv::saturate_cast;
using cv::waitKey;



/* Define to pass argument */

typedef map<string, string> argv_t;
typedef map<string, void*> argv_json;



/* Define constants */

#define ERROR_MESS_INVALID_ARGUMENTS                "Invalid arguments!"
#define ERROR_MESS_INVALID_COMMANDS                 "Invalid command!"
#define ERROR_MESS_INVALID_GRAYSCALE_IMAGE          "Invalid grayscale image!"


/* Define commands */

#define COMMAND_MEAN_FILTER_GRAYSCALE               "--mg"
#define COMMAND_MEAN_FILTER_RGB                     "--mc"
#define COMMAND_MEDIAN_FILTER_GRAYSCALE             "--meg"
#define COMMAND_MEDIAN_FILTER_RGB                   "--mec"
#define COMMAND_GAUSSIAN_FILTER_GRAYSCALE           "--gg"
#define COMMAND_GAUSSIAN_FILTER_RGB                 "--gc"

#define MEAN_FILTER_LABEL                           "mean"
#define MEDIAN_FILTER_LABEL                         "median"
#define GAUSSIAN_FILTER_LABEL                       "gaussian"

#define REQUIRE_GRAYSCALE                           "1"
#define NOT_REQUIRE_GRAYSCALE                       "0"


const double EPSILON = 1E-9;
const double PI = acos(-1.0);


/* Some utility function */

Mat readImage(string pathToImage);
void displayImage(string windowName, Mat img);
bool isGrayscale(Mat img);
bool isEqualDouble(double a, double b);
bool isLessDouble(double a, double b);
Mat convolution(Mat* img, double** filter, int n, int m);

#endif

