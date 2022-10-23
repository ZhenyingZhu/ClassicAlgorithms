#include "ComputeDiameter.hpp"

#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../MyUtils.h"

using std::vector;
using std::array;
using std::unique_ptr;
using std::move;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    struct ComputeDiameter::TreeNode {
        struct Edge {
            unique_ptr<TreeNode> child;
            double weight;
        };

        vector<Edge> edges;
    };

    double ComputeDiameter::diameterHelper(const unique_ptr<TreeNode> &node, double &maxDiameter) {
        assert(node != nullptr);

        array<double, 2> maxDistances = {{0.0, 0.0}};

        for (const TreeNode::Edge &e : node->edges) {
            double dis = diameterHelper(e.child, maxDiameter) + e.weight;

            if (dis > maxDistances[0])
                maxDistances[0] = dis;
            else if (dis > maxDistances[1])
                maxDistances[1] = dis;
        }

        if (maxDistances[0] + maxDistances[1] > maxDiameter)
            maxDiameter = maxDistances[0] + maxDistances[1];

        return maxDistances[0];
    }

    double ComputeDiameter::computeDiameter(const unique_ptr<TreeNode> &tree) {
        if (tree == nullptr)
            return 0.0;

        double maxDiameter = 0.0;
        diameterHelper(tree, maxDiameter);

        return maxDiameter;
    }

    bool ComputeDiameter::test() {
        unique_ptr<TreeNode> ap(new TreeNode), bp(new TreeNode), cp(new TreeNode), dp(new TreeNode), ep(new TreeNode);
        vector<unique_ptr<TreeNode>> ptrs;
        for (size_t i = 0; i != 11; ++i)
            ptrs.push_back(unique_ptr<TreeNode>(new TreeNode));

        TreeNode *b = bp.get(), *c = cp.get(), *d = dp.get();
        vector<TreeNode*> ps;
        for (const auto &ptr : ptrs)
            ps.push_back(ptr.get());

        b->edges.push_back({move(cp), 7});
        b->edges.push_back({move(ap), 14});
        b->edges.push_back({move(ptrs[0]), 3});

        c->edges.push_back({move(dp), 4});
        c->edges.push_back({move(ptrs[1]), 3});

        ps[0]->edges.push_back({move(ptrs[2]), 2});
        ps[0]->edges.push_back({move(ptrs[3]), 1});

        d->edges.push_back({move(ep), 6});

        ps[3]->edges.push_back({move(ptrs[4]), 6});
        ps[3]->edges.push_back({move(ptrs[5]), 4});

        ps[5]->edges.push_back({move(ptrs[6]), 4});
        ps[5]->edges.push_back({move(ptrs[7]), 2});

        ps[7]->edges.push_back({move(ptrs[8]), 1});
        ps[7]->edges.push_back({move(ptrs[9]), 2});
        ps[7]->edges.push_back({move(ptrs[10]), 3});

//        cout << bp->edges[0].weight << endl;
//        cout << bp->edges[0].child->edges[0].weight << endl;

        double res = computeDiameter(bp);

        if (res != 31) {
            cout << res << endl;

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
