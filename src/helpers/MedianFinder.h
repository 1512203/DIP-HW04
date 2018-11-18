#ifndef MEDIANFINDER_INCLUDED
#define MEDIANFINDER_INCLUDED

#include "ds/Heap.h"

class MedianFinder {
private:
    Heap* heapMin;
    Heap* heapMax;
    void rebalance();
public:
    MedianFinder();
    void push(int y, int x, int c);
    void extract(int y, int x);
    int getMedian();
    ~MedianFinder();
};

#endif
