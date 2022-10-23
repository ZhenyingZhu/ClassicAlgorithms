#ifndef SRC_EPI_CHAPTER15_GENERATEFIRSTKABSQRT2_HPP_
#define SRC_EPI_CHAPTER15_GENERATEFIRSTKABSQRT2_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter15 {
    class GenerateFirstKABSqrt2 : public myutils::Solution {
    public:
        struct ABSqrt2;

        GenerateFirstKABSqrt2():
            Solution("EPI Chapter 15.7",
                     "Enumerate first k numbers of the form a + b sqrt(2)",
                     "Note if `a+b*sqrt(2)=a'+b'*sqrt(2)`, then a=a', b=b'. So compute "
                     "all numbers of a=0, b=0 to a=k-1, b=k-1, and then sort them.") { }

        ~GenerateFirstKABSqrt2() { }

        std::vector<ABSqrt2> generateFirstKABSqrt2BST(size_t k);

        std::vector<ABSqrt2> generateFirstKABSqrt2Ptrs(size_t k);

        bool test();

    };

  } // chapter15
} // epi

#endif /* SRC_EPI_CHAPTER15_GENERATEFIRSTKABSQRT2_HPP_ */
