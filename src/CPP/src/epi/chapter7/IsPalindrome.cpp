#include "IsPalindrome.hpp"

#include <string>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

namespace epi {
  namespace chapter7 {
        bool IsPalindrome::isPalindrome(const string &s) {
            string::const_iterator b = s.begin(), e = s.end() - 1;

            while (b < e) {
                if ( !isalnum(*b) )
                    ++b;
                else if ( !isalnum(*e) )
                    --e;
                else if ( tolower(*b) == tolower(*e) ) {
                    ++b;
                    --e;
                } else {
                    return false; // *b != *e
                }
            }

            return true;
        }

        bool IsPalindrome::test() {
            vector<string> trueTestcases = {
                    "",
                    "A man, a plan, a canal, Panama.",
                    "Able was I, ere I saw Elba!"
            };

            vector<string> falseTestcases = {
                    "Ray a Ray"
            };

            for (string s : trueTestcases) {
                if ( !isPalindrome(s) ) {
                    cout << s << " should be palindrome" << endl;
                    return false;
                }
            }

            for (string s : falseTestcases) {
                if ( isPalindrome(s) ) {
                    cout << s << " should not be palindrome" << endl;
                    return false;
                }
            }

            return true;
        }

  } // chapter7
} // epi
