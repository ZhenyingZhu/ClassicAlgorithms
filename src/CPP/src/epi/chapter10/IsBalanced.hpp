#ifndef SRC_EPI_CHAPTER10_ISBALANCED_HPP_
#define SRC_EPI_CHAPTER10_ISBALANCED_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class IsBalanced : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        IsBalanced():
            Solution("EPI Chapter 10.1",
                     "Test if a binary tree is height-balanced",
                     "Recursive compute height, and return -1 if "
                     "the subtree is not balance.") { }

        ~IsBalanced() { }

        bool isBalanced(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        int computeHeight(const std::unique_ptr<myutils::BinaryTreeNode<int>> &root);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_ISBALANCED_HPP_ */
