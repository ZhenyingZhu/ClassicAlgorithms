#include "CanReachEnd.hpp"

#include <iostream>
#include <vector>
#include <algorithm>

#include "../../MyUtils.h"

using std::vector;
using std::max;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
namespace chapter6 {

    bool CanReachEnd::canReachEnd(const vector<int> &max_advance_steps) {
        int furthest_reach_so_far = 0, last_index = max_advance_steps.size() - 1;
        for (int i = 0; i <= furthest_reach_so_far && furthest_reach_so_far < last_index; ++i) {
            furthest_reach_so_far = max(furthest_reach_so_far, max_advance_steps[i] + i);
        }

        return furthest_reach_so_far >= last_index;
    }

    bool CanReachEnd::test() {
        int temp_arr1[] = { 3, 3, 1, 0, 2, 0, 1 };
        vector<int> a ( temp_arr1, temp_arr1 + sizeof(temp_arr1) / sizeof(temp_arr1[0]) );

        int temp_arr2[] = { 3, 2, 0, 0, 2, 0, 1 };
        vector<int> b ( temp_arr2, temp_arr2 + sizeof(temp_arr2) / sizeof(temp_arr2[0]) );

        cout << "In " << vec_to_string(a) << ", can ";
        if (!canReachEnd(a))
            cout << "not ";
        cout << "reach the end. " << endl;

        cout << "In " << vec_to_string(b) << ", can ";
        if (!canReachEnd(b))
            cout << "not ";
        cout << "reach the end. " << endl;

        return true;
    }

} // chapter6
} // epi
