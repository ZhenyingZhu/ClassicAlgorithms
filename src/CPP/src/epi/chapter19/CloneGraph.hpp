#ifndef SRC_EPI_CHAPTER19_CLONEGRAPH_HPP_
#define SRC_EPI_CHAPTER19_CLONEGRAPH_HPP_

#include "../../Solution.h"

#include <vector>
#include <memory>

namespace epi {
  namespace chapter19 {
    class CloneGraph : public myutils::Solution {
    public:
        struct GraphVertex;

        CloneGraph():
            Solution("EPI Chapter 19.5",
                     "Clone a graph",
                     "Directed graph. Use a map to store correspondent "
                     "old and copied vertexes. Then use BFS to traverse.") { }

        ~CloneGraph() { }

        GraphVertex* cloneGraph(GraphVertex* root);

        bool test();

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_CLONEGRAPH_HPP_ */
