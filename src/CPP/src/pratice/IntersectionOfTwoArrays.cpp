#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// [Source]: https://leetcode.com/problems/intersection-of-two-arrays/
// http://www.1point3acres.com/bbs/thread-225075-1-1.html

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        vector<int> res;
        for (int &num : nums2) {
            if (set.count(num)) {
                res.push_back(num);
                set.erase(num);
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    for (int &n : sol.intersection(nums1, nums2))
        cout << n << " ";
    cout << endl;

    return 0;
}
