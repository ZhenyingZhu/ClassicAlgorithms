#ifndef SRC_EPI_CHAPTER13_LCA_HPP_
#define SRC_EPI_CHAPTER13_LCA_HPP_

#include "../../Solution.h"

#include <memory>

#include "../../BinaryTreeNode.h"

namespace epi {
  namespace chapter13 {
    class LCA : public myutils::Solution {
    public:
        LCA():
            Solution("EPI Chapter 13.4",
                     "Compute the LCA, optimizing for close ancestors",
                     "traverse to root from both nodes at the same time. "
                     "If find one node already in the hash map, return.") { }

        ~LCA() { }

        myutils::BinaryTreeNode<int>* findLCA(const std::unique_ptr<myutils::BinaryTreeNode<int>> &node0,
                                              const std::unique_ptr<myutils::BinaryTreeNode<int>> &node1);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_LCA_HPP_ */
