#include "FindLCA.hpp"

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using myutils::BSTNode;
using myutils::BST_INT_NULL;
using myutils::createBSTFromPreorder;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    BSTNode<int>* FindLCA::findLCA(const unique_ptr<BSTNode<int>> &tree,
                                   const unique_ptr<BSTNode<int>> &a,
                                   const unique_ptr<BSTNode<int>> &b) {
        int low = a.get()->data, high = b.get()->data;
        assert(low != high);
        if (low > high) {
            int tmp = low;
            low = high;
            high = tmp;
        }

        BSTNode<int> *node = tree.get();
        while (node) {
            if (node->data == low || node->data == high
                    || (node->data > low && node->data < high) )
                return node;

            if (node->data < low) {
                node = node->right.get();
            } else {
                node = node->left.get();
            }
        }

        return nullptr;
    }

    bool FindLCA::test() {
        vector<int> preOrder = {19, 7, 3, 2, 5, 11, 17, 13, 43, 23, 37, 29, 31, 41, 47, 53};

        unique_ptr<BSTNode<int>> tree = createBSTFromPreorder(preOrder);
        unique_ptr<BSTNode<int>> &c = tree.get()->left.get()->left;
        unique_ptr<BSTNode<int>> &g = tree.get()->left.get()->right.get()->right;

        int ans = 7;

        BSTNode<int> *res = findLCA(tree, c, g);

        if (res->data != ans) {
            cout << "Should be " << ans << endl;
            cout << "Result " << res->data << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
