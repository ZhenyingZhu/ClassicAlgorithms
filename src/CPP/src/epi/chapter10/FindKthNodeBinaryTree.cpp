#include "FindKthNodeBinaryTree.hpp"

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
    size_t FindKthNodeBinaryTree::updateNodesWithSubtreeSize(const unique_ptr<BinaryTreeNode<int>> &tree) {
        if (!tree)
            return 0;

        size_t size = 1;
        if (tree.get()->left)
            size += updateNodesWithSubtreeSize(tree.get()->left);
        if (tree.get()->right)
            size += updateNodesWithSubtreeSize(tree.get()->right);

        tree.get()->size = size;
        return size;
    }

    const BinaryTreeNode<int>* FindKthNodeBinaryTree::findKthNodeBinaryTree(const unique_ptr<BinaryTreeNode<int>>& tree, int k) {
        updateNodesWithSubtreeSize(tree);
        --k;

        BinaryTreeNode<int> *res = tree.get();
        int cnt = res->size;

        while (k >= 0) {
            int left = 0;
            if (res->left)
                left += res->left.get()->size;

            if (k == left)
                return res;

            if (k < left) {
                res = res->left.get();
            } else {
                k -= left + 1;

                if (!res->right)
                    throw invalid_argument("k is larger than the tree size");
                res = res->right.get();
            }

            --cnt;
            if (cnt < -1)
                throw invalid_argument("Endless loop");
        }

        return res;
    }

    bool FindKthNodeBinaryTree::test() {
        vector<int> preOrder1 = {5, 3, 1, BTNULL, 2, BTNULL, BTNULL, 4, BTNULL, BTNULL,
                6, BTNULL, 7};
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        for (int i = 1; i != 8; ++i) {
            auto res = findKthNodeBinaryTree(root1, i);
            if (i != res->data) {
                cout << "should be " << i << endl;
                cout << "result " << res->data << endl;
                return false;
            }
        }

        return true;
    }

  } // chapter10
} // epi
