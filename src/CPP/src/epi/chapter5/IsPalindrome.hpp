#ifndef SRC_EPI_CHAPTER5_ISPALINDROME_HPP_
#define SRC_EPI_CHAPTER5_ISPALINDROME_HPP_

#include "../../Solution.h"
#include "../../SmartPtr.h"

namespace epi {
namespace chapter5 {

class IsPalindrome : public myutils::Solution {
    friend class myutils::SmartPtr;

public:
    IsPalindrome():
        Solution("EPI Chapter 5.9",
                 "Check if a decimal integer is palindrome.",
                 "Negative integer cannot be palindrome.") { }

    bool test();

    ~IsPalindrome() { }

    bool isPalindromeBruteForce(int);

    bool isPalindrome(int);
};

} // chapter5
} // epi

#endif /* SRC_EPI_CHAPTER5_ISPALINDROME_HPP_ */
