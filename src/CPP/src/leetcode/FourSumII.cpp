/*
 * [Source] https://leetcode.com/problems/4sum-ii/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Hash Table
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sumCnt;
        for (int i = 0; i < (int)A.size(); ++i) {
            for (int j = 0; j < (int)B.size(); ++j) {
                ++sumCnt[A[i] + B[j]];
            }
        }

        int res = 0;
        for (int m = 0; m < (int)C.size(); ++m) {
            for (int n = 0; n < (int)D.size(); ++n) {
                int target = - C[m] - D[n];
                if (sumCnt.count(target))
                    res += sumCnt[target];
            }
        }
        return res;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    vector<int> A = {1,2}, B = {-2,-1}, C = {-1,2}, D = {0,2};

    cout << sol.fourSumCount(A, B, C, D) << endl;

    return 0;
}
