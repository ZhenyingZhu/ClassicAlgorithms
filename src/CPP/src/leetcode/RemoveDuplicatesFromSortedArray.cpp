/*
 * [Source] https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Use a pointer to indicate last checked cell, and a pointer to indicate last non-dup cell. Then replace the next cell with non-dup value
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/RemoveDuplicatesFromSortedArray.java
 */

/* Java solution
public class Solution {
    public int removeDuplicates(int[] A) {
        if(A == null || A.length == 0) {
            return 0; 
        }
        int len = 1; 
        int key = A[0]; 
        for(int i = 1; i < A.length; ++i) {
            if(A[i] > key) {
                key = A[i]; 
                A[len] = A[i]; 
                ++len; 
            }
        }
        return len; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
