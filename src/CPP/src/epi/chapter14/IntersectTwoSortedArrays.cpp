#include "IntersectTwoSortedArrays.hpp"

#include <vector>
#include <iterator>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::vector;
using std::prev;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter14 {
    vector<int> IntersectTwoSortedArrays::intersectTwoSortedArrays(const vector<int> &array1, const vector<int> &array2) {
        vector<int> res;
        if (array1.empty() || array2.empty())
            return res;

        vector<int>::const_iterator iter1 = array1.begin(), iter2 = array2.begin();
        while (iter1 != array1.end() && iter2 != array2.end()) {
            if (iter1 != array1.begin() && *iter1 == *prev(iter1))
                ++iter1;
            if (iter2 != array2.begin() && *iter2 == *prev(iter2))
                ++iter2;

            if (*iter1 == *iter2) {
                res.push_back(*iter1);
                ++iter1, ++iter2;
            } else if (*iter1 > *iter2) {
                ++iter2;
            } else {
                ++iter1;
            }
        }

        return res;
    }

    bool IntersectTwoSortedArrays::test() {
        vector<int> array1 = {2,3,3,5,5,6,7,7,8,12};
        vector<int> array2 = {5,5,6,8,8,9,10,10};

        vector<int> res = intersectTwoSortedArrays(array1, array2);
        vector<int> ans = {5,6,8};

        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter14
} // epi
