#ifndef SRC_EPI_CHAPTER15_BUILDMINHEIGHTBSTFROMSORTEDARRAY_HPP_
#define SRC_EPI_CHAPTER15_BUILDMINHEIGHTBSTFROMSORTEDARRAY_HPP_

#include "../../Solution.h"
#include "../../BSTNode.h"

#include <memory>
#include <vector>

namespace epi {
  namespace chapter15 {
    class BuildMinHeightBSTFromSortedArray : public myutils::Solution {
    public:
        BuildMinHeightBSTFromSortedArray():
            Solution("EPI Chapter 15.9",
                     "Build a minimum height BST from a sorted array",
                     "Use the middle as the root.") { }

        ~BuildMinHeightBSTFromSortedArray() { }

        std::unique_ptr<myutils::BSTNode<int>> buildMinHeightBSTFromSortedArray(const std::vector<int> &sortedArray);

        bool test();

    private:
        std::unique_ptr<myutils::BSTNode<int>> buildBSTHelper(const std::vector<int> &sortedArray, int st, int ed);

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_BUILDMINHEIGHTBSTFROMSORTEDARRAY_HPP_ */
