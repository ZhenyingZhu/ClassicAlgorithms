#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// [Source]: https://leetcode.com/problems/fraction-to-recurring-decimal/?tab=Description
// http://www.1point3acres.com/bbs/thread-229745-1-1.html

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (denominator == 0)
            return "";
        if (numerator == 0)
            return "0";

        vector<char> res;
        long num = numerator, den = denominator;
        if (num * den < 0)
            res.push_back('-');
        num = abs(num);
        den = abs(den);

        long fraction = num / den;
        if (fraction == 0) {
            res.push_back('0');
        } else {
            size_t pos = res.size();
            while (fraction > 0) {
                res.push_back('0' + fraction % 10);
                fraction /= 10;
            }
            reverse(res.begin() + pos, res.end());
        }

        long remain = num % den;
        if (remain == 0) {
            return string(res.begin(), res.end());
        }
        res.push_back('.');

        unordered_map<long, int> numPos;
        while (remain > 0) {
            if (numPos.count(remain)) {
                res.insert(res.begin() + numPos[remain], '(');
                res.push_back(')');
                break;
            } else {
                numPos[remain] = res.size();
                remain *= 10;
                res.push_back('0' + remain / den);
                remain %= den;
            }
        }

        return string(res.begin(), res.end());
    }
};

int main() {
    Solution sol;

    cout << sol.fractionToDecimal(1010, 3) << endl;

    return 0;
}
