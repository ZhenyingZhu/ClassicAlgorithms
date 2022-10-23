#ifndef SRC_EPI_CHAPTER5_POWER_HPP_
#define SRC_EPI_CHAPTER5_POWER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
namespace chapter5 {

class Power : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Power():
        Solution("EPI Chapter 5.7",
                 "Compute x ^ y",
                 "x is double and y is integer") { }

    bool test();

    ~Power() { }

    double power(double x, int y);
};

} // chapter5
} // eip

#endif /* SRC_EPI_CHAPTER5_POWER_HPP_ */
