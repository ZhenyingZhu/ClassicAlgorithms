#include "IsSymmetric.hpp"

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
    bool IsSymmetric::compare(const unique_ptr<BinaryTreeNode<int>> &node1,
                              const unique_ptr<BinaryTreeNode<int>> &node2) {
        if (!node1 || !node2) {
            return !node2 && !node2;
        }

        if (node1.get()->data != node2.get()->data)
            return false;

        return compare(node1.get()->left, node2.get()->right) &&
               compare(node1.get()->right, node2.get()->left);
    }

    bool IsSymmetric::isSymmetric(const unique_ptr<BinaryTreeNode<int>> &tree) {
        if (!tree)
            return true;

        return compare(tree.get()->left, tree.get()->right);
    }

    bool IsSymmetric::test() {
        vector<int> preOrder1 = {314, 6, BTNULL, 2, BTNULL, 3, BTNULL, BTNULL, 6, 2, 3};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        if (!isSymmetric(root1)) {
            cout << "root1 should be symmetric" << endl;
            return false;
        }

        vector<int> preOrder2 = {314, 6, BTNULL, 561, BTNULL, 3, BTNULL, BTNULL, 6, 2, 3};
        pos = 0;
        unique_ptr<BinaryTreeNode<int>> root2 = createPreOrderIntBTree(preOrder2, &pos);

        if (isSymmetric(root2)) {
            cout << "root2 should not be symmetric" << endl;
            return false;
        }

        vector<int> preOrder3 = {314, 6, BTNULL, 561, BTNULL, 3, BTNULL, BTNULL, 6, 2};
        pos = 0;
        unique_ptr<BinaryTreeNode<int>> root3 = createPreOrderIntBTree(preOrder3, &pos);

        if (isSymmetric(root3)) {
            cout << "root2 should not be symmetric" << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
