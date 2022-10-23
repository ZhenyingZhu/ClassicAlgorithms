/*
 * [Source] https://leetcode.com/problems/next-greater-element-ii
 * [Difficulty]: Medium
 * [Tag]: Stack
 */

#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// [Solution]:
// [Corner Case]:
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> nexts;
        vector<int> res(nums.size());
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            while (!nexts.empty() && nexts.top() <= nums[i]) {
                nexts.pop();
            }

            if (nexts.empty()) {
                res[i] = -1;
            } else {
                res[i] = nexts.top();
            }
            nexts.push(nums[i]);
        }

        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            while (!nexts.empty() && nexts.top() <= nums[i])
                nexts.pop();

            if (nexts.empty())
                break;

            res[i] = nexts.top();
            nexts.push(nums[i]);
        }

        return res;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1,3,4,2};
    vector<int> nums = {3,-2,-1};
    for (int &idx : sol.nextGreaterElements(nums))
        cout << idx << ", ";
    cout << endl;

    return 0;
}
