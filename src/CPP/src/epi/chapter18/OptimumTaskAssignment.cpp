#include "OptimumTaskAssignment.hpp"

#include <vector>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::sort;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter18 {
    struct OptimumTaskAssignment::PairedTasks {
        int task1, task2;
    };

    vector<OptimumTaskAssignment::PairedTasks> OptimumTaskAssignment::optimumTaskAssignment(vector<int> taskDurations) {
        assert(taskDurations.size() % 2 == 0);

        sort(taskDurations.begin(), taskDurations.end());

        vector<OptimumTaskAssignment::PairedTasks> res;
        int st = 0, ed = taskDurations.size() - 1;
        while (st < ed) {
            res.push_back({taskDurations[st++], taskDurations[ed--]});
        }
        return res;
    }

    bool OptimumTaskAssignment::test() {
        vector<int> taskDurations = {5, 2, 1, 6, 4, 4};

        vector<PairedTasks> res = optimumTaskAssignment(taskDurations);

        for (PairedTasks p : res) {
            if (p.task1 + p.task2 > 8) {
                cout << "Tasks sum should be shorter than 8" << endl;
                cout << "Task1: " << p.task1 << ", Task2: " << p.task2 << endl;

                return false;
            }
        }

        return true;
    }

  } // chapter18
} // epi
