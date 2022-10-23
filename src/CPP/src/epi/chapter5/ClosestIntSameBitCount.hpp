#ifndef SRC_EPI_CHAPTER5_CLOSESTINTSAMEBITCOUNT_HPP_
#define SRC_EPI_CHAPTER5_CLOSESTINTSAMEBITCOUNT_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

namespace epi {
namespace chapter5 {

class ClosestIntSameBitCount : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    ClosestIntSameBitCount():
        Solution("EPI Chapter 5.4",
                "Closest integer that has same 1 bits",
                "Find the closest integer that has same "
                "weight as the given number. Weight "
                "is count as number of set bits.") { }

    bool test();

    ~ClosestIntSameBitCount() { }

    unsigned long closestIntBruteForce(unsigned long x);

    unsigned long closestIntLinearSearch(unsigned long x);

    unsigned long closestIntSameBitCount(unsigned long x);

private:
    size_t countBit(unsigned long x);
};

} // chapter5
} // eip

#endif /* SRC_EPI_CHAPTER5_CLOSESTINTSAMEBITCOUNT_HPP_ */
