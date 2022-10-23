#ifndef SRC_EPI_CHAPTER13_FINDNEARESTREPETITION_HPP_
#define SRC_EPI_CHAPTER13_FINDNEARESTREPETITION_HPP_

#include "../../Solution.h"

#include <vector>
#include <string>

namespace epi {
  namespace chapter13 {
    class FindNearestRepetition : public myutils::Solution {
    public:
        FindNearestRepetition():
            Solution("EPI Chapter 13.6",
                     "Find the nearest repeated entries in an array",
                     "Use hash table to record string and the index "
                     "of its previous presence.") { }

        ~FindNearestRepetition() { }

        int findNearestRepetition(const std::vector<std::string> &paragraph);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_FINDNEARESTREPETITION_HPP_ */
