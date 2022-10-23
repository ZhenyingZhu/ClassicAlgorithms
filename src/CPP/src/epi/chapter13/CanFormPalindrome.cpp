#include "CanFormPalindrome.hpp"

#include <string>
#include <unordered_map>
#include <iostream>

using std::string;
using std::unordered_map;
using std::cout;
using std::endl;

namespace epi {
  namespace chapter13 {
    bool CanFormPalindrome::canFormPalindrome(const string &s) {
        unordered_map<char, size_t> charCnts;
        for (char c : s) {
            ++charCnts[c];
        }

        int oddCharNum = 0;
        for (const auto &p : charCnts) {
            if ( (p.second % 2) && ++oddCharNum > 1)
                return false;
        }

        return true;
    }

    bool CanFormPalindrome::test() {
        string str1("abcd");
        if (canFormPalindrome(str1)) {
            cout << str1 << " cannot form palindrome" << endl;
            cout << "Result can" << endl;
            return false;
        }

        string str2("edified");
        if (!canFormPalindrome(str2)) {
            cout << str2 << " can form palindrome" << endl;
            cout << "Result cannot" << endl;
            return false;
        }

        return true;
    }

  } // chapter13
} // epi
