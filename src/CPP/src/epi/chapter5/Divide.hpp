#ifndef SRC_EPI_CHAPTER5_DIVIDE_HPP_
#define SRC_EPI_CHAPTER5_DIVIDE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
namespace chapter5 {

class Divide : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Divide():
        Solution("EPI Chapter 5.6",
                 "Divide",
                 "Divide x and y using only addition,"
                 " subtraction, and shifting.") { }

    bool test();

    ~Divide() { }

    unsigned divide(unsigned, unsigned);

};

} // chapter5
} // eip

#endif /* SRC_EPI_CHAPTER5_DIVIDE_HPP_ */
