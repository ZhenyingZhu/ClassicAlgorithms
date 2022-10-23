#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        int len = nums.size();
        for (int i = 0; i < len; ++i) {
            int cur = nums[i];
            while (cur != i + 1 && cur > 0 && cur <= len && nums[cur - 1] != cur) {
                swap(nums[i], nums[cur - 1]);
                cur = nums[i];
            }
        }

        for (int i = 0; i < len; ++i) {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return len + 1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,3,2};
    cout << sol.firstMissingPositive(nums) << endl;

    return 0;
}
