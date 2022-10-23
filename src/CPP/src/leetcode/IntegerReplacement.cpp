/*
 * [Source] https://leetcode.com/problems/integer-replacement/
 * [Difficulty]: Medium
 * [Tag]: Math
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>

using namespace std;

// [Solution]: Use vector as DP
// [Corner Case]:
class SolutionOutOfMem {
public:
    int integerReplacement(int n) {
        if (n <= 1)
            return 0;

        // Make sure the vector is always even length
        vector<int> steps( (n / 2 + n % 2) * 2, INT_MAX);
        steps[0] = 0;
        steps[1] = 1;
        
        int i = 0;
        while (i < (int)steps.size()) {
            int num = i + 1;
            if (num % 2 == 0) {
                steps[i] = steps[num / 2 - 1] + 1;
                --i;
            } else {
                // odd number jumps to next next even number. But need start from number 1, otherwise 4 is not updated
                steps[i] = i == 0 ? 0 : 1 + min(steps[i - 1], steps[i + 1]);
                i += 3;
            }
        }

        return steps[n - 1];
    }
};

// [Solution]: Use hash map. Since not every number smaller than n is involved, it save some spaces
class Solution {
public:
    int integerReplacement(int n) {
        if (n <= 1)
            return 0;

        unordered_map<long, int> numStepsMap;
        return helper((long)n, numStepsMap);
    }

    int helper(long n, unordered_map<long, int> &numStepsMap) {
        if (n <= 1)
            return 0;
        if (numStepsMap.find(n) != numStepsMap.end())
            return numStepsMap[n];

        int res;
        if (n % 2 == 0) {
            res = 1 + helper(n / 2, numStepsMap);
        } else {
            res = 1 + min( helper(n - 1, numStepsMap), helper(n + 1, numStepsMap) );
        }

        numStepsMap[n] = res;
        return res;
    }
};

// [Solution]: If an odd number + 1 equals to multiple of 4, then add 1, otherwise minus one. It is because divide 2 equals shift right. If an odd number becomes multiple of 4, it can shift twice. After 3 it is always no expensiver than minus 1.

int main() {
    Solution sol;

    cout << sol.integerReplacement(7) << endl;
    cout << sol.integerReplacement(2147483647) << endl;

    return 0;
}
