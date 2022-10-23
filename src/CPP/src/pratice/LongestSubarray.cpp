#include <iostream>
#include <vector>

using namespace std;

// [Source]: http://www.1point3acres.com/bbs/thread-225639-1-1.html

class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        if (nums.empty())
            return 0;

        int maxLen = 0;
        int cnt = 1;
        for (int i = 1; i < (int)nums.size(); ++i) {
            if (nums[i] == nums[i - 1] + 1) {
                ++cnt;
            } else {
                maxLen = max(maxLen, cnt);
                cnt = 1;
            }
        }
        maxLen = max(maxLen, cnt);
        return maxLen;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 4, 1,2,3,4,5,3};
    cout << sol.longestSubarray(nums) << endl;

    return 0;
}
