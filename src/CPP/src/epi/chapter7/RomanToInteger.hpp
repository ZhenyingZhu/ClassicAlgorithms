#ifndef SRC_EPI_CHAPTER7_ROMANTOINTEGER_HPP_
#define SRC_EPI_CHAPTER7_ROMANTOINTEGER_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

#include <string>

namespace epi {
  namespace chapter7 {

    class RomanToInteger : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        RomanToInteger():
            Solution("EPI Chapter 7.9",
                     "Convert from roman to decimal",
                     "Destract if smaller than next one.") {
        }

        ~RomanToInteger() { }

        int romanToInteger(const std::string &s);

        bool test();
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_ROMANTOINTEGER_HPP_ */
