/*
 * [Source] https://leetcode.com/problems/random-pick-index/
 * [Difficulty]: Medium
 * [Tag]: Reservior Sampling
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Reservior Sampling where k is 1.
// [Corner Case]:
class Solution {
public:
    Solution(vector<int> nums): nums_(nums) {
    }

    int pick(int target) {
        int cnt = 0;
        int idx = -1;
        for (int i = 0; i < (int)nums_.size(); ++i) {
            if (nums_[i] == target) {
                ++cnt;
                if (rand() % cnt == 0)
                    idx = i;
            }
        }
        return idx;
    }

private:
    vector<int> nums_;
};

// [Solution]:
/* Java solution

 */

int main() {
    vector<int> nums = {1,2,3,3,3};
    Solution sol(nums);

    cout << sol.pick(3) << endl;
    cout << sol.pick(3) << endl;
    cout << sol.pick(3) << endl;

    return 0;
}
