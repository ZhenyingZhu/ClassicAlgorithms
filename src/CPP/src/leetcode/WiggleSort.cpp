/*
 * [Source] https://leetcode.com/problems/wiggle-sort/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Sort first. Then swap every two numbers.
// [Corner Case]:
class SolutionSort {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int st = 1; st + 1 < (int)nums.size(); st += 2) {
            swap(nums[st], nums[st + 1]);
        }
    }
};

// [Solution]: As swap numbers does change previous order
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        for (int i = 1; i < (int)nums.size(); ++i) {
            if ( (i % 2 == 0 && nums[i] > nums[i - 1]) ||
                 (i % 2 == 1 && nums[i] < nums[i - 1]) )
                swap(nums[i], nums[i - 1]);
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 5, 2, 1, 6, 4};
    sol.wiggleSort(nums);
    for (int &n : nums)
        cout << n << " ";
    cout << endl;

    return 0;
}
