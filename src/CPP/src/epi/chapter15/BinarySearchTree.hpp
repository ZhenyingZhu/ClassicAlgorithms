#ifndef SRC_EPI_CHAPTER15_BINARYSEARCHTREE_HPP_
#define SRC_EPI_CHAPTER15_BINARYSEARCHTREE_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class BinarySearchTree : public myutils::Solution {
    public:
        class BST;

        BinarySearchTree():
            Solution("EPI Chapter 15.10",
                     "Insertion and deletion in a BST",
                     "Keys are unique. Insert: try to find the key, if find, return; else, "
                     "must at a leave, which can add node to; Delete: Find its successor in "
                     "its right subtree. If no right subtree, move left subtree to it; Otherwise "
                     "its successor must doesn't have left subtree. Replace successor's value to "
                     "the deletion node, and then replace the successor with its right subtree.") { }

        ~BinarySearchTree() { }

        bool test();

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_BINARYSEARCHTREE_HPP_ */
