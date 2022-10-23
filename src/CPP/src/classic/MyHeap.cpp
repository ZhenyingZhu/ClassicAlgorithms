#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Source]: http://interactivepython.org/courselib/static/pythonds/Trees/BinaryHeapImplementation.html
// http://www.1point3acres.com/bbs/thread-226221-1-1.html

// 1. complete binary tree
// 2. parent is smaller or equal to children
// 3. dummy 0 at first so that find parent is n/2

class MyHeap {
public:
    MyHeap(): size(0) {
        store.push_back(0);
    }

    bool empty() {
        return size == 0;
    }

    int top() {
        if (size == 0)
            return INT_MAX;
        return store[1];
    }

    void insert(int val) {
        store.push_back(val);
        size++;

        int idx = store.size() - 1;
        int par = idx / 2;
        while (par != 0 && store[idx] < store[par]) {
            swap(store[idx], store[par]);
            idx = par;
            par = idx / 2;
        }
    }

    void pop() {
        if (size == 0)
            return;

        size--;
        store[1] = store.back();
        store.pop_back();

        int idx = 1;
        // it could be only one left child, but still need to compare
        while (idx * 2 < (int)store.size()) {
            int minChildIdx = getMinChild(idx);
            if (store[minChildIdx] >= store[idx])
                break;

            swap(store[idx], store[minChildIdx]);
            idx = minChildIdx;
        }
    }

private:
    int getMinChild(int idx) {
        if (idx * 2 + 1 >= (int)store.size()) {
            return idx * 2;
        }

        if (store[idx * 2 + 1] < store[idx * 2])
            return idx * 2 + 1;
        return idx * 2;
    }

private:
    vector<int> store;
    int size;
};

int main() {
    MyHeap h;

    vector<int> vec = {1, 3, 2, 4, 4, 2};
    for (int &num : vec) {
        h.insert(num);
        cout << h.top() << ", ";
    }
    cout << endl;

    while (!h.empty()) {
        cout << h.top() << ", ";
        h.pop();
    }
    cout << endl;

    return 0;
}
