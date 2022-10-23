#ifndef SRC_EPI_CHAPTER16_GENERATEALLBINARYTREES_HPP_
#define SRC_EPI_CHAPTER16_GENERATEALLBINARYTREES_HPP_

#include "../../Solution.h"
#include "../../BinaryTreeNode.h"

#include <vector>
#include <memory>

namespace epi {
  namespace chapter16 {
    class GenerateAllBinaryTrees : public myutils::Solution {
    public:
        GenerateAllBinaryTrees():
            Solution("EPI Chapter 16.8",
                     "Generate binary trees",
                     "If there are two nodes, for a root, there can be 1 left "
                     "child and 0 right child, or 0 left child and 1 right child. "
                     "Recursive left subtree nodes number from 0 to n, and build trees.") { }

        ~GenerateAllBinaryTrees() { }

        std::vector<std::unique_ptr<myutils::BinaryTreeNode<int>>> generateAllBinaryTrees(int numNodes);

        bool test();

    private:
        std::unique_ptr<myutils::BinaryTreeNode<int>> clone(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_GENERATEALLBINARYTREES_HPP_ */
