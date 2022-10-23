#ifndef SRC_EPI_CHAPTER5_REVERSE_HPP_
#define SRC_EPI_CHAPTER5_REVERSE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
namespace chapter5 {

class Reverse : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Reverse():
        Solution("EPI Chapter 5.8",
                 "Reverse digits",
                 "Reverse digits of an integer. "
                 "Leave sign unchanged.") { }

    bool test();

    ~Reverse() { }

    long long reverseBruteForce(int);
    long long reverse(int);
};

} // chapter5
} // eip

#endif /* SRC_EPI_CHAPTER5_REVERSE_HPP_ */
