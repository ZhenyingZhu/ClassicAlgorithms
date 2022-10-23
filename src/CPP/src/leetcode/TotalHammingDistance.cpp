/*
 * [Source] https://leetcode.com/problems/total-hamming-distance/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulation
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Count number of 1s and 0s on each bit.
// [Corner Case]:
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> bitZeroCnt(32, 0);
        vector<int> bitOneCnt(32, 0);

        int dis = 0;
        for (int &num : nums) { // to save space, can do it for each bit first, then traverse the number
            // does sign bit also shiftable
            for (int i = 0; i < 32; ++i) {
                if ( ((num >> i) & 1) == 1 ) {
                    dis += bitZeroCnt[i];
                    ++bitOneCnt[i];
                } else {
                    dis += bitOneCnt[i];
                    ++bitZeroCnt[i];
                }
            }
        }

for (int &cnt : bitOneCnt) cout << cnt; cout << endl;
        return dis;
    }
};

// [Solution]:
/* Java solution

 */

int main() {
    Solution sol;
    //vector<int> nums = {-1, 0};
    vector<int> nums = {4,14,2};
    cout << sol.totalHammingDistance(nums) << endl;

    return 0;
}
