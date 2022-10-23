#ifndef SRC_EPI_CHAPTER10_LCAWITHPARENT_HPP_
#define SRC_EPI_CHAPTER10_LCAWITHPARENT_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class LCAWithParent : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        LCAWithParent():
            Solution("EPI Chapter 10.4",
                     "Compute the LCA when nodes have parent pointers",
                     "Compute the height of the first node and the "
                     "second node, then use runner pointer.") { }

        ~LCAWithParent() { }

        myutils::BinaryTreeNode<int>* lowestCommonAncestor(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node1,
                                                           const std::unique_ptr<myutils::BinaryTreeNode<int>> &node2);

        bool test();

    private:
        int getDepth(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_LCAWITHPARENT_HPP_ */
