/*
 * [Source] https://leetcode.com/problems/summary-ranges/
 * [Difficulty]: Medium
 * [Tag]: Array
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// [Solution]: How could it be medium?!
// [Corner Case]:
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int size = nums.size();
        if (size == 0)
            return res;

        int pre = nums[0], st = pre;
        for (int i = 1; i < size; ++i) {
            int cur = nums[i];
            if (cur > pre + 1) {
                res.push_back(toString(st, pre));
                st = cur;
            }
            pre = cur;
        }
        res.push_back(toString(st, pre));
        return res;
    }

    string toString(int st, int ed) {
        if (st == ed)
            return to_string(st);
        return to_string(st) + "->" + to_string(ed);
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 2, 4, 5, 7};
    for (string& s : sol.summaryRanges(nums))
        cout << s << " ";
    cout << endl;

    return 0;
}
