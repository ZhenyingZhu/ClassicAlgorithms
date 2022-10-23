#include "LCAWithParent.hpp"

#include <memory>
#include <stdlib.h>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include <vector>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using myutils::BinaryTreeNode;
using myutils::BTNULL;
using std::abs;
using std::max;
using std::swap;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    int LCAWithParent::getDepth(const unique_ptr<BinaryTreeNode<int>> &node) {
        int dep = 0;
        BinaryTreeNode<int> *p = node.get();
        while (p) {
            ++dep;
            p = p->parent;
        }

        return dep;
    }

    BinaryTreeNode<int>* LCAWithParent::lowestCommonAncestor(const unique_ptr<BinaryTreeNode<int>> &node1,
                                                             const unique_ptr<BinaryTreeNode<int>> &node2) {
        if (!node1 || !node2)
            return nullptr;

        int d1 = getDepth(node1), d2 = getDepth(node2);
        auto p1 = node1.get(), p2 = node2.get();

        int diff = abs(d1 - d2);
        if (d1 < d2)
            swap(p1, p2);

        while (diff-- > 0)
            p1 = p1->parent;

        while (p1 && p2 && p1 != p2) {
            p1 = p1->parent;
            p2 = p2->parent;
        }

        return p1;
    }

    bool LCAWithParent::test() {
        vector<int> preOrder1 = {314, 6, BTNULL, 2, BTNULL, 3, BTNULL, BTNULL, 6, 2, 3};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);
        unique_ptr<BinaryTreeNode<int>> &node11 = root1.get()->left;
        unique_ptr<BinaryTreeNode<int>> &node12 = root1.get()->right;

        if (lowestCommonAncestor(node11, node12)->data != 314) {
            cout << "root1 should be common ancestor" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
