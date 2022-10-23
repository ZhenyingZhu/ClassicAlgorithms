/*
 * [Source] https://leetcode.com/problems/median-of-two-sorted-arrays/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Array
 * [Tag]: Divide and Conquer
 */

#include <iostream>
#include <vector>
#include <exception>

using namespace std;

// [Solution]: The median must between(include) the medians of first array and the second array. So each time can abandom the part before the smaller median and the part after the larger median?
// [Corner Case]: The array is even length. Two medians are same.

// [Solution]: Convert the question to findout the kth element of the combination of two arrays. Compare the k/2 th elements of each array, and get rid of the first half of k/2 elements each time.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        if (len % 2 == 0) {
            int leftMid = findKthNum(nums1, nums2, 0, 0, len / 2);
            int rightMid = findKthNum(nums1, nums2, 0, 0, len / 2 + 1);
            return (double)(leftMid + rightMid) / 2;
        } else {
            return (double)findKthNum(nums1, nums2, 0, 0, len / 2 + 1);
        }
    }

private:
    int findKthNum(vector<int>& nums1, vector<int>& nums2, int st1, int st2, int k) {
        if (st1 == nums1.size()) {
            return nums2[st2 + k - 1];
        }

        if (st2 == nums2.size()) {
            return nums1[st1 + k - 1];
        }

        if (k == 1) {
            return nums1[st1] < nums2[st2] ? nums1[st1] : nums2[st2];
        }

        int md = k / 2 - 1;
        if (st1 + md >= nums1.size()) {
            return findKthNum(nums1, nums2, st1, st2 + md + 1, k - md - 1);
        }

        if (st2 + md >= nums2.size()) {
            return findKthNum(nums1, nums2, st1 + md + 1, st2, k - md - 1);
        }

        if (nums1[st1 + md] < nums2[st2 + md]) {
            return findKthNum(nums1, nums2, st1 + md + 1, st2, k - md - 1);
        } else {
            return findKthNum(nums1, nums2, st1, st2 + md + 1, k - md - 1);
        }
    }
};

/* Java solution
public class Solution {
    public double findMedianSortedArrays(int A[], int B[]) {
        int len = A.length + B.length; 
        if (len == 0) {
            return 0; 
        }
        if (len % 2 == 1) {
            return (double)findKth(A, 0, B, 0, len / 2 + 1); 
        } else {
            return (double)(findKth(A, 0, B, 0, len / 2) + findKth(A, 0, B, 0, len / 2 + 1)) / 2.0; 
        }
    }
    
    private int findKth(int[] A, int st1, int[] B, int st2, int k) {
        if (st1 >= A.length) {
            return B[st2 + k - 1]; 
        }
        if (st2 >= B.length) {
            return A[st1 + k - 1]; 
        }
        if (k == 1) {
            return Math.min(A[st1], B[st2]); 
        }
        int Akey = st1 + k / 2 - 1 >= A.length ? Integer.MAX_VALUE : A[st1 + k / 2 - 1]; 
        int Bkey = st2 + k / 2 - 1 >= B.length ? Integer.MAX_VALUE : B[st2 + k / 2 - 1]; 
        if (Akey <= Bkey) {
            return findKth(A, st1 + k / 2, B, st2, k - k / 2); 
        } else {
            return findKth(A, st1, B, st2 + k / 2, k - k / 2); 
        }
    }
}
 */

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/MedianOfTwoSortedArrays.java
 */

int main() {
    Solution sol;

    vector<int> nums1 = {2};
    vector<int> nums2 = {1, 3, 4};

    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;

    vector<int> nums3 = {};
    vector<int> nums4 = {1, 2};

    cout << sol.findMedianSortedArrays(nums3, nums4) << endl;

    return 0;
}
