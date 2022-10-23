#ifndef SRC_EPI_CHAPTER6_NEXTPERMUTATION_HPP_
#define SRC_EPI_CHAPTER6_NEXTPERMUTATION_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter6 {

    class NextPermutation : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        NextPermutation():
            Solution("EPI Chapter 6.10",
                     "Compute the next permutation",
                     "Find the first smaller value, then "
                     "insert the last value before it") { }

        bool test();

        ~NextPermutation() { }

        std::vector<int> nextPermutationBruteForce(std::vector<int> perm);

        std::vector<int> nextPermutation(std::vector<int> perm);

    private:
        bool isOneOfPerm(int num, const std::vector<int> perm);
    };

  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_NEXTPERMUTATION_HPP_ */
