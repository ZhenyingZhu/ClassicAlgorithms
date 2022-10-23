#include "SortKIncreasingDecreasingArray.hpp"

#include <vector>
#include <queue>
#include <functional>
#include <iterator>
#include <iostream>

#include "../../MyUtils.h"

using std::vector;
using std::priority_queue;
using std::greater;
using std::reverse_iterator;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter11 {
    struct SortKIncreasingDecreasingArray::IteratorCurrentAndEnd {
        bool operator>(const IteratorCurrentAndEnd &that) const {
            return *current > *that.current;
        }

        vector<int>::const_iterator current, end;
    };

    vector<int> SortKIncreasingDecreasingArray::mergeSortedArrays(const vector<vector<int>> &sortedArrays) {
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
                minHeap.push(smallestArray);
            }
        }

        return res;
    }

    vector<int> SortKIncreasingDecreasingArray::sortKIncreasingDecreasingArray(const vector<int> &array) {
        vector<vector<int>> sortedSubArrays;
        typedef enum { INCREASING, DECREASING } SubArrayType;

        SubArrayType type = INCREASING;
        vector<int>::const_iterator st = array.begin();

        for (vector<int>::const_iterator it = array.begin() + 1; it != array.end(); ++it) {
            if (type == INCREASING && *it < *(it - 1)) {
                vector<int> subArray(st, it);
                sortedSubArrays.push_back(subArray);

                st = it;
                type = DECREASING;
            } else if (type == DECREASING && *it > *(it - 1)) {
                vector<int>::const_reverse_iterator rst(it), red(st);
                vector<int> subArray(rst, red);
                sortedSubArrays.push_back(subArray);

                st = it;
                type = INCREASING;
            }
        }
        if (type == INCREASING) {
            vector<int> subArray(st, array.end());
            sortedSubArrays.push_back(subArray);
        } else {
            vector<int>::const_reverse_iterator rst(array.end()), red(st);
            vector<int> subArray(rst, red);
            sortedSubArrays.push_back(subArray);
        }

        return mergeSortedArrays(sortedSubArrays);
    }

    bool SortKIncreasingDecreasingArray::test() {
        vector<int> input = {57, 131, 493, 294, 221, 339, 418, 452, 442, 190};
        vector<int> ans = {57, 131, 190, 221, 294, 339, 418, 442, 452, 493};

        vector<int> res = sortKIncreasingDecreasingArray(input);
        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter11
} // epi
