/*
 * [Source] https://leetcode.com/problems/symmetric-tree/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Compare left subtree root is same as right subtree root, and recursive call.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/SymmetricTreeRecursive.java
 */

/* Java solution
public class Solution {
    public boolean isSymmetric(TreeNode root) {
		if(root==null) return true;
		return isSymmetric(root.left, root.right);
    }
	
	public boolean isSymmetric(TreeNode lNode, TreeNode rNode){
		if(lNode==null && rNode==null) return true;
		if(lNode==null || rNode==null) return false;
		if(lNode.val!=rNode.val) return false;
		boolean lSub=isSymmetric(lNode.left, rNode.right);
		boolean rSub=isSymmetric(lNode.right, rNode.left);
		return lSub && rSub;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
