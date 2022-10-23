#ifndef SRC_EPI_CHAPTER16_COMBINATIONS_HPP_
#define SRC_EPI_CHAPTER16_COMBINATIONS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter16 {
    class Combinations : public myutils::Solution {
    public:
        Combinations():
            Solution("EPI Chapter 16.5",
                     "Generate all subsets of size k",
                     "Call recursive.") { }

        ~Combinations() { }

        std::vector<std::vector<unsigned int>> combinations(unsigned int n, size_t k);

        bool test();

    private:
        void combinationsHelper(unsigned int n, size_t k, unsigned int st,
                std::vector<unsigned int> &prevAdded, std::vector<std::vector<unsigned int>> &result);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_COMBINATIONS_HPP_ */
