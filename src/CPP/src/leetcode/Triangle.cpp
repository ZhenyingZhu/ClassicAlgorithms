/*
 * [Source] https://leetcode.com/problems/triangle/
 * [Difficulty]: Medium
 * [Tag]: Array
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: D[i][j]=S[i][j]+min(D[i-1][j],D[i-1][j+1])
// [Corner Case]: The border
class Solution {
};

// [Solution]: Use rotate arrays to same memory
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/rcanddp/TriangleMinPath.java
 */

/* Java solution
public class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
		if(triangle==null || triangle.size()<=0) return 0;
		int totalLevel=triangle.size();
		int[][] store=new int[2][totalLevel]; // Since 0 level has 1 element
		store[0][0]=triangle.get(0).get(0);
		if(triangle.size()==1) return store[0][0];
		for(int i=1; i<totalLevel; i++){
			List<Integer> currentLevel=triangle.get(i);
			store[i%2][0]=currentLevel.get(0)+store[(i-1)%2][0];
			store[i%2][currentLevel.size()-1]=currentLevel.get(currentLevel.size()-1)+store[(i-1)%2][currentLevel.size()-2];
			for(int j=1; j<currentLevel.size()-1; j++){
				store[i%2][j]=currentLevel.get(j)+Math.min(store[(i-1)%2][j-1],store[(i-1)%2][j]);
			}
		}
		int min=Integer.MAX_VALUE;
		for(int i=0; i<store[(totalLevel-1)%2].length; i++){
			if(min>store[(totalLevel-1)%2][i]) min=store[(totalLevel-1)%2][i];
		}
		return min;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
