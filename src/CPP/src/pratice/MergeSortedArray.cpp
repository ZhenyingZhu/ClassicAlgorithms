#include <iostream>
#include <vector>

using namespace std;

// [Source]: https://leetcode.com/problems/merge-sorted-array/
// http://www.1point3acres.com/bbs/thread-227329-1-1.html

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int pt1 = m - 1, pt2 = n - 1, pt = m + n - 1;
        while (pt1 >= 0 && pt2 >= 0) {
            if (nums1[pt1] > nums2[pt2]) {
                nums1[pt--] = nums1[pt1--];
            } else {
                nums1[pt--] = nums2[pt2--];
            }
        }
        while (pt2 >= 0)
            nums1[pt--] = nums2[pt2--];
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {0, 1, 3, 4, -1, -1, -1, -1};
    vector<int> nums2 = {2, 5, 6};

    sol.merge(nums1, 4, nums2, 3);
    for (int &num : nums1)
        cout << num << " ";
    cout << endl;

    return 0;
}
