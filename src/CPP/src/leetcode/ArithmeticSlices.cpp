/*
 * [Source] https://leetcode.com/problems/arithmetic-slices/
 * [Difficulty]: Medium
 * [Tag]: Dynamic Programming
 * [Tag]: Math
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Pick three number from a length equals len-2+len-1+...+1
// [Corner Case]:
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int res = 0;

        int st = 0;
        int diff = A[1] - A[st];
        for (int i = 2; i < (int)A.size(); ++i) {
            if (A[i] - A[i - 1] != diff) {
                int ed = i - 1;
                res += sliceNumBetween(st, ed);
                st = i - 1;
                diff = A[i] - A[i - 1];
            }
        }

        res += sliceNumBetween(st, A.size() - 1);
        return res;
    }

    int sliceNumBetween(int st, int ed) {
        int len = ed - st + 1;
        if (len <= 2)
            return 0;
        int res = 0;
        // len = 5, then with length 5, there are 1, with length 3, there are 5 - 2
        for (int i = 1; i <= len - 2; ++i)
            res += i;
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //vector<int> A = {1, 2, 3, 4};
    vector<int> A = {1, 2, 3, 4, 6, 8, 9, 1, 2, 3};
    cout << sol.numberOfArithmeticSlices(A) << endl;

    return 0;
}
