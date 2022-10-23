/*
 * [Source] https://leetcode.com/problems/missing-ranges/
 * [Difficulty]: Medium
 * [Tag]: Arrays
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// [Solution]: Use a start, an end to store ranges. Start update after insert ranges, and end update before.
// [Corner Case]: Integer overflow
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;

        long rangeSt = lower, rangeEd;
        for (int i = 0; i < (int)nums.size(); ++i) {
            long cur = nums[i];
            rangeEd = cur - 1;
            insertRes(rangeSt, rangeEd, res);

            rangeSt = cur + 1;
        }
        insertRes(rangeSt, upper, res);
        return res;
    }

    void insertRes(long st, long ed, vector<string> &res) {
        if (ed < st)
            return;
        else if (ed == st)
            res.push_back(to_string(st));
        else
            res.push_back(to_string(st) + "->" + to_string(ed));
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 3, 50, 75};
    for (string &s : sol.findMissingRanges(nums, 0, 99))
        cout << s << " ";
    cout << endl;

    return 0;
}
