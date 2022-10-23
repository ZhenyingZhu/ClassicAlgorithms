#ifndef SRC_EPI_CHAPTER14_ELIMINATEDUPLICATE_HPP_
#define SRC_EPI_CHAPTER14_ELIMINATEDUPLICATE_HPP_

#include "../../Solution.h"

#include <vector>

namespace epi {
  namespace chapter14 {
    class EliminateDuplicate : public myutils::Solution {
    public:
        struct Name;

        EliminateDuplicate():
            Solution("EPI Chapter 14.3",
                     "Remove first-name duplicates",
                     "First sort the array, then remove "
                     "duplicates in place from beginning.") { }

        ~EliminateDuplicate() { }

        void eliminateDuplicate(std::vector<Name> &vec);

        bool test();

    };

  } // chapter14
} // epi

#endif /* SRC_EPI_CHAPTER14_ELIMINATEDUPLICATE_HPP_ */
