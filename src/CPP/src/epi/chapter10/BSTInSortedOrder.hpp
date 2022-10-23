#ifndef SRC_EPI_CHAPTER10_BSTINSORTEDORDER_HPP_
#define SRC_EPI_CHAPTER10_BSTINSORTEDORDER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class BSTInSortedOrder : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        BSTInSortedOrder():
            Solution("EPI Chapter 10.7",
                     "Implement an inorder traversal without recursion",
                     "Use a stack. If the left child of a node is already"
                     " traversed, output this node, otherwise push it back.") { }

        ~BSTInSortedOrder() { }

        std::vector<int> inSortedOrder(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);

        bool test();

    private:
        struct Status;
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_BSTINSORTEDORDER_HPP_ */
