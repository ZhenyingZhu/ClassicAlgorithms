/*
 * [Source] https://leetcode.com/problems/next-greater-element-i
 * [Difficulty]: Easy
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
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> num2NextGreater;
        stack<int> nexts;
        for (int i = (int)nums.size() - 1; i >= 0; --i) {
            while (!nexts.empty() && nexts.top() <= nums[i]) {
                nexts.pop();
            }

            if (nexts.empty()) {
                num2NextGreater[nums[i]] = -1;
            } else {
                num2NextGreater[nums[i]] = nexts.top();
            }
            nexts.push(nums[i]);
        }

        vector<int> res;
        for (int &num : findNums) {
            if (!num2NextGreater.count(num)) {
                res.push_back(-1);
            } else {
                res.push_back(num2NextGreater[num]);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {4,1,2}, nums2 = {1,3,4,2};
    for (int &idx : sol.nextGreaterElement(nums1, nums2))
        cout << idx << ", ";
    cout << endl;

    return 0;
}
