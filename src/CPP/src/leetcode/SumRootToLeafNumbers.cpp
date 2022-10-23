/*
 * [Source] https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Previous * 10 + current is the number.
// [Corner Case]: If this node doesn't has left and right child, it is done.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/SumRootToLeafNumbers.java
 */

/* Java solution
public class Solution {
    public int sumNumbers(TreeNode root) {
		if(root==null) return 0;
		return sumNumbers(root, 0);
    }
	
	public int sumNumbers(TreeNode root, int sum){
		if(root==null) return 0;
		int s=sum*10+root.val;
		if(root.left==null && root.right==null) return s;
		return sumNumbers(root.left, s)+sumNumbers(root.right, s);
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
