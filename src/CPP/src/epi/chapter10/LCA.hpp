#ifndef SRC_EPI_CHAPTER10_LCA_HPP_
#define SRC_EPI_CHAPTER10_LCA_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class LCA : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        LCA():
            Solution("EPI Chapter 10.3",
                     "Compute the lowest common ancestor(LCA) in a binary tree",
                     "check if the two nodes are in different subtrees of a node.") { }

        ~LCA() { }

        myutils::BinaryTreeNode<int>* lowestCommonAncestor(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree,
                                                           const std::unique_ptr<myutils::BinaryTreeNode<int>> &node1,
                                                           const std::unique_ptr<myutils::BinaryTreeNode<int>> &node2);

        bool test();

    private:
        struct Status {
            myutils::BinaryTreeNode<int> *ancestor;
            size_t nodesNum;
        };

        Status lcaHelper(const std::unique_ptr<myutils::BinaryTreeNode<int>> &root,
                         const std::unique_ptr<myutils::BinaryTreeNode<int>> &node1,
                         const std::unique_ptr<myutils::BinaryTreeNode<int>> &node2);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_LCA_HPP_ */
