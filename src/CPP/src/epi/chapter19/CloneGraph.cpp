#include "CloneGraph.hpp"

#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::unordered_map;
using std::queue;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct CloneGraph::GraphVertex {
        int id;
        std::vector<GraphVertex*> neighbors;
    };

    CloneGraph::GraphVertex* CloneGraph::cloneGraph(GraphVertex* root) {
        if (!root)
            return nullptr;

        unordered_map<GraphVertex*, GraphVertex*> mapping;

        queue<GraphVertex*> queue;
        mapping.emplace(root, new GraphVertex{root->id});
        queue.push(root);

        while (!queue.empty()) {
            GraphVertex *cur = queue.front();
            assert(mapping.find(cur) != mapping.end());

            GraphVertex *cpy = mapping[cur];
            for (GraphVertex *neighbor : cur->neighbors) {
                // Even a vertex is already visited, it is still need to be added
                if (mapping.find(neighbor) == mapping.end()) {
                    // not visit
                    mapping.emplace(neighbor, new GraphVertex{neighbor->id});
                    queue.push(neighbor);
                }

                // visiting
                cpy->neighbors.push_back(mapping[neighbor]);
            }

            // visited
            queue.pop();
        }

        return mapping[root];
    }

    bool CloneGraph::test() {
        vector<GraphVertex*> graph = {new GraphVertex{1}, new GraphVertex{2}, new GraphVertex{3}};
        graph[0]->neighbors.push_back(graph[1]);
        graph[1]->neighbors.push_back(graph[2]);
        graph[2]->neighbors.push_back(graph[0]);

        GraphVertex *clone = cloneGraph(graph[0]);

        if (clone->id != 1) {
            cout << "Should be: 1" << endl;
            cout << "Result: " << clone->id << endl;

            return false;
        }

        if (clone->neighbors[0]->id != 2) {
            cout << "Should be: 2" << endl;
            cout << "Result: " << clone->neighbors[0]->id << endl;

            return false;
        }

        if (clone->neighbors[0]->neighbors[0]->id != 3) {
            cout << "Should be: 3" << endl;
            cout << "Result: " << clone->neighbors[0]->neighbors[0]->id << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
