#ifndef SRC_EPI_CHAPTER17_COMPUTEBINOMIALCOEFFICIENT_HPP_
#define SRC_EPI_CHAPTER17_COMPUTEBINOMIALCOEFFICIENT_HPP_

#include "../../Solution.h"

#include <unordered_map>
#include <utility>

namespace epi {
  namespace chapter17 {
    class ComputeBinomialCoefficient : public myutils::Solution {
    public:
        ComputeBinomialCoefficient():
            Solution("EPI Chapter 17.4",
                     "Compute the binomial coefficients",
                     "C(n, k)=C(n-1, k)+C(n-1, k-1). Use recursive with records of previous results.") { }

        ~ComputeBinomialCoefficient() { }

        int computeBinomialCoefficient(int n, int k);

        bool test();

    private:
        struct PairHash;

        int coefficientHelper(int n, int k, std::unordered_map<std::pair<int, int>, int, PairHash> &map);

    };

  } // chapter17
} // epi

#endif /* SRC_EPI_CHAPTER17_COMPUTEBINOMIALCOEFFICIENT_HPP_ */
