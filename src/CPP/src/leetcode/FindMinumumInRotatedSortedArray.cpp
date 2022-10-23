/*
 * [Source] https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Binary Search
 */

#include <iostream>

using namespace std;

// [Solution]: Compare current value with left value to decide if it is the min. If it is smaller than end, then go to left, else go to right.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/sortandsearch/FindMinimumInRotatedSortedArray.java
 */

// [Solution]: lineary scan
/* Java solution
public class Solution {
    public int findMin(int[] num) {
        if (num == null || num.length == 0) {
            return Integer.MAX_VALUE; 
        }
        
        for (int i = 1; i < num.length; ++i) {
            if (num[i] < num[i - 1]) {
                return num[i]; 
            }
        }
        
        return num[0]; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
