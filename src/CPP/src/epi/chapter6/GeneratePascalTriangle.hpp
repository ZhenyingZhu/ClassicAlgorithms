#ifndef SRC_EPI_CHAPTER6_GENERATEPASCALTRIANGLE_HPP_
#define SRC_EPI_CHAPTER6_GENERATEPASCALTRIANGLE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter6 {
    class GeneratePascalTriangle : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        GeneratePascalTriangle():
            Solution("EPI Chapter 6.19",
                 "Compute rows in Pascal's triangle",
                 "Use previous row, or nCi") { }

        bool test();

        ~GeneratePascalTriangle() { }

        std::vector< std::vector<int> > generatePascalTriangle(unsigned numRows);

        std::vector< std::vector<int> > generatePascalTriangleMath(unsigned numRows);

    private:
        int combine(unsigned m, unsigned n);
    };

  } // chapter6
} // epi

#endif /* SRC_EPI_CHAPTER6_GENERATEPASCALTRIANGLE_HPP_ */
