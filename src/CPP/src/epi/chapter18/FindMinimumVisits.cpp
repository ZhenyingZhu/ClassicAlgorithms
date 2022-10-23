#include "FindMinimumVisits.hpp"

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
    struct FindMinimumVisits::Interval {
        int left, right;
    };

    vector<int> FindMinimumVisits::findMinimumVisits(vector<Interval> intervals) {
        vector<int> res;

        if (intervals.empty())
            return res;

        sort(intervals.begin(), intervals.end(),
             [](const Interval &interval1, const Interval &interval2) -> bool {
                 return interval1.right < interval2.right;
             });

        int firstLastTime = intervals.front().right;
        res.push_back(firstLastTime);
        for (Interval in : intervals) {
            if (in.left > firstLastTime) {
                firstLastTime = in.right;
                res.push_back(firstLastTime);
            }
        }

        return res;
    }

    bool FindMinimumVisits::test() {
        vector<Interval> intervals = {
                {0,3},{2,6},{3,4},{6,9}
        };

        vector<int> res = findMinimumVisits(intervals);
        vector<int> ans = {3, 9};

        if (res != ans) {
            cout << "Should be: " << vec_to_string(ans) << endl;
            cout << "Result: " << vec_to_string(res) << endl;

            return false;
        }

        return true;
    }

  } // chapter18
} // epi
