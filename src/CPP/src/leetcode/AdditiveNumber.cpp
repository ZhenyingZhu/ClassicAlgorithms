/*
 * [Source] https://leetcode.com/problems/additive-number/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: DFS. When third number is larger than first + second, can stop.
// [Corner Case]:
class Solution {
public:
    size_t int_len = 10;

    bool isAdditiveNumber(string num) {
        if (num.length() < 3)
            return false;

        for (size_t i = 1; i <= int_len && i <= num.length() - 2; ++i) {
            if (num[0] == '0' && i > 1)
                break;

            long first = stol(num.substr(0, i));
            for (size_t j = 1; j <= int_len && i + j <= num.length() - 1; ++j) {
                if (num[i] == '0' && j > 1)
                    break;

                long second = stol(num.substr(i, j));
                if ( helper(num.substr(i + j), first, second) )
                    return true;
            }
        }
        return false;
    }

    bool helper(string num, long first, long second) {
        if (num == "")
            return true;

        for (size_t i = 1; i <= int_len && i <= num.length(); ++i) {
            if (num[0] == '0' && i > 1)
                break;

            long third = stol(num.substr(0, i));
            if (third > first + second)
                break;

            if (first + second == third) {
                if ( helper(num.substr(i), second, third) )
                    return true;
            }
        }
        return false;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.isAdditiveNumber("123") << endl;
    cout << sol.isAdditiveNumber("112358") << endl;
    cout << sol.isAdditiveNumber("199100199") << endl;

    return 0;
}
