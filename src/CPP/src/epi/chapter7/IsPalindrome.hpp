#ifndef SRC_EPI_CHAPTER7_ISPALINDROME_HPP_
#define SRC_EPI_CHAPTER7_ISPALINDROME_HPP_

#include <string>

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
  namespace chapter7 {

    class IsPalindrome : public myutils::Solution {
        friend class myutils::SmartPtr;

    public:
        IsPalindrome():
            Solution("EPI Chapter 7.5",
                     "Test palindromicify ignoring case and special characters",
                     "Two pointers from beginning and ending") { }

        bool test();

        ~IsPalindrome() { }

        bool isPalindrome(const std::string&);
    };

  } // chapter7
} // epi

#endif /* SRC_EPI_CHAPTER7_ISPALINDROME_HPP_ */
