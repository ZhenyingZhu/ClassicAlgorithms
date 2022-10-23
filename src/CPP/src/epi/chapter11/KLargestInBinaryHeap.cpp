#include "KLargestInBinaryHeap.hpp"

#include <vector>
#include <queue>
#include <string>
#include <functional>
#include <iostream>
#include <stdexcept>
#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::function;
using std::invalid_argument;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    vector<int> KLargestInBinaryHeap::kLargestInBinaryHeap(const vector<int> &array, size_t k) {
        if (k >= array.size())
            throw invalid_argument("k too large");

        struct HeapEntry {
            size_t index;
            int value;
        };

        vector<int> result;

        priority_queue< HeapEntry, vector<HeapEntry>, function<bool(HeapEntry, HeapEntry)> > maxHeap
                ( [](const HeapEntry &a, const HeapEntry &b) -> bool {return a.value < b.value;} );
        maxHeap.push( {0, array[0]} );
        for (size_t i = 0; i != k; ++i) {
            result.push_back( maxHeap.top().value );
            size_t idx = maxHeap.top().index;

            maxHeap.pop();

            if (idx * 2 + 1 < array.size())
                maxHeap.push( {idx * 2 + 1, array[idx * 2 + 1]} );
            if (idx * 2 + 2 < array.size())
                maxHeap.push( {idx * 2 + 2, array[idx * 2 + 2]} );
        }

        return result;
    }

    bool KLargestInBinaryHeap::test() {
        vector<int> input = {561, 314, 401, 28, 156, 359, 271, 11, 3};

        vector<int> ans = {561, 401, 359, 314};
        vector<int> res = kLargestInBinaryHeap(input, 4);

        if (ans != res) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter11
} // epi
