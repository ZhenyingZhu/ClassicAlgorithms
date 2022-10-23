#ifndef SRC_EPI_CHAPTER10_SUMROOTTOLEAF_HPP_
#define SRC_EPI_CHAPTER10_SUMROOTTOLEAF_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class SumRootToLeaf : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        SumRootToLeaf():
            Solution("EPI Chapter 10.5",
                     "Sum the root-to-leaf paths present in binary in a binary tree",
                     "Pass a variable to the child node. Sum left path and right path.") { }

        ~SumRootToLeaf() { }

        int sumRootToLeaf(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        int sumRootToLeafHelper(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node, int partialPathSum);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_SUMROOTTOLEAF_HPP_ */
