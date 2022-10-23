#ifndef SRC_EPI_CHAPTER19_FILLSURROUNDEDREGIONS_HPP_
#define SRC_EPI_CHAPTER19_FILLSURROUNDEDREGIONS_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter19 {
    class FillSurroundedRegions : public myutils::Solution {
    public:
        struct Coordinate;

        FillSurroundedRegions():
            Solution("EPI Chapter 19.3",
                     "Compute enclosed regions",
                     "Given a matrix with B and W color cells. Replace "
                     "all W color cells with B if they cannot reach the "
                     "boundary. Search from boundary, and mark these cells "
                     "with another color. Then flip all cells.") { }

        ~FillSurroundedRegions() { }

        void fillSurroundedRegions(std::vector<std::vector<char>> &board);

        bool test();

    private:
        void flipColor(const Coordinate &start, std::vector<std::vector<char>> &board);
    };

  } // chapter19
} // epi

#endif /* SRC_EPI_CHAPTER19_FILLSURROUNDEDREGIONS_HPP_ */
