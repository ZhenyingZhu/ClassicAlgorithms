#include "IsBinaryTreeBST.hpp"

#include <memory>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::vector;
using myutils::BinaryTreeNode;
using myutils::createPreOrderIntBTree;
using myutils::BTNULL;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter15 {
    struct IsBinaryTreeBST::SubtreeRange {
        bool isBST;
        int left;
        int right;
    };

    IsBinaryTreeBST::SubtreeRange IsBinaryTreeBST::bstCheckHelper(const unique_ptr<BinaryTreeNode<int>> &node) {
        assert(node != nullptr);

        int data = node.get()->data;

        SubtreeRange leftChildRange{true, data, data}, rightChildRange{true, data, data};
        if (node.get()->left != nullptr)
            leftChildRange = bstCheckHelper(node.get()->left);

        if (node.get()->right != nullptr)
            rightChildRange = bstCheckHelper(node.get()->right);

        if (!leftChildRange.isBST || !rightChildRange.isBST ||
                data < leftChildRange.right || data > rightChildRange.left)
            return {false, 0, 0};

        return {true, leftChildRange.left, rightChildRange.right};
    }

    bool IsBinaryTreeBST::isBinaryTreeBST(const unique_ptr<BinaryTreeNode<int>> &tree) {
        if (tree == nullptr)
            return true;

        return bstCheckHelper(tree).isBST;
    }

    bool IsBinaryTreeBST::test() {
        vector<int> preOrder = {19, 7, 3, 2, BTNULL, BTNULL, 5, BTNULL, BTNULL, 11, BTNULL, 17, 13, BTNULL, BTNULL, BTNULL,
            43, 23, BTNULL, 37, 29, BTNULL, 31, BTNULL, BTNULL, 41, BTNULL, BTNULL, 47, BTNULL, 53, BTNULL, BTNULL};

        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> tree = createPreOrderIntBTree(preOrder, &pos);

        if ( !isBinaryTreeBST(tree) ) {
            cout << "Should be a BST" << endl;
            return false;
        }

        return true;
    }

  } // chapter15
} // epi

