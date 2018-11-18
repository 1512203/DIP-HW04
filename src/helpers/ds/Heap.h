#ifndef HEAP_INCLUDED
#define HEAP_INCLUDED

#include <cassert>
#include <cstdlib>
#include <cstring>
#include <map>
using std::map;


const int BLOCK_SIZE = 64;

struct KeyValue {
    int y;  // Coordinate along y axis
    int x;  // Coordinate along x axis
    int c;  // Color value
    KeyValue(int _y, int _x, int _c): y(_y), x(_x), c(_c) {}
};


class Heap {
private:
    int n;
    int allocated;
    KeyValue* items;
    bool reverse;
    map < int, map < int, int > > position;

    bool less(KeyValue* u, KeyValue* v);

    void upHeap(int i);
    void downHeap(int i);
public:
    Heap(bool reverse = false);
    void printAllElements();
    int size();
    bool isEmpty();
    bool keyExist(int y, int x);
    void push(int y, int x, int c);
    KeyValue pop();
    KeyValue top();
    KeyValue extract(int y, int x);
    KeyValue get(int y, int x);
    void assignTop(KeyValue t);
    ~Heap();
};

#endif
