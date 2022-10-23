#include "ExteriorBinaryTree.hpp"

#include <memory>
#include <list>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::unique_ptr;
using std::list;
using std::vector;
using std::move;
using myutils::traversePreInOrder;
using myutils::BinaryTreeNode;
using myutils::BTNULL;
using std::invalid_argument;
using myutils::createPreOrderIntBTree;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter10 {
    list< const unique_ptr<BinaryTreeNode<int>>* > ExteriorBinaryTree::leftBoundary(
            const unique_ptr<BinaryTreeNode<int>> &node, bool isBoundary) {
        list< const unique_ptr<BinaryTreeNode<int>>* > partialExterior;

        if (isBoundary || (!node.get()->left && !node.get()->right) )
            partialExterior.push_back(&node);

        if (node.get()->left)
            partialExterior.splice( partialExterior.end(), leftBoundary(node.get()->left, isBoundary) );
        if (node.get()->right)
            partialExterior.splice( partialExterior.end(), leftBoundary(node.get()->right, isBoundary && !node.get()->left) );

        return partialExterior;
    }

    list< const unique_ptr<BinaryTreeNode<int>>* > ExteriorBinaryTree::rightBoundary(
            const unique_ptr<BinaryTreeNode<int>> &node, bool isBoundary) {
        list< const unique_ptr<BinaryTreeNode<int>>* > partialExterior;

        if (node.get()->left)
            partialExterior.splice( partialExterior.end(), rightBoundary(node.get()->left, isBoundary && !node.get()->right) );
        if (node.get()->right)
            partialExterior.splice( partialExterior.end(), rightBoundary(node.get()->right, isBoundary) );

        if (isBoundary || (!node.get()->left && !node.get()->right) )
            partialExterior.push_back(&node);

        return partialExterior;
    }

    list< const unique_ptr<BinaryTreeNode<int>>* > ExteriorBinaryTree::exteriorBinaryTree(
            const unique_ptr<BinaryTreeNode<int>> &tree) {
        list< const unique_ptr<BinaryTreeNode<int>>* > exterior;

        if (!tree)
            return exterior;
        exterior.push_back(&tree);

        if (!tree.get()->left)
            exterior.splice(exterior.end(), exteriorBinaryTree(tree.get()->right));
        else if (!tree.get()->right)
            exterior.splice(exterior.end(), exteriorBinaryTree(tree.get()->left));
        else {
            exterior.splice(exterior.end(), leftBoundary(tree.get()->left, true));
            exterior.splice(exterior.end(), rightBoundary(tree.get()->right, true));
        }

        return exterior;
    }

    bool ExteriorBinaryTree::test() {
        vector<int> preOrder1 = {314, 6, 271, 28, BTNULL, BTNULL, 0, BTNULL, BTNULL,
                561, BTNULL, 3, 17, BTNULL, BTNULL, BTNULL,
                6, 2, BTNULL, 1, 401, BTNULL, 641, BTNULL, BTNULL, 257, BTNULL, BTNULL,
                272, BTNULL, 29
        };
        size_t pos = 0;
        unique_ptr<BinaryTreeNode<int>> root1 = createPreOrderIntBTree(preOrder1, &pos);

        vector<int> ans = {314, 6, 271, 28, 0, 17, 641, 257, 29, 272, 6};

        list< const unique_ptr<BinaryTreeNode<int>>* > list = exteriorBinaryTree(root1);
        vector<int> res;
        for (auto it = list.begin(); it != list.end(); ++it) {
            res.push_back((*it)->get()->data);
        }

        if (res != ans) {
            cout << "Should be " << vec_to_string(ans) << endl;
            cout << "Result    " << vec_to_string(res) << endl;
            return false;
        }

        return true;
    }

  } // chapter10
} // epi
