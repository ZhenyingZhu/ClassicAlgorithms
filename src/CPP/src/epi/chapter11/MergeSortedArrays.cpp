#include "MergeSortedArrays.hpp"

#include <vector>
#include <queue>
#include <functional>
#include <iterator>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::greater;
using std::next;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    struct MergeSortedArrays::IteratorCurrentAndEnd {
        bool operator>(const IteratorCurrentAndEnd &that) const {
            return *current > *that.current;
        }

        vector<int>::const_iterator current, end;
    };

    vector<int> MergeSortedArrays::mergeSortedArrays(const vector<vector<int>> &sortedArrays) {
        priority_queue<IteratorCurrentAndEnd, vector<IteratorCurrentAndEnd>, greater<IteratorCurrentAndEnd>> minHeap;

        for (const vector<int> &array : sortedArrays) {
            if (!array.empty()) {
                minHeap.push( IteratorCurrentAndEnd{array.cbegin(), array.cend()} );
            }
        }

        vector<int> res;
        while (!minHeap.empty()) {
            auto smallestArray = minHeap.top();
            minHeap.pop();
            res.push_back(*smallestArray.current);

            ++smallestArray.current;
            if (smallestArray.current != smallestArray.end) {
                // the code in the answer use the idea that *end return a value doesn't matter
                // though it works, it is bad to access un-initialized memory
                minHeap.push(smallestArray);
            }
        }

        return res;
    }

    bool MergeSortedArrays::test() {
        vector<int> v1 = {3, 5, 7};
        vector<int> v2 = {0, 6};
        vector<int> v3 = {0, 6, 16};
        vector<vector<int>> input = {v1, v2, v3};
        vector<int> ans = {0, 0, 3, 5, 6, 6, 7, 16};

        vector<int> res = mergeSortedArrays(input);
        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter11
} // epi
