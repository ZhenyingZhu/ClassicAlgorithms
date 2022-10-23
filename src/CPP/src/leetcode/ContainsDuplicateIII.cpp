/*
 * [Source] https://leetcode.com/problems/contains-duplicate-iii/
 * [Difficulty]: Medium
 * [Tag]: Binary Search Tree
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <climits>

using namespace std;

// [Corner Case]:
class Solution {
public:
// [Solution]: Scan previous k elements.
// [Solution]: Scan hash map cur-t to cur+t. Both solution will timeout
    bool containsNearbyAlmostDuplicateTimeout(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if (size == 0 || k == 0)
            return false;

        unordered_map<int, int> map;
        for (int i = 0; i < size; ++i) {
            int cur = nums[i];
            for (int ran = cur - t; ran <= cur + t; ++ran) {
                if (map.find(ran) != map.end() && i - map[ran] <= k)
                    return true;
            }
            map[cur] = i;
        }
        return false;
    }

// [Solution]: Use map which is an ordered hash table.
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if (size == 0 || k == 0)
            return false;

        map<long, int> preNums;
        int st = 0;
        for (int i = 0; i < size; ++i) {
            if (i - st > k && preNums[nums[st]] == st)
                preNums.erase(nums[st]);
            long cur = (long)nums[i];
            map<long, int>::iterator it = preNums.lower_bound(cur - (long)t);
            for (; it != preNums.end() && it->first <= cur + (long)t; ++it) {
                if ( i - it->second <= k )
                    return true;
            }
            preNums[cur] = i; // overwrite same values idx with the later one
        }

        return false;
    }
};

int main() {
    Solution sol;

    //vector<int> nums = {1, 3, 5, 7, 9, 4};
    vector<int> nums = {0, INT_MAX};
    cout << (sol.containsNearbyAlmostDuplicate(nums, 1, INT_MAX) ? "True" : "False") << endl;

    return 0;
}
