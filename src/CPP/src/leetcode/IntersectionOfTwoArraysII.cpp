/*
 * [Source] https://leetcode.com/problems/intersection-of-two-arrays-ii/
 * [Difficulty]: Easy
 * [Tag]: Binary Search
 * [Tag]: Hash Table
 * [Tag]: Two Pointers
 * [Tag]: Sort
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Solution]: Sort first, then two pointers.
// [Corner Case]:
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty() || nums2.empty())
            return {};

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int idx1 = 0, idx2 = 0;
        while (idx1 < (int)nums1.size() && idx2 < (int)nums2.size()) {
            if (nums1[idx1] == nums2[idx2]) {
                res.push_back(nums1[idx1]);
                ++idx1;
                ++idx2;
            } else if (nums1[idx1] < nums2[idx2]) {
                ++idx1;
            } else {
                ++idx2;
            }
        }

        return res;
    }
};

// [Solution]: Create a hash set for larger size array. Use each number in the smaller size array as index to find it.
/* Java solution

 */

int main() {
    Solution sol;

    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};
    for (int &num : sol.intersection(nums1, nums2))
        cout << num << " ";
    cout << endl;

    return 0;
}
