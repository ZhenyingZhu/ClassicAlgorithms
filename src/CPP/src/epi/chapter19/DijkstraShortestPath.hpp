#ifndef SRC_EPI_CHAPTER19_DIJKSTRASHORTESTPATH_HPP_
#define SRC_EPI_CHAPTER19_DIJKSTRASHORTESTPATH_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter19 {
    class DijkstraShortestPath : public myutils::Solution {
    public:
        struct GraphVertex;

        DijkstraShortestPath():
            Solution("EPI Chapter 19.9",
                     "Compute a shortest path with fewest edges",
                     "Use Dijkstra shortest path algorithm but compare edge numbers as well.") { }

        ~DijkstraShortestPath() { }

        std::vector<GraphVertex*> dijkstraShortestPath(GraphVertex *s, GraphVertex *t);

        bool test();

    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_DIJKSTRASHORTESTPATH_HPP_ */
