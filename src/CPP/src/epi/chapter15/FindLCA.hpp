#ifndef SRC_EPI_CHAPTER15_FINDLCA_HPP_
#define SRC_EPI_CHAPTER15_FINDLCA_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>

namespace epi {
  namespace chapter15 {
    class FindLCA : public myutils::Solution {
    public:
        FindLCA():
            Solution("EPI Chapter 15.4",
                     "Compute the LCA in a BST with distinct value",
                     "The first node that has value between two input "
                     "nodes, comming from root, is the LCA.") { }

        ~FindLCA() { }

        myutils::BSTNode<int>* findLCA(const std::unique_ptr<myutils::BSTNode<int>> &tree,
                                       const std::unique_ptr<myutils::BSTNode<int>> &a,
                                       const std::unique_ptr<myutils::BSTNode<int>> &b);

        bool test();

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_FINDLCA_HPP_ */
