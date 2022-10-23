#ifndef SRC_EPI_CHAPTER7_INTERCONVERTINTSTR_HPP_
#define SRC_EPI_CHAPTER7_INTERCONVERTINTSTR_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class InterconvertIntStr : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        InterconvertIntStr():
            Solution("EPI Chapter 7.1",
                     "Interconvert strings and integers",
                     "Digit by digit. Refer to atoi") { }

        bool test();

        ~InterconvertIntStr() { }

        std::string intToString(int);

        int stringToInt(const std::string&);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_INTERCONVERTINTSTR_HPP_ */
