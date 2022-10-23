#ifndef SRC_EPI_CHAPTER6_CANREACHEND_HPP_
#define SRC_EPI_CHAPTER6_CANREACHEND_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

class CanReachEnd : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    CanReachEnd():
        Solution("EPI Chapter 6.4",
                 "Advancing through an array of steps, check if can reach the end",
                 "Each non-negative integer in an array indicate how far it can go from this cell."
                 "Store the max cell current cell can reach") { }

    bool test();

    ~CanReachEnd() { }

    bool canReachEnd(const std::vector<int>&);
};

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_CANREACHEND_HPP_ */
