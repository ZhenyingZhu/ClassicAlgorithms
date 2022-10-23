/*
 * [Source] https://leetcode.com/problems/rotate-function/
 * [Difficulty]: Easy
 * [Tag]: Math
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Find a diff between each rotate
// [Corner Case]:
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        if (A.empty())
            return 0;
        int len = A.size();

        int firstF = 0, totalSum = 0;
        for (int i = 0; i < (int)A.size(); ++i) {
            firstF += i * A[i];
            totalSum += A[i];
        }

        int maxVal = firstF, curVal = firstF;
        for (int i = 1; i < len; ++i) {
            curVal += totalSum - len * A[len - i];
cout << curVal << endl;
            maxVal = max(maxVal, curVal);
        }

        return maxVal;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> A = {4, 3, 2, 6};
    cout << sol.maxRotateFunction(A) << endl;

    return 0;
}
