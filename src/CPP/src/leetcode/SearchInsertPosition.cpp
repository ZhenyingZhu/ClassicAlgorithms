/*
 * [Source] https://leetcode.com/problems/search-insert-position/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Find the first smaller value
// [Corner Case]: The first value is still larger than target
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SearchInsertPosition.java
 */

/* Java solution
public class Solution {
    public int searchInsert(int[] A, int target) {
        if (A == null || A.length <= 0) {
            return 0;
        }
        int st = 0; 
        int ed = A.length - 1;
        int prev = A.length; 
        int md; 
        while (st <= ed) {
            md = (st + ed) / 2;
            if (target == A[md]) {
                return md; 
            } else if (target > A[md]) {
                st = md + 1; 
            } else { // target < A[md]
                prev = md; 
                ed = md - 1; 
            }
        }
        return prev; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
