#include "GenerateAllBinaryTrees.hpp"

#include <vector>
#include <memory>
#include <iostream>
#include <stdexcept>
#include <cassert>

#include "../../BinaryTreeNode.h"
#include "../../MyUtils.h"

using std::vector;
using std::unique_ptr;
using myutils::BinaryTreeNode;
using std::move;
using myutils::traversePreInOrder;
using myutils::vec_to_string;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter16 {
    unique_ptr<BinaryTreeNode<int>> GenerateAllBinaryTrees::clone(const unique_ptr<BinaryTreeNode<int>> &node) {
        if (node == nullptr)
            return nullptr;

        unique_ptr<BinaryTreeNode<int>> newNode(new BinaryTreeNode<int>(node->data));
        newNode->left = move(clone(node->left));
        newNode->right = move(clone(node->right));

        return newNode;
    }

    vector<unique_ptr<BinaryTreeNode<int>>> GenerateAllBinaryTrees::generateAllBinaryTrees(int numNodes) {
        vector<unique_ptr<BinaryTreeNode<int>>> res;
        if (numNodes == 0) {
            res.push_back(nullptr);
            return res;
        }

        for (int l = 0; l != numNodes; ++l) { // minus root node
            int r = numNodes - l - 1;
            vector<unique_ptr<BinaryTreeNode<int>>> leftSubtrees = generateAllBinaryTrees(l);
            vector<unique_ptr<BinaryTreeNode<int>>> rightSubtrees = generateAllBinaryTrees(r);
            for (unique_ptr<BinaryTreeNode<int>> &leftSubtree : leftSubtrees) {
                for (unique_ptr<BinaryTreeNode<int>> &rightSubtree : rightSubtrees) {
                    unique_ptr<BinaryTreeNode<int>> root(new BinaryTreeNode<int>(0));
                    root->left = move(clone(leftSubtree));
                    root->right = move(clone(rightSubtree));

                    res.push_back(move(root));
                }
            }
        }

        return res;
    }

    bool GenerateAllBinaryTrees::test() {
        vector<unique_ptr<BinaryTreeNode<int>>> res = generateAllBinaryTrees(3);

        if (res.size() != 5) {
            cout << "Wrong number of results: " << res.size() << endl;
            for (unique_ptr<BinaryTreeNode<int>> &tree : res) {
                vector<int> preorder, inorder;
                traversePreInOrder(tree, inorder, preorder);
                cout << vec_to_string(inorder)  << endl;
            }

            return false;
        }

        return true;
    }

  } // chapter16
} // epi
