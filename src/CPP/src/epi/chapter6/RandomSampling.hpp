#ifndef SRC_EPI_CHAPTER6_RANDOMSAMPLING_HPP_
#define SRC_EPI_CHAPTER6_RANDOMSAMPLING_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter6 {
    class RandomSampling : public myutils::Solution {
        friend class myutils::SmartPtr;
    public:
        RandomSampling():
            Solution("EPI Chapter 6.11",
                     "Get k random elements from an array with n elements",
                     "Pick elements one by one") { }

        bool test();

        ~RandomSampling() { }

        void randomSampling(int k, std::vector<int> &vec);
    };
  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_RANDOMSAMPLING_HPP_ */
