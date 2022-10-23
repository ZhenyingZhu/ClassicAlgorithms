#include "FindFirstGreaterThanK.hpp"

#include <vector>
#include <memory>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using myutils::BSTNode;
using myutils::createPreOrderIntBST;
using myutils::BST_INT_NULL;
using std::vector;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    BSTNode<int>* FindFirstGreaterThanK::findFirstGreaterThanK(const unique_ptr<BSTNode<int>> &tree, int k) {
        BSTNode<int> *res = nullptr;

        BSTNode<int> *cur = tree.get();
        while (cur) {
            if (cur->data <= k) {
                cur = cur->right.get();
            } else {
                if (!res || res->data > cur->data) // If there are nodes have same data, need check left/right subtree
                    res = cur; // Actually no need to check if res>cur. Since res always > cur if not equal.

                cur = cur->left.get();
            }
        }

        return res;
    }

    bool FindFirstGreaterThanK::test() {
        vector<int> preOrder = {19, 7, 3, 2, BST_INT_NULL, BST_INT_NULL, 5, BST_INT_NULL, BST_INT_NULL, 11, BST_INT_NULL,
                17, 13, BST_INT_NULL, BST_INT_NULL, BST_INT_NULL,
                43, 23, BST_INT_NULL, 37, 29, BST_INT_NULL, 31, BST_INT_NULL, BST_INT_NULL,
                41, BST_INT_NULL, BST_INT_NULL, 47, BST_INT_NULL, 53, BST_INT_NULL, BST_INT_NULL};

        size_t pos(0);
        unique_ptr<BSTNode<int>> tree = createPreOrderIntBST(preOrder, &pos);

        BSTNode<int> *res = findFirstGreaterThanK(tree, 23);

        if (res->data != 29) {
            cout << "Should be " << 29 << endl;
            cout << "Result " << res->data << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
