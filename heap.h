#ifndef heap_H_
#define heap_H_
#pragma warning(disable:4996)

typedef struct TAG_ELEMENT {
    int key;
}ELEMENT;

typedef ELEMENT* ElementT;

typedef struct TAG_HEAP {
    int capacity;
    int size;
    ElementT* H;
}HEAP;

HEAP* Initialize(int n);
void printHeap(HEAP* A);
void writeHeap(HEAP* A);
void insert(HEAP* A, ELEMENT* B);
int extractMin(HEAP* heap);
void decreaseKey(HEAP* heap, int i, int key);
int minHeapify(HEAP* heap, int i);
int buildMinHeap(HEAP* heap);
void initializeSingleSource()

#endif