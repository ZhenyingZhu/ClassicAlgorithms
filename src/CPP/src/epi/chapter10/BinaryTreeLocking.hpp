#ifndef SRC_EPI_CHAPTER10_BINARYTREELOCKING_HPP_
#define SRC_EPI_CHAPTER10_BINARYTREELOCKING_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

namespace epi {
  namespace chapter10 {

    class BinaryTreeLocking : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        class BinaryTreeNode;

        BinaryTreeLocking():
            Solution("EPI Chapter 10.17",
                     "Implement locking in a binary tree",
                     "Use a counter to indicate how many nodes are locked in "
                     "subtree. So only if this value is 0, and no nodes locked"
                     " on the path to root, this node can be locked..") { }

        ~BinaryTreeLocking() { }

        bool test();

    private:
        std::shared_ptr<BinaryTreeNode> createPreOrderIntBTree(const std::vector<int> &vec, size_t *pos);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_BINARYTREELOCKING_HPP_ */
