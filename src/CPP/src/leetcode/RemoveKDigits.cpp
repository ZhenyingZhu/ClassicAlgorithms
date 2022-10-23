/*
 * [Source] https://leetcode.com/problems/remove-k-digits/
 * [Difficulty]: Medium
 * [Tag]: Stack
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

// [Solution]: When a number shows up, place it to the next position of a number that is just smaller or equal to it
// [Corner Case]: When the index is larger than the array, or when the index is too small that numbers left cannot fill the result
class Solution {
public:
    string removeKdigits(string num, int k) {
        int len = num.length() - k;
        if (len <= 0)
            return "0";
        if (k == 0)
            return num;

        vector<int> digits(len);
        int idx = -1;
        for (int i = 0; i < (int)num.length(); ++i) {
            int digit = num[i] - '0';
            int numberLeft = num.length() - i - 1;
            if (len - idx - 1 >= numberLeft + 1) {
                // not enough digits
                digits[++idx] = digit;
            } else {
                int pos = binarySearch(digits, idx, digit);
                if (pos >= len)
                    continue;
                // if the pos is too behind, numbers will not enough
                if (len - pos - 1 >= numberLeft)
                    pos = len - numberLeft - 1;
                digits[pos] = digit;
                idx = pos;
            }
        }
        return getString(digits);
    }

    int binarySearch(vector<int> &nums, int ed, int target) {
        // find the next cell of the number that is smaller or equal to target
        if (ed == -1)
            return 0;

        int st = 0;
        while (st + 1 < ed) {
            int md = st + (ed - st) / 2;
            if (nums[md] <= target) {
                st = md;
            } else {
                ed = md;
            }
        }

        if (nums[ed] <= target)
            return ed + 1;
        if (nums[st] <= target)
            return st + 1;
        return 0;
    }

    string getString(vector<int> &digits) {
        vector<char> res;
        bool leading = true;
        for (int i = 0; i < (int)digits.size(); ++i) {
            int digit = digits[i];
            if (leading && digit == 0)
                continue;
            leading = false;
            res.push_back('0' + digit);
        }

        if (res.size() == 0)
            return "0";
        return string(res.begin(), res.end());
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    /*
    cout << sol.removeKdigits("1432219", 3) << endl;
    cout << sol.removeKdigits("10200", 1) << endl;
    cout << sol.removeKdigits("10", 2) << endl;
    */
    cout << sol.removeKdigits("1111111", 3) << endl;

    return 0;
}
