#ifndef SRC_EPI_CHAPTER15_ISBINARYTREEBST_HPP_
#define SRC_EPI_CHAPTER15_ISBINARYTREEBST_HPP_

#include "../../Solution.h"
#include "../../BinaryTreeNode.h"

#include <memory>
#include <iostream>

namespace epi {
  namespace chapter15 {
    class IsBinaryTreeBST : public myutils::Solution {
    public:
        IsBinaryTreeBST():
            Solution("EPI Chapter 15.1",
                     "Test if a binary tree satisfies the BST property",
                     "Use a struct to return the largest and smallest value "
                     "of a subtree, and a bool to indicate if the tree is not BST.") { }

        ~IsBinaryTreeBST() { }

        bool isBinaryTreeBST(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        struct SubtreeRange;

        SubtreeRange bstCheckHelper(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node);

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_ISBINARYTREEBST_HPP_ */
