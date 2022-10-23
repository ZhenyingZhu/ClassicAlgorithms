#include "HasThreeSum.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::sort;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    bool HasThreeSum::hasThreeSum(vector<int> array, int sum) {
        if (array.empty())
            return false;

        sort(array.begin(), array.end());

        for (int cur : array) {
            int tar = sum - cur;
            int st = 0, ed = array.size() - 1;
            while (st <= ed) {
                if (array[st] + array[ed] == tar)
                    return true;
                else if (array[st] + array[ed] < tar)
                    ++st;
                else
                    --ed;
            }
        }

        return false;
    }

    bool HasThreeSum::test() {
        vector<int> array = {11,2,5,7,3};

        bool res1 = hasThreeSum(array, 21);
        if (!res1) {
            cout << "Should be able to find result" << endl;

            return false;
        }

        bool res2 = hasThreeSum(array, 22);
        if (res2) {
            cout << "Should not be able to find result" << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
