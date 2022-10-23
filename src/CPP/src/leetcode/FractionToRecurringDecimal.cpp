/*
 * [Source] https://leetcode.com/problems/fraction-to-recurring-decimal/
 * [Difficulty]: Medium
 * [Tag]: Hash Table
 * [Tag]: Math
 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

// [Solution]: First deal with integer part. Need print 0 at the end. Then use a hash map to store which number devide to which idx. To avoid INT_MIN get in the way, use long.
// [Corner Case]: Negative. INT_MIN
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        if ( (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0) )
            res += "-";
        vector<int> nums = convertNumeratorToPositiveVector(numerator);
        long den = abs(long(denominator));
        long left = 0;
        res += divideIntergerPart(nums, den, left);

        if (left == 0)
            return res;

        vector<char> fractionPart;
        unordered_map<long, size_t> map;
        while (left != 0) {
            if (map.find(left) != map.end())
                return res + "." + constructRepeat(fractionPart, map[left]);
            map[left] = fractionPart.size();
            fractionPart.push_back(left / den + '0');
            left = left % den * 10;
        }

        return res + "." + constructRepeat(fractionPart, fractionPart.size());
    }

private:
    vector<int> convertNumeratorToPositiveVector(int num) {
        int n = num < 0 ? -1 : 1;
        vector<int> s;
        while (num != 0) {
            s.push_back(num % 10 * n);
            num = num / 10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string divideIntergerPart(vector<int>& num, long den, long& left) {
        bool firstNonZeroApp = false;
        vector<char> res;
        for (int cur : num) {
            left += cur;
            int val = left / den;
            if (val == 0) {
                if (firstNonZeroApp)
                    res.push_back(val + '0');
            } else {
                res.push_back(val + '0');
                firstNonZeroApp = true;
            }
            left = left % den * 10;
        }
        if (res.empty())
            return "0";
        return string(res.begin(), res.end());
    }

    string constructRepeat(vector<char>& fractionPart, size_t loopIdx) {
        string res = string(fractionPart.begin(), fractionPart.begin() + loopIdx);
        if (loopIdx == fractionPart.size())
            return res;
        res += "(" + string(fractionPart.begin() + loopIdx, fractionPart.end()) + ")";
        return res;
    }
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/FractionToRecurringDecimal.java
 */

int main() {
    Solution sol;

    cout << sol.fractionToDecimal(-1, 2) << endl;
    cout << sol.fractionToDecimal(2, 7) << endl;
    cout << sol.fractionToDecimal(2, 13) << endl;
    cout << sol.fractionToDecimal(-2147483648, -1) << endl;
    cout << sol.fractionToDecimal(-1, -2147483648) << endl;
    cout << sol.fractionToDecimal(100, -1) << endl;
    cout << sol.fractionToDecimal(22, 7) << endl;

    return 0;
}
