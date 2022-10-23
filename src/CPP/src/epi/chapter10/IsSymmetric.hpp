#ifndef SRC_EPI_CHAPTER10_ISSYMMETRIC_HPP_
#define SRC_EPI_CHAPTER10_ISSYMMETRIC_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class IsSymmetric : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        IsSymmetric():
            Solution("EPI Chapter 10.2",
                     "Test if a binary tree is symmetric",
                     "Recursive check if the left subtree has the same right "
                     "node as the right subtree left node, and vice visa.") { }

        ~IsSymmetric() { }

        bool isSymmetric(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        bool compare(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node1,
                    const std::unique_ptr<myutils::BinaryTreeNode<int>> &node2);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_ISSYMMETRIC_HPP_ */
