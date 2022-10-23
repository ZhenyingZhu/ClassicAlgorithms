#ifndef SRC_EPI_CHAPTER19_FINDLARGESTNUMBERTEAMS_HPP_
#define SRC_EPI_CHAPTER19_FINDLARGESTNUMBERTEAMS_HPP_

#include "../../Solution.h"

#include <vector>
#include <stack>

namespace epi {
  namespace chapter19 {
    class FindLargestNumberTeams : public myutils::Solution {
    public:
        struct GraphVertex;

        FindLargestNumberTeams():
            Solution("EPI Chapter 19.8",
                     "Find the longest path length in a DAG graph",
                     "Use a stack to record visited vertexes in DFS can order the vertexes "
                     "in topological order, and the top is the source, which records the "
                     "longest distance to a sink.") { }

        ~FindLargestNumberTeams() { }

        size_t findLargestNumberTeams(std::vector<GraphVertex> &dagGraph);

        bool test();

    private:
        void dfsFindTopologicalOrder(GraphVertex *vertex, std::stack<GraphVertex*> &topologicalOrder);

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_FINDLARGESTNUMBERTEAMS_HPP_ */
