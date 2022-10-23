/*
 * [Source] https://leetcode.com/problems/remove-element/
 * [Difficulty]: Easy
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: One pointer from begining, another from end. Swap a target value with other values.
// [Corner Case]:
class Solution {
};

/* Java solution
public class Solution {
    public int removeElement(int[] A, int elem) {
        if(A == null || A.length == 0) {
            return 0; 
        }
        int len = A.length; 
        for(int i = 0; i < len; ++i) {
            if(A[i] == elem) {
                while(len > 0 && A[len - 1] == elem) {
                    --len; 
                }
                if(i > len - 1) { // After i all elem
                    return len; 
                }
                A[i] = A[len - 1]; 
                --len; 
            }
        }
        return len; 
    }
}
 */

// [Solution]: Use a pointer indicate fine area, and a pointer for current proceed cell
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/RemoveElement.java
 */

int main() {
    Solution sol;

    return 0;
}
