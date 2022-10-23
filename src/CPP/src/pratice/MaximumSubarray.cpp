#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// [Source]: https://leetcode.com/problems/maximum-subarray/#/description
// http://www.1point3acres.com/bbs/thread-258831-1-1.html

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalSum = INT_MIN, localSum = 0;
        int st = 0;
        vector<int> maxRange = {0, 0};
        for (int i = 0; i < (int)nums.size(); i++) {
            localSum += nums[i];
            if (localSum > globalSum) {
                maxRange[0] = st;
                maxRange[1] = i;
                globalSum = localSum;
            }

            if (localSum < 0) {
                st = i + 1;
                localSum = 0;
            }
        }

        cout << maxRange[0] << "->" << maxRange[1] << endl;
        return globalSum;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {-1, 1, 2, -1, 3,-10,11};
    cout << sol.maxSubArray(nums) << endl;

    return 0;
}
