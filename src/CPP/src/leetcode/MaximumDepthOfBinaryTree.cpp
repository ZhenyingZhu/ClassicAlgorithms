/*
 * [Source] https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Use a queue to do DFS and count the level.
// [Corner Case]:
class Solution {
};

// [Solution]: recursive call with return value as depth
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/MaximumDepthOfBinaryTree.java
 */

/* Java solution
public class Solution {
    public int maxDepth(TreeNode root) {
		return height(root);
    }
	
	public int height(TreeNode current){
		if(current==null) return 0;
		int lHeight=height(current.left);
		int rHeight=height(current.right);
		int h=Math.max(lHeight, rHeight);
		return h+1;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
