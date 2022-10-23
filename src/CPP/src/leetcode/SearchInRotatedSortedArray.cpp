/*
 * [Source] https://leetcode.com/problems/search-in-rotated-sorted-array/
 * [Difficulty]: Hard
 * [Tag]: Binary Search
 * [Tag]: Array
 */

#include <iostream>
#include <vector>

using namespace std;

// [Solution]: Draw a graph, and see there are three cases to go left, but one case to go right. Find the reason why it go right.
// [Corner Case]: st or ed is the ans. md-1 exit the loop
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;

        int st = 0, ed = nums.size() - 1;
        while (st <= ed) {
            int md = st + (ed - st) / 2;
            if (target == nums[md])
                return md;

            if (target > nums[md]) {
                if (target >= nums[st] && nums[md] < nums[st]) {
                    ed = md - 1;
                } else {
                    st = md + 1;
                }
            } else {
                if (target <= nums[ed] && nums[ed] < nums[md]) {
                    st = md + 1;
                } else {
                    ed = md - 1;
                }
            }
        }

        return -1;
    }

};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SearchInRotatedSortedArray.java
 */

/* Java solution
public class Solution {
    public int search(int[] A, int target) {
        if (A == null || A.length <= 0) {
            return -1; 
        }
        return rotateBinarySearch(A, target, 0, A.length - 1); 
    }
    
    private int rotateBinarySearch(int[] A, int target, int st, int ed) {
        if(st > ed) {
            return -1;
        }
        int md = (st + ed) / 2; 
        if(A[md] == target) {
            return md; 
        }
        if(A[st] == target) {
            return st; 
        }
        if(A[ed] == target) {
            return ed; 
        }
        if(A[md] > target) {
            if(A[st] < A[md]) { // still may rotate to right
                if(A[st] < target) { 
                    return rotateBinarySearch(A, target, st, md - 1); 
                } else {
                    return rotateBinarySearch(A, target, md + 1, ed); 
                }
            } else { // rotate, but smaller part are all in left
                return rotateBinarySearch(A, target, st, md - 1); 
            }
        } else { // A[md] < target
            if(A[ed] > A[md]) { 
                if(A[ed] > target) {
                    return rotateBinarySearch(A, target, md + 1, ed); 
                } else {
                    return rotateBinarySearch(A, target, st, md - 1); 
                }
            } else {
                return rotateBinarySearch(A, target, md + 1, ed); 
            }
        }
    }
}
 */

int main() {
    Solution sol;

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    for (int i = 0; i <= 7; ++i) {
        cout << sol.search(arr, i) << endl;
    }

    return 0;
}
