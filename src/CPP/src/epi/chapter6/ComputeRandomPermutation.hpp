#ifndef SRC_EPI_CHAPTER6_COMPUTERANDOMPERMUTATION_HPP_
#define SRC_EPI_CHAPTER6_COMPUTERANDOMPERMUTATION_HPP_

#include <vector>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter6 {
    class ComputeRandomPermutation : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ComputeRandomPermutation():
            Solution("EPI Chapter 6.13",
                     "Compute a random permutation",
                     "Random pick one element and move to the front.") { }

        bool test();

        ~ComputeRandomPermutation() { }

        std::vector<int> computeRandomPermutation(int n);
    };
  } // chapter6

} // epi


#endif /* SRC_EPI_CHAPTER6_COMPUTERANDOMPERMUTATION_HPP_ */
