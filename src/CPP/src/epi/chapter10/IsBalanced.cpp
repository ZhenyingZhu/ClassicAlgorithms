#include "IsBalanced.hpp"

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
    int IsBalanced::computeHeight(const unique_ptr<BinaryTreeNode<int>> &root) {
        if (!root)
            return 0;

        int leftHeight = computeHeight(root.get()->left);
        int rightHeight = computeHeight(root.get()->right);

        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;

        return 1 + max(leftHeight, rightHeight);
    }

    bool IsBalanced::isBalanced(const unique_ptr<BinaryTreeNode<int>> &tree) {
        int height = computeHeight(tree);

        if (height == -1)
            return false;

        return true;
    }

    bool IsBalanced::test() {
        vector<int> preOrder1 = {0, 1, 2, BTNULL, BTNULL, 3, BTNULL, BTNULL, 4};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        if (!isBalanced(root1)) {
            cout << "root1 should be balanced" << endl;
            return false;
        }

        vector<int> preOrder2 = {0, 1, 2, 3, BTNULL, BTNULL, BTNULL, BTNULL, 4};
        pos = 0;
        unique_ptr<BinaryTreeNode<int>> root2 = createPreOrderIntBTree(preOrder2, &pos);

        if (isBalanced(root2)) {
            cout << "root2 should not be balanced" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
