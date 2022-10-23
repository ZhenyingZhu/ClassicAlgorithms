#ifndef SRC_EPI_CHAPTER6_GENERATEPRIMES_HPP_
#define SRC_EPI_CHAPTER6_GENERATEPRIMES_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
namespace chapter6 {

    class GeneratePrimes : public myutils::Solution {
        friend myutils::SmartPtr;

    public:
        GeneratePrimes():
            Solution("EPI Chapter 6.8",
                     "Enumerate all primes to n",
                     "sift all multiples of founded prime numbers") { }

        bool test();

        ~GeneratePrimes() { }

        std::vector<int> generatePrimesBruteForce(int n);

        std::vector<int> generatePrimes(int n);

    private:
        int idxToNum(int);

        int numToIdx(int);
    };

} // chapter6
} // epi




#endif /* SRC_EPI_CHAPTER6_GENERATEPRIMES_HPP_ */
