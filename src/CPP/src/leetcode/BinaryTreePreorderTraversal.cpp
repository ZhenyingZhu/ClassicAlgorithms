/*
 * [Source] https://leetcode.com/problems/binary-tree-preorder-traversal/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Stack
 */

#include <iostream>

using namespace std;

// [Solution]: First push current node. Then pop it, print it and push its right child, and then its left child.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreePreorderTraversal.java
 */

/* Java solution
public class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
		// Mid, left, right 
		List<Integer> list=new ArrayList<Integer>();
		if(root==null) return list;
		Stack<TreeNode> stack=new Stack<TreeNode>();
		TreeNode current=root;
		stack.push(current);
		while(!stack.isEmpty()){
			current=stack.pop();
			list.add(current.val);
			if(current.right!=null) stack.push(current.right);
			if(current.left!=null) stack.push(current.left);
		}
		return list;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
