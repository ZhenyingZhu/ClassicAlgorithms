#ifndef SRC_EPI_CHAPTER6_NONUNIFORMRANDOMNUMBERGENERATION_HPP_
#define SRC_EPI_CHAPTER6_NONUNIFORMRANDOMNUMBERGENERATION_HPP_

#include <vector>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter6 {
    class NonuniformRandomNumberGeneration : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        NonuniformRandomNumberGeneration():
            Solution("EPI Chapter 6.15",
                     "Generate number in a set that are not uniform distributed",
                     "Split 0~1 into spans that are follow the distribution.") { }

        bool test();

        ~NonuniformRandomNumberGeneration() { }

        int nonuniformRandomNumberGeneration(const std::vector<int> &values, const std::vector<double> &probabilities);
    };
  } // chapter6
} // epi


#endif /* SRC_EPI_CHAPTER6_NONUNIFORMRANDOMNUMBERGENERATION_HPP_ */
