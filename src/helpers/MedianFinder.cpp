#include "MedianFinder.h"


MedianFinder::MedianFinder() {
    this->heapMin = new Heap();
    this->heapMax = new Heap(true);
}


void MedianFinder::rebalance() {
    if (this->heapMax->size() > 0 && this->heapMin->size() > 0) {
        KeyValue topMax = this->heapMax->top();
        KeyValue topMin = this->heapMin->top();
        if (topMax.c > topMin.c) {
            this->heapMax->pop();
            this->heapMin->pop();
            this->heapMax->push(topMin.y, topMin.x, topMin.c);
            this->heapMin->push(topMax.y, topMax.x, topMax.c);
        }
    }
    if (this->heapMax->size() > this->heapMin->size()) {
        KeyValue topMax = this->heapMax->pop();
        this->heapMin->push(topMax.y, topMax.x, topMax.c);
    }
    else if (this->heapMin->size() > this->heapMax->size() + 1) {
        KeyValue topMin = this->heapMin->pop();
        this->heapMax->push(topMin.y, topMin.x, topMin.c);
    }
}


void MedianFinder::push(int y, int x, int c) {
    this->heapMax->push(y, x, c);
    this->rebalance();
}


void MedianFinder::extract(int y, int x) {
    if (this->heapMin->keyExist(y, x)) 
        this->heapMin->extract(y, x);
    else if (this->heapMax->keyExist(y, x)) 
        this->heapMax->extract(y, x);
    this->rebalance();
}


int MedianFinder::getMedian() {
    int result;
    if (this->heapMax->size() == this->heapMin->size()) {
        KeyValue topMax = this->heapMax->top();
        KeyValue topMin = this->heapMin->top();
        result = (topMax.c + topMin.c) / 2;
    }
    else {
        KeyValue topMin = this->heapMin->top();
        result = topMin.c;
    }
    return result;
}


MedianFinder::~MedianFinder() {
    delete heapMin;
    delete heapMax;
}
