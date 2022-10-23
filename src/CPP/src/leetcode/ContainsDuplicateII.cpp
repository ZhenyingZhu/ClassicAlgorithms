/*
 * [Source] https://leetcode.com/problems/contains-duplicate-ii/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Hash Table
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Solution]: Sliding window
// [Corner Case]:
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0)
            return false;

        if (k > size - 1)
            k = size - 1;

        unordered_set<int> set;
        for (int i = 0; i < k; ++i) {
            if (set.find(nums[i]) != set.end())
                return true;
            set.insert(nums[i]);
        }

        int st = 0, ed = k;
        for (; ed < size; ++ed, ++st) {
            if (set.find(nums[ed]) != set.end())
                return true;
            set.insert(nums[ed]);
            set.erase(nums[st]);
        }

        return false;
    }
};

// [Solution]: Hash number and index

int main() {
    Solution sol;

    //vector<int> nums = {1, 2, 3, 1};
    vector<int> nums;
    cout << (sol.containsNearbyDuplicate(nums, 0) ? "True " : "False ") << endl;

    return 0;
}
