/*
 * [Source] https://leetcode.com/problems/3sum-closest/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Same as three sum, just calucate the diff. Find the smallest diff.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/arrandstring/ThreeSumClosest.java
 */

/* Java solution
public class Solution {
    public int threeSumClosest(int[] num, int target) {
        if (num == null || num.length < 3) {
            return Integer.MIN_VALUE; 
        }
        Arrays.sort(num); 
        int gap = Integer.MAX_VALUE; 
        int st, ed; 
        int sum; 
        for (int i = 0; i < num.length - 2; ++i) {
            st = i + 1; 
            ed = num.length - 1; 
            while (st < ed) {
                sum = num[i] + num[st] + num[ed];
                if (sum == target) {
                    return sum; 
                }
                if (Math.abs(sum - target) < Math.abs(gap)) {
                    gap = sum - target; 
                }
                if (sum > target) {
                    --ed; 
                } else  {
                    ++st; 
                }
            }
        }
        return target + gap; 
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
