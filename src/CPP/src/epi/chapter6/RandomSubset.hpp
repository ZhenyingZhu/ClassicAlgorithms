#ifndef SRC_EPI_CHAPTER6_RANDOMSUBSET_HPP_
#define SRC_EPI_CHAPTER6_RANDOMSUBSET_HPP_

#include <vector>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter6 {
    class RandomSubset : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RandomSubset():
            Solution("EPI Chapter 6.14",
                     "Find a k-element subset equally from 1~n",
                     "Using hash table to mimic random pick an "
                     "element and move to the front.") { }

        bool test();

        ~RandomSubset() { }

        std::vector<int> randomSubset(int n, int k);

        std::vector<int> randomSubsetBruteForce(int n, int k);
    };
  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_RANDOMSUBSET_HPP_ */
