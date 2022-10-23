/*
 * [Source] https://leetcode.com/problems/climbing-stairs/
 * [Difficulty]: Easy
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: use an n+1 size array. A[i]=A[i-1]+A[i-2]
// [Corner Case]: n = 0,1,2
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/ClimbingStairs.java
 */

/* Java solution
public class Solution {
    public int climbStairs(int n) {
		if(n<=0) return 0;
        int[] array=new int[n+1];
		array[0]=1;
		array[1]=1;
		for(int i=2; i<array.length; i++){
			array[i]=array[i-1]+array[i-2];
		}
		return array[n];
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
