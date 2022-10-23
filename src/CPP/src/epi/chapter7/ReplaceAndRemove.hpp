#ifndef SRC_EPI_CHAPTER7_REPLACEANDREMOVE_HPP_
#define SRC_EPI_CHAPTER7_REPLACEANDREMOVE_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter7 {

    class ReplaceAndRemove : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        ReplaceAndRemove():
            Solution("EPI Chapter 7.4",
                     "Replace 'a' with 2 'd', and remove 'b'",
                     "First pass remove 'b' and count final length, second pass replace 'a'") { }

        bool test();

        ~ReplaceAndRemove() { }

        int replaceAndRemove(int size, char s[]);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_REPLACEANDREMOVE_HPP_ */
