#ifndef SRC_EPI_CHAPTER6_MULTIPLY_HPP_
#define SRC_EPI_CHAPTER6_MULTIPLY_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

class Multiply : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Multiply():
        Solution("EPI Chapter 6,3",
                 "Multiply two arbitary precision integers presented by vector "
                 "where the negative number has a negative number in the first cell.",
                 "Shift and plus.") { }

    bool test();

    ~Multiply() { }

    std::vector<int> multiply(std::vector<int>, std::vector<int>);

private:
    int convertVecToInt(const std::vector<int>&);
};

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_MULTIPLY_HPP_ */
