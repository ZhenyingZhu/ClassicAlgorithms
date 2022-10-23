/*
 * [Source] https://leetcode.com/problems/jump-game/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Greedy
 */

#include <iostream>

using namespace std;

// [Solution]: Use a pointer to track the farest position. If reach that position but cannot move forward, return false.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/JumpGame.java
 */

/* Java solution
public class Solution {
    public boolean canJump(int[] A) {
        if(A.length<=1) return true;
        int far=0;
        int i=0;
        while(far>=i){
            if(i+A[i]>far) far=i+A[i];
            i++;
            if(far>=A.length-1) return true;
        }
        return false;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
