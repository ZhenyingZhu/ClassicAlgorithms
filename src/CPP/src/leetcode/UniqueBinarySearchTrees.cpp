/*
 * [Source] https://leetcode.com/problems/unique-binary-search-trees/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: D[i,j]=sum(D[i,k]*D[k+2,j])
// [Corner Case]: if i==j, D[i,j] = 1 not 0
class Solution {
};

// [Solution]: Recursive call
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/UniqueBinarySearchTreesNum.java
 */

/* Java solution
public class Solution {
    public int numTrees(int n) {
		if(n<=0) return 0;
        int ans=createTree(1, n);
		return ans;
    }
	
	public int createTree(int start, int end){
		if(start>end) return 0;
		if(start==end) return 1;
		int sum=0;
		sum+=createTree(start+1, end);
		sum+=createTree(start, end-1);
		for(int i=start+1; i<=end-1; i++){
			sum+=createTree(start, i-1)*createTree(i+1, end);
		}
		return sum;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
