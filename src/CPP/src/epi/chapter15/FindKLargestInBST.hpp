#ifndef SRC_EPI_CHAPTER15_FINDKLARGESTINBST_HPP_
#define SRC_EPI_CHAPTER15_FINDKLARGESTINBST_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class FindKLargestInBST : public myutils::Solution {
    public:
        FindKLargestInBST():
            Solution("EPI Chapter 15.3",
                     "Find the k largest elements in a BST",
                     "Reversed inorder traverse.") { }

        ~FindKLargestInBST() { }

        std::vector<int> findKLargestInBST(const std::unique_ptr<myutils::BSTNode<int>> &tree, size_t k);

        bool test();

    private:
        struct NodePushCnt;

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_FINDKLARGESTINBST_HPP_ */
