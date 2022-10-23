#include "IsDeadlocked.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::shared_ptr;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct IsDeadlocked::GraphVertex {
        GraphVertex(int id): id(id) { }

        int id;
        std::vector<shared_ptr<GraphVertex>> neighbors;
        enum Status {notvisit, visiting, visited} status = notvisit;
    };

    bool IsDeadlocked::dfsHasCycle(shared_ptr<GraphVertex> cur) {
        if (cur->status == GraphVertex::visited)
            return false; // another branch doesn't mean there is a cycle

        if (cur->status == GraphVertex::visiting)
            return true;

        cur->status = GraphVertex::visiting;
        for (shared_ptr<GraphVertex> &neighbor : cur->neighbors) {
            if (dfsHasCycle(neighbor))
                return true;
        }

        cur->status = GraphVertex::visited;
        return false;
    }

    bool IsDeadlocked::isDeadlocked(vector<shared_ptr<GraphVertex>> &graph) {
        for (shared_ptr<GraphVertex> &vertex : graph) {
            if (dfsHasCycle(vertex))
                return true;
        }

        return false;
    }

    bool IsDeadlocked::test() {
        vector<shared_ptr<GraphVertex>> graph = {shared_ptr<GraphVertex>(new GraphVertex(1)),
                                                 shared_ptr<GraphVertex>(new GraphVertex(2)),
                                                 shared_ptr<GraphVertex>(new GraphVertex(3))};
        graph[0]->neighbors.push_back(graph[1]);
        graph[1]->neighbors.push_back(graph[2]);
        graph[2]->neighbors.push_back(graph[0]);

        if (!isDeadlocked(graph)) {
            cout << "Should have dead lock" << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
