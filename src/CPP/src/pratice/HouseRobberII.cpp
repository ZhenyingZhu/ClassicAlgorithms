#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/house-robber-ii/
// http://www.1point3acres.com/bbs/thread-218632-1-1.html

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty())
            return 0;
        int size = nums.size();
        if (size == 1) // when only one element, robFirst[1] doesn't exist
            return nums[0];

        vector<int> robFirst(size, 0);
        robFirst[1] = nums[0];
        for (int i = 1; i < size - 1; ++i) // the last one cannot rob
            robFirst[i + 1] = max(nums[i] + robFirst[i - 1], robFirst[i]);

        vector<int> notRobFirst(size + 1, 0);
        for (int i = 1; i < size; ++i)
            notRobFirst[i + 1] = max(nums[i] + notRobFirst[i - 1], notRobFirst[i]);

        return max(robFirst.back(), notRobFirst.back());
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1};
    cout << sol.rob(nums) << endl;

    return 0;
}
