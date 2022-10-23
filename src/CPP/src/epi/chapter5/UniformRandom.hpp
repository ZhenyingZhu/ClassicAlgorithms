#ifndef SRC_EPI_CHAPTER5_UNIFORMRANDOM_HPP_
#define SRC_EPI_CHAPTER5_UNIFORMRANDOM_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
namespace chapter5 {

class UniformRandom : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    UniformRandom():
        Solution("EPI Chapter 5.10",
                 "Generate uniform random number between a and b",
                 "Using a 0/1 random generator") { }

    bool test();

    ~UniformRandom() { }

    int uniformRandom(int lower, int upper);

private:
    int zeroOneRandom();
};

} // chapter5
} // epi

#endif /* SRC_EPI_CHAPTER5_UNIFORMRANDOM_HPP_ */
