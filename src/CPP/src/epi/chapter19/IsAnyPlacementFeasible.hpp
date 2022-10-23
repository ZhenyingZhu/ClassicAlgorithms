#ifndef SRC_EPI_CHAPTER19_ISANYPLACEMENTFEASIBLE_HPP_
#define SRC_EPI_CHAPTER19_ISANYPLACEMENTFEASIBLE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter19 {
    class IsAnyPlacementFeasible : public myutils::Solution {
    public:
        struct GraphVertex;

        IsAnyPlacementFeasible():
            Solution("EPI Chapter 19.6",
                     "Making wired connections",
                     "For a undirected graph, mark all path to be 0, 1, "
                     "repeately show up. Use BFS. When there is an edge "
                     "on the same level return false.") { }

        ~IsAnyPlacementFeasible() { }

        bool isAnyPlacementFeasible(std::vector<GraphVertex> &graph);

        bool test();

    private:
        bool bfsMark(GraphVertex *root);

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_ISANYPLACEMENTFEASIBLE_HPP_ */
