/*
 * [Source] https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 * [Difficulty]: Easy
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <string>
#include <climits>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        long n = num;
        if (num < 0) {
            n = (1L << 32) + num; // two's complement
        }

        string digits = "0123456789abcdef";
        vector<char> res;
        while (n > 0) {
            long digit = n % 16;
            res.push_back(digits[digit]);
            n /= 16;
        }

        return string(res.rbegin(), res.rend());
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> testcases = {26, -1};
    for (int &num : testcases)
        cout << num << ": " << sol.toHex(num) << endl;

    return 0;
}
