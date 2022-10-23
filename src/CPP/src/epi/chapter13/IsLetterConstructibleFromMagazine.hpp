#ifndef SRC_EPI_CHAPTER13_ISLETTERCONSTRUCTIBLEFROMMAGAZINE_HPP_
#define SRC_EPI_CHAPTER13_ISLETTERCONSTRUCTIBLEFROMMAGAZINE_HPP_

#include "../../Solution.h"

#include <string>

namespace epi {
  namespace chapter13 {
    class IsLetterConstructibleFromMagazine : myutils::Solution {
    public:
        IsLetterConstructibleFromMagazine():
            Solution("EPI Chapter 13.2",
                     "Is an anonymous letter constructible",
                     "Hash the letter character counts. Iterate "
                     "the magazine, if all characters are "
                     "available, return true.") { }

        ~IsLetterConstructibleFromMagazine() { }

        bool isLetterConstructibleFromMagazine(const std::string &letter, const std::string &magazine);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_ISLETTERCONSTRUCTIBLEFROMMAGAZINE_HPP_ */
