#ifndef SRC_EPI_CHAPTER10_HASPATHSUM_HPP_
#define SRC_EPI_CHAPTER10_HASPATHSUM_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class HasPathSum : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        HasPathSum():
            Solution("EPI Chapter 10.6",
                     "Find a root to leaf path with specified sum",
                     "Return true if find a path. Use recursive calls.") { }

        ~HasPathSum() { }

        bool hasPathSum(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree, int targetSum);

        bool test();

    private:
        bool hasPathSumHelper(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node, int partialPathSum, int targetSum);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_HASPATHSUM_HPP_ */
