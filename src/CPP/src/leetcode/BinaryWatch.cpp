/*
 * [Source] https://leetcode.com/problems/binary-watch/
 * [Difficulty]: Easy
 * [Tag]: Backtracking
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<int> digits;
        vector<string> res;
        helper(num, digits, res);
        return res;
    }

    void helper(int digitLeft, vector<int> &digits, vector<string> &res) {
        if (digits.size() == 10) {
            if (digitLeft > 0)
                return;

            string time = getString(digits);
            if (time != "")
                res.push_back(time);
            return;
        }

        digits.push_back(0);
        helper(digitLeft, digits, res);
        if (digitLeft > 0) {
            digits.back() = 1;
            helper(digitLeft - 1, digits, res);
        }
        digits.pop_back();
    }

    string getString(vector<int> &digits) {
        int i = 0;
        int hour = 0;
        for (; i < 4; ++i) {
            hour = hour * 2 + digits[i];
        }
        if (hour > 11)
            return "";

        int miniute = 0;
        for (; i < 10; ++i) {
            miniute = miniute * 2 + digits[i];
        }
        if (miniute > 59)
            return "";

        return to_string(hour) + ":" + (miniute >= 10 ? to_string(miniute) : ("0" + to_string(miniute)));
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    for (string &time : sol.readBinaryWatch(1)) {
        cout << time << " ";
    }
    cout << endl;

    return 0;
}
