#ifndef SRC_EPI_CHAPTER15_FINDFIRSTGREATERTHANK_HPP_
#define SRC_EPI_CHAPTER15_FINDFIRSTGREATERTHANK_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>

namespace epi {
  namespace chapter15 {
    class FindFirstGreaterThanK : myutils::Solution {
    public:
        FindFirstGreaterThanK():
            Solution("EPI Chapter 15.2",
                     "Find the first key greater than a given value in a BST",
                     "Binary search. Store the latest seen larger value. If "
                     "find another larger value but smaller than the previous "
                     "one, return that one.") { }

        ~FindFirstGreaterThanK() { }

        myutils::BSTNode<int>* findFirstGreaterThanK(const std::unique_ptr<myutils::BSTNode<int>> &tree, int k);

        bool test();

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_FINDFIRSTGREATERTHANK_HPP_ */
