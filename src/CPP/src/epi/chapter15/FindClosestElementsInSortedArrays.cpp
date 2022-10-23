#include "FindClosestElementsInSortedArrays.hpp"

#include <memory>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <climits>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::multimap;
using std::min;
using std::next;
using myutils::BSTNode;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    int FindClosestElementsInSortedArrays::findClosestElementsInSortedArrays(const vector<vector<int>> &sortedArrays) {
        struct IterAndTail {
            vector<int>::const_iterator iter, tail;
        };

        multimap<int, IterAndTail> valAndIters;
        // const vector &vec cannot be vector vec, otherwise vec
        // release outside the loop, and iter points to null
        for (const vector<int> &vec : sortedArrays) {
            valAndIters.emplace(vec.front(), IterAndTail{vec.cbegin(), vec.cend()});
        }

        int res = INT_MAX;

        while (true) {
            int minVal = valAndIters.begin()->first;
            int maxVal = valAndIters.rbegin()->first;
            res = min(res, maxVal - minVal);

            IterAndTail minIterPair = valAndIters.begin()->second;
            vector<int>::const_iterator nextIter = next(minIterPair.iter);

            if (nextIter == minIterPair.tail)
                return res;

            valAndIters.emplace(*nextIter, IterAndTail{nextIter, minIterPair.tail});
            valAndIters.erase(valAndIters.begin());
        }

        return res;
    }

    bool FindClosestElementsInSortedArrays::test() {
        vector<int> vec1 = {5, 10, 15};
        vector<int> vec2 = {3, 6, 9, 12, 15};
        vector<int> vec3 = {8, 16, 24};

        vector<vector<int>> vecs = {vec1, vec2, vec3};

        int ans = 1;
        int res = findClosestElementsInSortedArrays(vecs);

        if (ans != res) {
            cout << "Should be " << ans << endl;
            cout << "Result " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
