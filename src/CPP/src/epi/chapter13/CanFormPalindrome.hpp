#ifndef SRC_EPI_CHAPTER13_CANFORMPALINDROME_HPP_
#define SRC_EPI_CHAPTER13_CANFORMPALINDROME_HPP_

#include "../../Solution.h"

#include <string>

namespace epi {
  namespace chapter13 {
    class CanFormPalindrome : public myutils::Solution {
    public:
        CanFormPalindrome():
            Solution("EPI Chapter 13.1",
                     "Test for palindromic permutations",
                     "Check if all chars are show in pairs except one.") { }

        ~CanFormPalindrome() { }

        bool canFormPalindrome(const std::string &s);

        bool test();

    };

  } // chapter13
} // epi

#endif /* SRC_EPI_CHAPTER13_CANFORMPALINDROME_HPP_ */
