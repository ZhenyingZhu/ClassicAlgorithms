#ifndef SRC_EPI_CHAPTER10_EXTERIORBINARYTREE_HPP_
#define SRC_EPI_CHAPTER10_EXTERIORBINARYTREE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <list>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class ExteriorBinaryTree : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ExteriorBinaryTree():
            Solution("EPI Chapter 10.15",
                     "Compute the exterior of a binary tree",
                     "Use a flag to indicate if it is boundary.") { }

        ~ExteriorBinaryTree() { }

        std::list< const std::unique_ptr<myutils::BinaryTreeNode<int>>* > exteriorBinaryTree(
                const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        std::list< const std::unique_ptr<myutils::BinaryTreeNode<int>>* > leftBoundary(
                const std::unique_ptr<myutils::BinaryTreeNode<int>> &node, bool isBoundary);

        std::list< const std::unique_ptr<myutils::BinaryTreeNode<int>>* > rightBoundary(
                const std::unique_ptr<myutils::BinaryTreeNode<int>> &node, bool isBoundary);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_EXTERIORBINARYTREE_HPP_ */
