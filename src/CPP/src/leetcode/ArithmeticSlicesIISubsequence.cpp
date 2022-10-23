/*
 * [Source] https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
 * [Difficulty]: Hard
 * [Tag]: Dynamic Programming
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// [Solution]: See in line comment. TLE because C++ unordered_map init when call operator[].
// [Corner Case]:
class SolutionTLE {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        // diffMaps[i] store the number of slices that end with num[i] + diff. So when num[j] = num[i] + diff, res += diffMaps[i][diff]
        vector<unordered_map<long, int>> diffMaps(A.size());
        for (int i = 1; i < (int)A.size(); ++i) {
            diffMaps[i].reserve(1000);
            for (int j = 0; j < i; ++j) {
                long diff = (long)A[i] - (long)A[j];
                unordered_map<long, int> &diffMap = diffMaps[j];
                int cnt = diffMap[diff];
                res += cnt;
                // there could be two pathes has same diff, 2 2 1 0, so need add times together, when compute -1 of, 2 2 1 0 -1, 0 should contains both path
                diffMaps[i][diff] = diffMaps[i][diff] + cnt + 1;
            }
        }
        return res;
    }
};

// [Solution]: Less the insert of unordered_map by precheck.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
        vector<unordered_map<long, int>> diffMaps(A.size());
        unordered_set<int> set(A.begin(), A.end());
        for (int i = 1; i < (int)A.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)A[i] - (long)A[j];
                int cnt = 0;
                if (diffMaps[j].count(diff)) {
                    cnt = diffMaps[j][diff];
                    res += cnt;
                }
                if (set.count(A[i] + diff)) {
                    diffMaps[i][diff] += cnt + 1;
                }
            }
        }
        return res;
    }
};
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> A = {2, 4, 6, 3, 2, 1, 0};
    cout << sol.numberOfArithmeticSlices(A) << endl;

    return 0;
}
