#include "InorderTraversal.hpp"

#include <memory>
#include <vector>
#include <stack>
#include <stdexcept>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using std::stack;
using myutils::BinaryTreeNode;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using myutils::BTNULL;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    vector<int> InorderTraversal::inorderTraversal(const unique_ptr<BinaryTreeNode<int>> &tree) {
        vector<int> inOrder;
        if (!tree)
            return inOrder;

        BinaryTreeNode<int> *iter = tree.get(), *prev = nullptr;
        while (iter != nullptr) {
            BinaryTreeNode<int> *next;
            if (iter->parent == prev) {
                if (iter->left) {
                    next = iter->left.get();
                } else {
                    inOrder.push_back(iter->data);
                    next = iter->right ? iter->right.get() : iter->parent;
                }
            } else if (iter->left.get() == prev) {
                inOrder.push_back(iter->data);
                next = iter->right ? iter->right.get() : iter->parent;
            } else {
                next = iter->parent;
            }

            prev = iter;
            iter = next;
        }

        return inOrder;
    }

    bool InorderTraversal::test() {
        vector<int> preOrder1 = {5, 3, 1, BTNULL, 2, BTNULL, BTNULL, 4, BTNULL, BTNULL, 6, BTNULL, 7};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        vector<int> res = inorderTraversal(root1);
        vector<int> ans = {1, 2, 3, 4, 5, 6, 7};

        if (res != ans) {
            cout << "should be " << vec_to_string(ans) << endl;
            cout << "result " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
