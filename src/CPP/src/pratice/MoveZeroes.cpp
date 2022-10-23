#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/move-zeroes/?tab=Description#/description
// http://www.1point3acres.com/bbs/thread-227472-1-1.html

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int pt = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] != 0)
                swap(nums[i], nums[pt++]);
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {0, 1, 2, 0, 3, 0, 0};
    sol.moveZeroes(nums);
    for (int &num : nums)
        cout << num << ", ";
    cout << endl;

    return 0;
}
