#include "FindLargestNumberTeams.hpp"

#include <vector>
#include <stack>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::stack;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct FindLargestNumberTeams::GraphVertex {
        size_t longestDis = 1;
        enum Status {notvisit, visiting, visited} status = notvisit;
        std::vector<GraphVertex*> edges;
    };

    void FindLargestNumberTeams::dfsFindTopologicalOrder(GraphVertex *vertex, stack<GraphVertex*> &topologicalOrder) {
        vertex->status = GraphVertex::visiting;
        for (GraphVertex *edge : vertex->edges) {
            assert(edge->status != GraphVertex::visiting);

            if (edge->status == GraphVertex::notvisit)
                dfsFindTopologicalOrder(edge, topologicalOrder);

            if (edge->longestDis + 1 > vertex->longestDis)
                vertex->longestDis = edge->longestDis + 1;
        }

        vertex->status = GraphVertex::visited;

        topologicalOrder.push(vertex);
    }

    size_t FindLargestNumberTeams::findLargestNumberTeams(vector<GraphVertex> &dagGraph) {
        size_t longestDis = 1;

        for (GraphVertex &v : dagGraph) {
            stack<GraphVertex*> topologicalOrder;
            dfsFindTopologicalOrder(&v, topologicalOrder);
            if (topologicalOrder.top()->longestDis > longestDis) {
                longestDis = topologicalOrder.top()->longestDis;
            }
        }

        return longestDis;
    }

    bool FindLargestNumberTeams::test() {
        vector<GraphVertex> dagGraph(5);

        dagGraph[0].edges.push_back(&dagGraph[1]);
        dagGraph[0].edges.push_back(&dagGraph[3]);
        dagGraph[1].edges.push_back(&dagGraph[2]);
        dagGraph[2].edges.push_back(&dagGraph[4]);
        dagGraph[3].edges.push_back(&dagGraph[4]);

        size_t res = findLargestNumberTeams(dagGraph);

        if (res != 4) {
            cout << "Should be: 4" << endl;
            cout << "Result: " << res << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
