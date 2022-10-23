#ifndef SRC_EPI_CHAPTER22_MACROUSAGE_HPP_
#define SRC_EPI_CHAPTER22_MACROUSAGE_HPP_

#include "../../Solution.h"

#include <iostream>

#define macrocomparetwice(c) (c > 0 && c > 0)

namespace epi {
  namespace chapter22 {
    class MacroUsage : public myutils::Solution {
    public:
        MacroUsage():
            Solution("EPI Chapter 22.11",
                     "Fast function calls",
                     "Macro expands anything in the pass-in args, so if pass-in "
                     "++ operator, the arg will ++ in macro leads to errors.") { }

        ~MacroUsage() { }

        inline bool compareTwice(int c) {
            return (c > 0 && c > 0);
        }

        bool test();

    };

  } // chapter22
} // epi

#endif /* SRC_EPI_CHAPTER22_MACROUSAGE_HPP_ */
