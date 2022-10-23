#ifndef SRC_EPI_CHAPTER16_PERMUTATIONS_HPP_
#define SRC_EPI_CHAPTER16_PERMUTATIONS_HPP_

#include "../../Solution.h"

#include <vector>
#include <memory>

namespace epi {
  namespace chapter16 {
    class Permutations : public myutils::Solution {
    public:
        Permutations():
            Solution("EPI Chapter 16.3",
                     "Generate permutations",
                     "Sort the input array, then use a bool vector to "
                     "indicate which elements are already added, and "
                     "call recursive.") { }

        ~Permutations() { }

        std::vector<std::vector<int>> permutations(std::vector<int> array);

        bool test();

    private:
        void permutationsHelper(std::vector<int> &array, std::vector<int> &prevAdded,
                std::vector<bool> &isEntriesAdded, std::vector<std::vector<int>> &result);

    };

  } // chapter16
} // epi

#endif /* SRC_EPI_CHAPTER16_PERMUTATIONS_HPP_ */
