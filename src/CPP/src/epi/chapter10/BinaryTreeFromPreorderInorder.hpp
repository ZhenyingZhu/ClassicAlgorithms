#ifndef SRC_EPI_CHAPTER10_BINARYTREEFROMPREORDERINORDER_HPP_
#define SRC_EPI_CHAPTER10_BINARYTREEFROMPREORDERINORDER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class BinaryTreeFromPreorderInorder : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        BinaryTreeFromPreorderInorder():
            Solution("EPI Chapter 10.12",
                     "Reconstruct a binary tree from traversal data",
                     "Given inorder and preorder traveral, The first node of "
                     "preorder is the root, and in inorder sequence, before "
                     "this node is the subtree part.") { }

        ~BinaryTreeFromPreorderInorder() { }

        std::unique_ptr<myutils::BinaryTreeNode<int>> binaryTreeFromPreorderInorder(
                const std::vector<int> &preorder,
                const std::vector<int> &inorder);

        bool test();

    private:
        std::unique_ptr<myutils::BinaryTreeNode<int>> btConstructHelper(
                const std::vector<int> &preorder,
                std::vector<int>::const_iterator pst, std::vector<int>::const_iterator ped,
                const std::vector<int> &inorder,
                std::vector<int>::const_iterator ist, std::vector<int>::const_iterator ied);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_BINARYTREEFROMPREORDERINORDER_HPP_ */
