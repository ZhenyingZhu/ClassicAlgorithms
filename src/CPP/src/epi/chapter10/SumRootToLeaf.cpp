#include "SumRootToLeaf.hpp"

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
    int SumRootToLeaf::sumRootToLeafHelper(const unique_ptr<BinaryTreeNode<int>> &node, int partialPathSum) {
        if (!node)
            return 0;

        if (node.get()->data != 0 && node.get()->data != 1)
            throw invalid_argument("Nodes data should be digit of binary");

        partialPathSum = partialPathSum * 2 + node.get()->data;

        if (!node.get()->left && !node.get()->right)
            return partialPathSum; // Leaf

        int left = sumRootToLeafHelper(node.get()->left, partialPathSum);
        int right = sumRootToLeafHelper(node.get()->right, partialPathSum);

        return left + right;
    }

    int SumRootToLeaf::sumRootToLeaf(const unique_ptr<BinaryTreeNode<int>> &tree) {
        return sumRootToLeafHelper(tree, 0);
    }

    bool SumRootToLeaf::test() {
        vector<int> preOrder1 =
        {1, 0, 0, 0, BTNULL, BTNULL, 1, BTNULL, BTNULL,
                1, BTNULL, 1, 0, BTNULL, BTNULL, BTNULL,
                1, 0, BTNULL, 0, 1, BTNULL, 1, BTNULL, BTNULL,
                0, BTNULL, BTNULL, 0, BTNULL, 0, BTNULL, BTNULL};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        int res = sumRootToLeaf(root1);

        if (res != 126) {
            cout << "sum should be 126" << endl;
            cout << "but is " << res << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
