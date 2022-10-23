#include "HasPathSum.hpp"

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
    bool HasPathSum::hasPathSumHelper(const unique_ptr<BinaryTreeNode<int>> &node, int partialPathSum, int targetSum) {
        if (!node)
            return 0;

        partialPathSum += node.get()->data;

        if (!node.get()->left && !node.get()->right)
            return partialPathSum == targetSum; // Leaf

        bool left = hasPathSumHelper(node.get()->left, partialPathSum, targetSum);
        bool right = hasPathSumHelper(node.get()->right, partialPathSum, targetSum);

        return left || right;
    }

    bool HasPathSum::hasPathSum(const unique_ptr<BinaryTreeNode<int>> &tree, int targetSum) {
        return hasPathSumHelper(tree, 0, targetSum);
    }

    bool HasPathSum::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, BTNULL, BTNULL, 0, BTNULL, BTNULL,
                561, BTNULL, 3, 17, BTNULL, BTNULL, BTNULL,
                6, 2, BTNULL, 1, 401, BTNULL, 641, BTNULL, BTNULL, 257, BTNULL, BTNULL,
                271, BTNULL, 28
        };
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        bool res = hasPathSum(root1, 591);

        if (!res) {
            cout << "should exist" << endl;
            cout << "but not exist" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
