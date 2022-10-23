/*
 * [Source] https://leetcode.com/problems/container-with-most-water/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 * [Tag]: Greedy
 */

#include <iostream>

using namespace std;

// [Solution]: for x = 0..n-1, y = n..1, if Ax < Ax-1, skip; if Ay < Ay-1, skip.
// [Corner Case]:
class Solution {
};

// [Solution]: If Ax < Ay, then there is no way to make area become larger if x not change.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ContainerWithMostWater.java
 */

/* Java solution
public class Solution {
    public int maxArea(int[] height) {
        if (height == null || height.length <= 1) {
            return 0; 
        }
        int st = 0; 
        int ed = height.length - 1; 
        int max = Integer.MIN_VALUE; 
        while (st < ed) {
            max = Math.max(max, Math.min(height[st], height[ed]) * (ed - st)); 
            if (height[st] <= height[ed]) {
                ++st; 
            } else {
                --ed; 
            }
        }
        return max; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
