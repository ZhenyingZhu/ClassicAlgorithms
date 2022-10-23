#ifndef SRC_EPI_CHAPTER19_ISDEADLOCKED_HPP_
#define SRC_EPI_CHAPTER19_ISDEADLOCKED_HPP_

#include "../../Solution.h"

#include <vector>
#include <memory>

namespace epi {
  namespace chapter19 {
    class IsDeadlocked : public myutils::Solution {
    public:
        struct GraphVertex;

        IsDeadlocked():
            Solution("EPI Chapter 19.4",
                     "Deadlock detection",
                     "Nodes represent processes and edges represent "
                     "dependencies. Use DFS to detect cycles.") { }

        ~IsDeadlocked() { }

        bool isDeadlocked(std::vector<std::shared_ptr<GraphVertex>> &graph);

        bool test();

    private:
        bool dfsHasCycle(std::shared_ptr<GraphVertex> cur);
    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_ISDEADLOCKED_HPP_ */
