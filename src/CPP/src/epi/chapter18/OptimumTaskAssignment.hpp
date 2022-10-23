#ifndef SRC_EPI_CHAPTER18_OPTIMUMTASKASSIGNMENT_HPP_
#define SRC_EPI_CHAPTER18_OPTIMUMTASKASSIGNMENT_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter18 {
    class OptimumTaskAssignment : public myutils::Solution {
    public:
        struct PairedTasks;

        OptimumTaskAssignment():
            Solution("EPI Chapter 18.1",
                     "Compute an optimum assignment of tasks",
                     "Pair the longest task with the shortest task.") { }

        ~OptimumTaskAssignment() { }

        std::vector<PairedTasks> optimumTaskAssignment(std::vector<int> taskDurations);

        bool test();

    };

  } // chapter18
} // epi

#endif /* SRC_EPI_CHAPTER18_OPTIMUMTASKASSIGNMENT_HPP_ */
