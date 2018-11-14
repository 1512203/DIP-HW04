cmake_minimum_required(VERSION 2.8)

# The project name
project( DIP_HW04 )

# Find OpenCV Package and include it
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} )

# Set C++ 11
set( CMAKE_CXX_STANDARD 11 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_CXX_EXTENSIONS OFF )

# Project sources
set ( SOURCE_DIR src )
set ( SOURCE_FILTERS_DIR src/filters )
set ( PROJECT_SOURCES 
    ${SOURCE_DIR}/common.h 
    ${SOURCE_DIR}/common.cpp 
    ${SOURCE_DIR}/BaseProcessor.h 
    ${SOURCE_DIR}/BaseProcessor.cpp 
    ${SOURCE_DIR}/Smoother.h 
    ${SOURCE_DIR}/Smoother.cpp 
    ${SOURCE_FILTERS_DIR}/BaseFilter.h
    ${SOURCE_FILTERS_DIR}/BaseFilter.cpp
    ${SOURCE_FILTERS_DIR}/GaussianFilter.h
    ${SOURCE_FILTERS_DIR}/GaussianFilter.cpp
    ${SOURCE_FILTERS_DIR}/MeanFilter.h
    ${SOURCE_FILTERS_DIR}/MeanFilter.cpp
    ${SOURCE_FILTERS_DIR}/MedianFilter.h
    ${SOURCE_FILTERS_DIR}/MedianFilter.cpp
)

# The main program
add_executable( DIP_HW04 ${SOURCE_DIR}/main.cpp ${PROJECT_SOURCES} )

# Add link libraries
target_link_libraries( DIP_HW04 ${OpenCV_LIBS} )

