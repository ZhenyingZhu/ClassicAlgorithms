/*
 * [Source] https://leetcode.com/problems/add-strings/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

// [Solution]: Reverse to make compute easier
// [Corner Case]:
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.length() == 0 || num1 == "0")
            return num2;
        if (num2.length() == 0 || num2 == "0")
            return num1;

        if (num1.length() > num2.length())
            swap(num1, num2);
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        vector<char> res;
        res.reserve(num2.length() + 1);
        int carry = 0;
        int idx = 0;
        for (; idx < (int)num1.length(); ++idx) {
            int a = num1[idx] - '0', b = num2[idx] - '0';
            int sum = a + b + carry;
            res.push_back( (sum) % 10 + '0' );
            carry = sum / 10;
        }
        for (; idx < (int)num2.length(); ++idx) {
            int b = num2[idx] - '0';
            int sum = b + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        if (carry != 0)
            res.push_back(carry + '0');

        return string(res.rbegin(), res.rend());
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    cout << sol.addStrings("123", "987") << endl;

    return 0;
}
