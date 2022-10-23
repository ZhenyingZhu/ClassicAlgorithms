#ifndef SRC_EPI_CHAPTER10_FINDKTHNODEBINARYTREE_HPP_
#define SRC_EPI_CHAPTER10_FINDKTHNODEBINARYTREE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <memory>
#include <vector>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter10 {

    class FindKthNodeBinaryTree : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        FindKthNodeBinaryTree():
            Solution("EPI Chapter 10.9",
                     "Compute the kth node in an inorder traversal",
                     "Compute the number of nodes in the subtree of a "
                     "node for each node. Then use D&Q to solve the problem.") { }

        ~FindKthNodeBinaryTree() { }

        const myutils::BinaryTreeNode<int>* findKthNodeBinaryTree(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree, int k);

        bool test();

    private:
        size_t updateNodesWithSubtreeSize(const std::unique_ptr<myutils::BinaryTreeNode<int>> &tree);
    };

  } // chapter10
} // epi

#endif /* SRC_EPI_CHAPTER10_FINDKTHNODEBINARYTREE_HPP_ */
