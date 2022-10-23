#include "LCA.hpp"

#include <memory>
#include <stdlib.h>
#include <algorithm>
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
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    LCA::Status LCA::lcaHelper(const unique_ptr<BinaryTreeNode<int>> &root,
                               const unique_ptr<BinaryTreeNode<int>> &node1,
                               const unique_ptr<BinaryTreeNode<int>> &node2) {
        if (node1 == node2)
            return {node1.get(), 2};

        if (!root)
            return {nullptr, 0};

        size_t nodesNum = 0;
        if (root == node1)
            ++nodesNum;

        if (root == node2)
            ++nodesNum;

        Status left = lcaHelper(root.get()->left, node1, node2);
        if (left.nodesNum == 2)
            return left;

        Status right = lcaHelper(root.get()->right, node1, node2);
        if (right.nodesNum == 2)
            return right;

        nodesNum += left.nodesNum + right.nodesNum;
        if (nodesNum == 2)
            return {root.get(), nodesNum};
        return {nullptr, nodesNum};
    }

    BinaryTreeNode<int>* LCA::lowestCommonAncestor(const unique_ptr<BinaryTreeNode<int>> &tree,
                                                   const unique_ptr<BinaryTreeNode<int>> &node1,
                                                   const unique_ptr<BinaryTreeNode<int>> &node2) {
        return lcaHelper(tree, node1, node2).ancestor;
    }

    bool LCA::test() {
        vector<int> preOrder1 = {314, 6, BTNULL, 2, BTNULL, 3, BTNULL, BTNULL, 6, 2, 3};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);
        unique_ptr<BinaryTreeNode<int>> &node11 = root1.get()->left;
        unique_ptr<BinaryTreeNode<int>> &node12 = root1.get()->right;

        if (lowestCommonAncestor(root1, node11, node12)->data != 314) {
            cout << "root1 should be common ancestor" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
