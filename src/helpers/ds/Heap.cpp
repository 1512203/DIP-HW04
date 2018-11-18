#include "Heap.h"


bool Heap::less(KeyValue* u, KeyValue* v) {
    if (this->reverse) 
        return u->c > v->c;
    return u->c < v->c;
}


void Heap::upHeap(int i) {
    KeyValue item = this->items[i];
    while (i > 0 && this->less(&item, this->items + ((i - 1) >> 1))) {
        this->items[i] = this->items[(i - 1) >> 1];
        this->position[this->items[i].y][this->items[i].x] = i;
        i = (i - 1) >> 1;
    }
    this->items[i] = item;
    this->position[item.y][item.x] = i;
}


void Heap::downHeap(int i) {
    KeyValue item = this->items[i];
    do {
        int j = (i << 1) + 1;
        if (j >= n) 
            break;
        if (j + 1 < n && this->less(this->items + j + 1, this->items + j)) 
            j = j + 1;
        if (!this->less(this->items + j, &item))
            break;
        this->items[i] = this->items[j];
        this->position[this->items[i].y][this->items[i].x] = i;
        i = j;
    } while (true);
    this->items[i] = item;
    this->position[item.y][item.x] = i;
}


Heap::Heap(bool reverse) {
    this->n = 0;
    this->allocated = 0;
    this->items = NULL;
    this->reverse = reverse;
}


int Heap::size() {
    return this->n;
}


bool Heap::isEmpty() {
    return this->n == 0;
}


bool Heap::keyExist(int y, int x) {
    if (this->position.find(y) == this->position.end())
        return false;
    if (this->position[y].find(x) == this->position[y].end())
        return false;
    return true;
}


void Heap::push(int y, int x, int c) {
    if (this->n == this->allocated) {
        this->allocated += BLOCK_SIZE;
        this->items = (KeyValue*)realloc(
                this->items,
                this->allocated * sizeof(KeyValue)
        );
    }
    this->position[y][x] = this->n;
    this->items[this->n++] = KeyValue(y, x, c);
    this->upHeap(this->n - 1);
}


KeyValue Heap::top() {
    assert(!this->isEmpty());
    return this->items[0];
}


KeyValue Heap::pop() {
    assert(!this->isEmpty());
    KeyValue result = this->items[0];
    this->position[result.y].erase(result.x);
    if (this->position[result.y].empty())
        this->position.erase(result.y);
    this->n--;
    if (this->n > 0) {
        this->items[0] = this->items[this->n];
        this->position[this->items[0].y][this->items[0].x] = 0;
        this->downHeap(0);
    }
    return result;
}


KeyValue Heap::extract(int y, int x) {
    assert(this->position.find(y) != this->position.end());
    assert(this->position[y].find(x) != this->position[y].end());
    int i = this->position[y][x];
    KeyValue result = this->items[i];
    this->position[result.y].erase(result.x);
    if (this->position[result.y].empty())
        this->position.erase(result.y);
    this->n--;
    if (this->n != i) {
        this->items[i] = this->items[this->n];
        this->position[this->items[i].y][this->items[i].x] = i;
        this->downHeap(i);
        this->upHeap(i);
    }
    return result;
}


KeyValue Heap::get(int y, int x) {
    assert(this->position.find(y) != this->position.end());
    assert(this->position[y].find(x) != this->position[y].end());
    int i = this->position[y][x];
    KeyValue result = this->items[i];
    return result;
}


Heap::~Heap() {
    free(this->items);
}


void Heap::assignTop(KeyValue t) {
    assert(this->n > 0);
    this->position[this->items[0].y].erase(this->items[0].x); 
    if (this->position[this->items[0].y].empty()) 
        this->position.erase(this->items[0].y);
    this->items[0] = t;
    this->position[t.y][t.x] = 0;
}


void Heap::printAllElements() {
    printf("Values:");
    for (int i = 0; i < this->n; ++i)
        printf(" (%d, %d, %d)", this->items[i].y, this->items[i].x, this->items[i].c);
    printf("\nPositions:");
    for (map<int, map<int, int>>::iterator it = this->position.begin(); it != this->position.end(); ++it)
        for (map<int, int>::iterator jt = it->second.begin(); jt != it->second.end(); ++jt)
            printf(" (%d, %d, %d)", it->first, jt->first, jt->second);
    printf("\n");
}

