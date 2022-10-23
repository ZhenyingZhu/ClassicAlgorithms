#ifndef SRC_CHAPTER5_PARITY_HPP_
#define SRC_CHAPTER5_PARITY_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"
#include "../../SolutionCollection.h"

#include <unordered_map>

namespace epi {
namespace chapter5 {

class Parity : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    Parity():
        Solution("EPI Chapter 5.1",
                "Compute Parity",
                "If there are odd 1 in the number, "
                "return 1, else return 0.") { }

    bool test();

    ~Parity() { }

    short parityBruteForce(unsigned long);
    short parityEliminateLastOne(unsigned long);
    short parityUseCache(unsigned long, const int);
    short parity(unsigned long);

private:
    std::unordered_map<unsigned short, short> precomputedParity;

    void computeParity(int);

};

} // chapter5
} // eip

#endif /* SRC_CHAPTER5_PARITY_HPP_ */
