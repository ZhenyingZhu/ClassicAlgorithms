/*
 * [Source] https://leetcode.com/problems/find-permutation/
 * [Difficulty]: Medium
 * [Tag]: Greedy
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: When descring, keep searching, if increasing, constucte previous vector in descring order, so that the result is in lexicographically order
// [Corner Case]:
class Solution {
public:
    vector<int> findPermutation(string s) {
        if (s.empty())
            return {1};

        int len = s.length();
        vector<int> res(len + 1);
        res[0] = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] == 'D')
                res[i + 1] = res[i] - 1;
            else
                res[i + 1] = res[i] + 1;
        }

        helper(res, 0, len, 1); // make it complicated. Should use s directly
        return res;
    }

    void helper(vector<int> &res, int st, int ed, int lowNum) {
        if (st == ed) {
            res[st] = lowNum;
            return;
        }
        if (st > ed)
            return;

        int minIdx = st;
        for (int i = st + 1; i <= ed; ++i) {
            if (res[i] < res[i - 1]) { // if several cells have same number, let lsb become the partition place
                minIdx = i;
            } else {
                break;
            }
        }
        res[minIdx] = lowNum;
        helper(res, st, minIdx - 1, lowNum + 1);
        helper(res, minIdx + 1, ed, (lowNum + 1) + (minIdx - st));
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    //for (int &num : sol.findPermutation("D"))
    //for (int &num : sol.findPermutation("DI"))
    for (int &num : sol.findPermutation("DDDDIIIIIIDDDDDDDD"))
        cout << num << " ";
    cout << endl;

    return 0;
}
