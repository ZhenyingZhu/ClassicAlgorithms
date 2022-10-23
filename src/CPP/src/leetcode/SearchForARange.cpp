/*
 * [Source] https://leetcode.com/problems/search-for-a-range/
 * [Difficulty]: Medium
 * [Tag]: Binary Search
 * [Tag]: Array
 */

#include <iostream>

using namespace std;

// [Solution]: Binary search. When find the value, move left and right to find the range
// [Corner Case]:
class Solution {
};

// [Solution]: BS for the first value, then BS for the last value.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/SearchForARange.java
 */

// [Solution]: BS until cannot find
/* Java solution
public class Solution {
    public int[] searchRange(int[] A, int target) {
        int[] result = {-1, -1};
        if (A == null || A.length <= 0) {
            return result; 
        }
        int md = binarySearch(A, target, 0, A.length - 1); 
        if (md == -1) {
            return result;
        }
        result[0] = md; 
        result[1] = md; 
        int st = binarySearch(A, target, 0, md - 1);  
        while (st != -1) {
            result[0] = st; 
            st = binarySearch(A, target, 0, st - 1); 
        }
        int ed = binarySearch(A, target, md + 1, A.length - 1);
        while (ed != -1) {
            result[1] = ed; 
            ed = binarySearch(A, target, ed + 1, A.length - 1);
        }
        return result; 
    }
    
    private int binarySearch(int[] A, int target, int st, int ed) {
        if (st > ed) {
            return -1; 
        }
        int md = (st + ed) / 2;
        if (A[md] == target) {
            return md;
        } else if (A[md] > target) {
            return binarySearch(A, target, st, md - 1); 
        } else {
            return binarySearch(A, target, md + 1, ed);
        }
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
