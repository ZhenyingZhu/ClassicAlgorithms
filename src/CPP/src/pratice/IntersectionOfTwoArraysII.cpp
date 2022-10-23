#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [Source]: https://leetcode.com/problems/intersection-of-two-arrays-ii/
// http://www.1point3acres.com/bbs/thread-225075-1-1.html

class Solution {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> res;
        int pt1 = 0, pt2 = 0;
        while (pt1 < (int)nums1.size() && pt2 < (int)nums2.size()) {
            if (nums1[pt1] == nums2[pt2]) {
                res.push_back(nums1[pt1]);
                ++pt1;
                ++pt2;
            } else if (nums1[pt1] > nums2[pt2]) {
                ++pt2;
            } else {
                ++pt1;
            }
        }
        return res;
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {1,2,2,1}, nums2 = {2,2};
    for (int &n : sol.intersect(nums1, nums2))
        cout << n << " ";
    cout << endl;

    return 0;
}
