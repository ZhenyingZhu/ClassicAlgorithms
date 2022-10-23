#include "IsPalindrome.hpp"

#include <iostream>
#include <cmath>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::to_string;

namespace epi {
namespace chapter5 {
    bool IsPalindrome::isPalindromeBruteForce(int x) {
        if (x < 0)
            return false;

        string num(to_string(x));

        for (string::iterator beg = num.begin(), end = --num.end();
                beg != end; ++beg, --end) {
            if (*beg != *end) {
                return false;
            }
        }

        return true;
    }

    bool IsPalindrome::isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;

        // for loop use this as an exit indicator
        const int kNumDigits = static_cast<int>( floor(log10(x)) ) + 1;
        int msd_mask = static_cast<int>( pow(10, kNumDigits - 1) );

        for (int i = 0; i != kNumDigits / 2; ++i) {
            if (x / msd_mask != x % 10)
                return false;
            else {
                x %= msd_mask;
                msd_mask /= 100;
                x /= 10;
            }
        }

        return true;
    }

    bool IsPalindrome::test() {
        const size_t arr_size = 4;
        int arr[arr_size] = { 214747412, 12, -111, 1 };
        for (size_t ix = 0; ix != arr_size; ++ix)
            if ( isPalindromeBruteForce(arr[ix]) ^ isPalindrome(arr[ix]) ) {
                cout << arr[ix] << " is " << (isPalindrome(arr[ix]) ? "" : "not ") << "palindrome. " << endl;
                return false;
            }

        return true;
    }
} // chapter5
} // epi
