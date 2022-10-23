#ifndef SRC_EPI_CHAPTER17_OPTIMUMSUBJECTOCAPACITY_HPP_
#define SRC_EPI_CHAPTER17_OPTIMUMSUBJECTOCAPACITY_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter17 {
    class OptimumSubjecToCapacity : public myutils::Solution {
    public:
        struct Item;

        OptimumSubjecToCapacity():
            Solution("EPI Chapter 17.6",
                     "The knapsack problem",
                     "Compute weight from 0 to weight. w means the capacity, "
                     "i means include previous i items. Value(i, w) = "
                     "max( Value(i-1, w), Value(i-1, w-wi) + vi ).") { }

        ~OptimumSubjecToCapacity() { }

        unsigned int optimumSubjecToCapacity(const std::vector<Item> &items, size_t capacity);

        bool test();

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_OPTIMUMSUBJECTOCAPACITY_HPP_ */
