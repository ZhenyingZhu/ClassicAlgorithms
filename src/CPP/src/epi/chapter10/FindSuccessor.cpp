#include "FindSuccessor.hpp"

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
using myutils::BTNULL;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    BinaryTreeNode<int>* FindSuccessor::findSuccessor(const unique_ptr<BinaryTreeNode<int>> &node) {
        if (!node)
            return nullptr;

        if (!node.get()->right) {
            // node could be right child of its parent
            BinaryTreeNode<int> *res = node.get();
            while (res->parent && res->parent->right.get() == res) {
                res = res->parent;
            }

            return res->parent;
        }

        BinaryTreeNode<int> *res = node.get()->right.get();
        while (res->left)
            res = res->left.get();

        return res;
    }

    bool FindSuccessor::test() {
        vector<int> preOrder1 = {5, 3, 1, BTNULL, 2, BTNULL, BTNULL, 4, BTNULL, BTNULL,
                6, BTNULL, 7};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        unique_ptr<BinaryTreeNode<int>> &node1 = root1.get()->left.get()->left;
        auto res1 = findSuccessor(node1);
        if (res1->data != 2) {
            cout << "should be " << 2 << endl;
            cout << "result " << res1->data << endl;
            return false;
        }

        unique_ptr<BinaryTreeNode<int>> &node2 = node1.get()->right;
        auto res2 = findSuccessor(node2);
        if (res2->data != 3) {
            cout << "should be " << 3 << endl;
            cout << "result " << res2->data << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
