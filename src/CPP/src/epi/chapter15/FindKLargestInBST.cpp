#include "FindKLargestInBST.hpp"

#include <memory>
#include <vector>
#include <stack>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BSTNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using myutils::BSTNode;
using myutils::BST_INT_NULL;
using std::stack;
using myutils::createPreOrderIntBST;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    struct FindKLargestInBST::NodePushCnt {
        BSTNode<int> *node;
        size_t pushCnt;
    };

    vector<int> FindKLargestInBST::findKLargestInBST(const unique_ptr<BSTNode<int>> &tree, size_t k) {
        vector<int> res;

        stack<NodePushCnt> reverseInorderStack;
        reverseInorderStack.push({tree.get(), 1});
        while (!reverseInorderStack.empty()) {
            NodePushCnt cur = reverseInorderStack.top();
            reverseInorderStack.pop();

            if (cur.pushCnt == 2) {
                res.push_back(cur.node->data);

                if (res.size() == k)
                    return res;

                continue;
            }

            // reverse inorder traverse
            if (cur.node->left != nullptr)
                reverseInorderStack.push({cur.node->left.get(), 1});
            reverseInorderStack.push({cur.node, 2});
            if (cur.node->right != nullptr)
                reverseInorderStack.push({cur.node->right.get(), 1});
        }

        return res; // the tree doesn't have k nodes
    }

    bool FindKLargestInBST::test() {
        vector<int> preOrder = {19, 7, 3, 2, BST_INT_NULL, BST_INT_NULL, 5, BST_INT_NULL, BST_INT_NULL, 11, BST_INT_NULL,
                17, 13, BST_INT_NULL, BST_INT_NULL, BST_INT_NULL, 43, 23, BST_INT_NULL, 37, 29, BST_INT_NULL, 31, BST_INT_NULL, BST_INT_NULL,
                41, BST_INT_NULL, BST_INT_NULL, 47, BST_INT_NULL, 53, BST_INT_NULL, BST_INT_NULL};

        size_t pos = 0;
        unique_ptr<BSTNode<int>> tree = createPreOrderIntBST(preOrder, &pos);

        vector<int> ans = {53, 47, 43};
        vector<int> res = findKLargestInBST(tree, 3);

        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result " << vec_to_string(res) << endl;

            return false;
        }

        return true;
    }

  } // chapter15
} // epi
