/*
 * [Source] https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
 * [Difficulty]: Medium
 * [Tag]: Bit Manipulate
 * [Tag]: Trie
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Solution]: Try to construct the result by checking from the highest bit
// [Corner Case]:
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;

        // 0 ≤ num < 2^31, so in total 31 bits.
        int mask = 0;
        for (int bit = 30; bit >= 0; --bit) {
            // create prefix set for previous 32 to bit bits
            unordered_set<int> prefixSet;
            mask |= 1 << bit;
            for (int &num : nums) {
                prefixSet.insert(num & mask);
            }

            // each prefix present at least one number.
            // if prefix1 ^ prefix2 = target, then prefix1 ^ target = prefix2
            int target = res | (1 << bit);
            for (auto it = prefixSet.begin(); it != prefixSet.end(); ++it) {
                int prefix = *it;
                if (prefixSet.count(target ^ prefix)) {
                    res = target;
                    break;
                }
            }
        }
        return res;
    }
};

// [Solution]: Use Trie tree to store each number
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums = {3, 10, 5, 25, 2, 8};
    cout << sol.findMaximumXOR(nums) << endl;

    return 0;
}
