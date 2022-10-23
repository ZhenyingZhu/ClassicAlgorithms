#include "AddInterval.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "../../MyUtils.h"

using std::vector;
using std::string;
using std::sort;
using std::max;
using std::min;
using std::cout;
using std::endl;
using myutils::vec_to_string;

namespace epi {
  namespace chapter14 {
    struct AddInterval::Interval {
        int left, right;
    };

    void AddInterval::addInterval(vector<Interval> &disjointIntervals, Interval newInterval) {
        if (disjointIntervals.empty())
            return;

        vector<Interval>::iterator st = disjointIntervals.begin();
        while (st != disjointIntervals.end() && st->right < newInterval.left)
            ++st;

        if (st == disjointIntervals.end()) {
            disjointIntervals.push_back(newInterval);
            return;
        }

        // st should be the first intersect interval
        vector<Interval>::iterator ed = st;
        while (ed != disjointIntervals.end() && ed->left <= newInterval.right) {
            newInterval.left = min(newInterval.left, ed->left);
            newInterval.right = max(newInterval.right, ed->right);
            ++ed;
        }

        vector<Interval>::const_iterator remain = st - 1;
        disjointIntervals.erase(st, ed);

        disjointIntervals.insert(remain + 1, newInterval);
    }

    bool AddInterval::test() {
        vector<Interval> intervals = {
                {-4, -1},
                {0, 2},
                {3, 6},
                {7, 9},
                {11, 12},
                {14, 17}
        };

        addInterval(intervals, {1, 8});


        if (intervals.size() != 4) {
            cout << "Should be size 4" << endl;
            cout << "Result " << endl;

            for (Interval interval : intervals) {
                cout << interval.left << " " << interval.right << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter14
} // epi
