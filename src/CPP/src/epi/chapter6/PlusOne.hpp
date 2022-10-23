#ifndef SRC_EPI_CHAPTER6_PLUSONE_HPP_
#define SRC_EPI_CHAPTER6_PLUSONE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

    class PlusOne : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        PlusOne():
            Solution("EPI Chapter 6.2",
                     "Increase a number that record in a vector",
                     "Use a carry on.") { }

        bool test();

        ~PlusOne() { }

        std::vector<int> plusOneBruteForce(std::vector<int>);

        std::vector<int> plusOne(std::vector<int>);

    private:
        std::vector<int> generateVectorFromNum(int);
    };

} // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_PLUSONE_HPP_ */
