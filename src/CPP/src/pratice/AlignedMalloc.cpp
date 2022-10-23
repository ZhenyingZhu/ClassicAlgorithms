#include <iostream>

using namespace std;

void understandMalloc() {
    int *p = (int*)malloc(100);
    cout << sizeof(*p) << endl;
    cout << p << endl;
    cout << ++p << endl;
}

void understandArray() {
    int size = 10;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i + 1;
    cout << arr[0] << endl;
    cout << arr[-1] << endl;
}

// [Source]: CTCI v5, Chapter 13.9
// http://www.1point3acres.com/bbs/thread-226625-1-1.html

void alignedMallocCannotFree(size_t requiredBits, size_t alignment) {
    // requiredBits is actually bytes
    void *p = malloc(requiredBits + alignment - 1);
    cout << p << endl;
    size_t st = ((size_t)p + alignment - 1) & ~(alignment - 1);
    void *q = (void*)st;
    cout << q << endl;
}

void* alignedMalloc(size_t requireBytes, size_t alignment) {
    // store the p1 in the 8 bytes (64 bit machine use 8 bytes to store a pointer) just before p2
    size_t offset = alignment - 1 + sizeof(void*);

    // if fail to malloc, return NULL
    void *p1;
    if ( (p1 = malloc(offset + requireBytes)) == NULL)
        return NULL;

    // to store a pointer in the byte before start, needs make p2 a pointer to a void* array
    size_t st = ((size_t)p1 + offset) & ~(alignment - 1);
    void **p2 = (void**)st;
    p2[-1] = p1;
    return p2;
}

void alignedFree(void *p) {
    void *p1 = ((void**)p)[-1];
    free(p1);
}

int main() {
    for (int i = 0; i < 5; i++) {
        void *p = alignedMalloc(100, 128);
        cout << p << endl;
        alignedFree(p);
    }

    return 0;
}
