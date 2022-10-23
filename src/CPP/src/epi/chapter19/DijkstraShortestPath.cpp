#include "DijkstraShortestPath.hpp"

#include <vector>
#include <limits>
#include <set>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::set;
using std::ostream;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter19 {
    struct DijkstraShortestPath::GraphVertex {
        struct Edge {
            GraphVertex &vertex;
            size_t weight;
        };

        struct DisToS {
            size_t distance;
            size_t edgeNum;
        };

        GraphVertex(int id): id(id) { }

        int id;
        DisToS disToS = DisToS{std::numeric_limits<int>::max(), 0};
        std::vector<Edge> edges;
        // Need to check the solution, which use const here
        GraphVertex *pred = nullptr;
    };

    struct Comp {
        bool operator()(const DijkstraShortestPath::GraphVertex *lhs, const DijkstraShortestPath::GraphVertex *rhs) {
            if (lhs->disToS.distance < rhs->disToS.distance)
                return true;

            if (lhs->disToS.distance > rhs->disToS.distance)
                return false;

            if (lhs->disToS.edgeNum < rhs->disToS.edgeNum)
                return true;

            return false;
        }
    };

    vector<DijkstraShortestPath::GraphVertex*> DijkstraShortestPath::dijkstraShortestPath(GraphVertex *s, GraphVertex *t) {
        s->disToS = {0, 0};

        set<GraphVertex*, Comp> vertexSet;
        vertexSet.insert(s);

        while (!vertexSet.empty()) {
            GraphVertex *u = *vertexSet.cbegin();
            if (u->id == t->id)
                break;

            vertexSet.erase(vertexSet.cbegin());

            for (const GraphVertex::Edge &edge : u->edges) {
                GraphVertex *v = &edge.vertex;
                size_t vDistance = u->disToS.distance + edge.weight;
                size_t vEdgeNum = u->disToS.edgeNum + 1;

                if (v->disToS.distance > vDistance ||
                        (v->disToS.distance == vDistance && v->disToS.edgeNum > vEdgeNum) ) {
                    vertexSet.erase(v);
                    v->pred = u;
                    v->disToS = {vDistance, vEdgeNum};
                    vertexSet.insert(v);
                }
            }
        }

        vector<GraphVertex*> path;
        GraphVertex *node = t;
        while (node) {
            path.push_back(node);
            node = node->pred;
        }

        return path;
    }

    bool DijkstraShortestPath::test() {
        GraphVertex v1(1), v2(2), v3(3);
        v1.edges.push_back({v2, 1});
        v2.edges.push_back({v3, 1});

        vector<GraphVertex*> res = dijkstraShortestPath(&v1, &v3);

        if (res.size() != 3) {
            cout << "Should be: 3" << endl;
            for (GraphVertex *v : res) {
                cout << v->id << "<-";
            }
            cout << endl;

            return false;
        }

        return true;
    }

  } // chapter19
} // epi
