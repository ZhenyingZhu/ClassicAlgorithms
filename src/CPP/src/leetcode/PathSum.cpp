/*
 * [Source] https://leetcode.com/problems/path-sum/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: DFS. backtracking.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/PathSum.java
 */

/* Java solution
public class Solution {
    public boolean hasPathSum(TreeNode root, int sum) {
		if(root==null) return false;
		return pathSum(root, sum);
    }
	
	public boolean pathSum(TreeNode root, int sum){
		if(root==null) return false;
		if((sum-root.val)==0 && root.left==null && root.right==null) return true; // should be leaf
		boolean l=pathSum(root.left, sum-root.val);
		boolean r=pathSum(root.right, sum-root.val);
		return l || r;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
