#ifndef SRC_EPI_CHAPTER12_FINDBUPLICATEMISSING_HPP_
#define SRC_EPI_CHAPTER12_FINDBUPLICATEMISSING_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <vector>

namespace epi {
  namespace chapter12 {
    class FindBuplicateMissing : myutils::Solution {
    public:
        struct DuplicateAndMissing;

        FindBuplicateMissing():
            Solution("EPI Chapter 12.10",
                     "Find the duplicate and missing elements",
                     "One element is replaced by another element. To seperate "
                     "the vector from a vector that only contains the missing "
                     "A, and a vector that only contains the duplicate B, do xor "
                     "for all elements lead to A ^ B. So we know which bits are "
                     "different in A and B. Now search for all the elements that "
                     "have that bit set, can tell us either A or B. Traverse the "
                     "array to find out another one.") { }

        ~FindBuplicateMissing() { }

        DuplicateAndMissing findBuplicateMissing(std::vector<int> &vec);

        bool test();

    };

  } // chapter12
} // epi

#endif /* SRC_EPI_CHAPTER12_FINDBUPLICATEMISSING_HPP_ */
