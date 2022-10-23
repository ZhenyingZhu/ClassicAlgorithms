#ifndef SRC_EPI_CHAPTER5_SWAPBITS_HPP_
#define SRC_EPI_CHAPTER5_SWAPBITS_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

namespace epi {
namespace chapter5 {

class SwapBits : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    SwapBits():
        Solution("EPI Chapter 5.2",
                "Swap Bits",
                "Swap bits at i and j. "
                "LSB as 0, and MSB as 31.") { }

    bool test();

    ~SwapBits() { }

    long swapBits(long x, int i, int j);

};

} // chapter5
} // eip

#endif /* SRC_EPI_CHAPTER5_SWAPBITS_HPP_ */
