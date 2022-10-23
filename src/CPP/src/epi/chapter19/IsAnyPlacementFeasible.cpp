#include "IsAnyPlacementFeasible.hpp"

#include <vector>
#include <queue>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::queue;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct IsAnyPlacementFeasible::GraphVertex {
        int mark = -1;
        std::vector<GraphVertex*> neighbors;
    };

    bool IsAnyPlacementFeasible::bfsMark(GraphVertex *root) {
        root->mark = 0;

        queue<GraphVertex*> visit;
        visit.push(root);

        while (!visit.empty()) {
            GraphVertex *cur = visit.front();
            for (GraphVertex *neighbor : cur->neighbors) {
                if (neighbor->mark == cur->mark)
                    return false;

                if (neighbor->mark == -1) {
                    neighbor->mark = (cur->mark + 1) % 2;
                    visit.push(neighbor);
                }
            }
            visit.pop();
        }

        return true;
    }

    bool IsAnyPlacementFeasible::isAnyPlacementFeasible(vector<GraphVertex> &graph) {
        for (GraphVertex &vertex : graph) {
            if (vertex.mark == -1) {
                if (!bfsMark(&vertex))
                    return false;
            }
        }

        return true;
    }

    bool IsAnyPlacementFeasible::test() {
        vector<GraphVertex> graph(4);
        graph[0].neighbors.push_back(&graph[1]);
        graph[0].neighbors.push_back(&graph[2]);
        graph[1].neighbors.push_back(&graph[0]);
        graph[1].neighbors.push_back(&graph[3]);
        graph[2].neighbors.push_back(&graph[0]);
        graph[2].neighbors.push_back(&graph[3]);
        graph[3].neighbors.push_back(&graph[1]);
        graph[3].neighbors.push_back(&graph[2]);

        if (!isAnyPlacementFeasible(graph)) {
            cout << "Should be feasible" << endl;

            return false;
        }

        for (GraphVertex &vertex : graph) {
            vertex.mark = -1;
        }

        graph[1].neighbors.push_back(&graph[2]);
        graph[2].neighbors.push_back(&graph[1]);

        if (isAnyPlacementFeasible(graph)) {
            cout << "Should not be feasible" << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
