#ifndef SRC_EPI_CHAPTER6_DUTCHFLAGPARTITION_HPP_
#define SRC_EPI_CHAPTER6_DUTCHFLAGPARTITION_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

class DutchFlagPartition : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    typedef enum { RED, WHITE, BLUE } Color;

public:
    DutchFlagPartition():
        Solution("EPI Chapter 6.1",
                 "Dutch Flag Partition",
                 "Sort array into 3 subarrays,"
                 " follow quick sort.") { }

    bool test();

    ~DutchFlagPartition() { }

    void bruteForceTwoThrough(int pivotIndex, std::vector<Color> &arr);

    void dutchFlagTwoThrough(int pivotIndex, std::vector<Color> &arr);

    void dutchFlagPartition(int pivotIndex, std::vector<Color> &arr);

private:
    void swap(Color*, Color*);
};

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_DUTCHFLAGPARTITION_HPP_ */
