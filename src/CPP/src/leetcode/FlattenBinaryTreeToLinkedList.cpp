/*
 * [Source] https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Preorder traverse the tree with stack, and then set right sub tree of previous linked node as the current node.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/FlattenBinaryTreeToLinkedList.java
 */

/* Java solution
public class Solution {
	TreeNode last=null;
    public void flatten(TreeNode root) {
		if(root==null) return;
		if(last!=null){
			last.right=root;
			last=null;
		}
		TreeNode temp=root.right;
		if(root.left!=null){
			root.right=root.left;
			flatten(root.left);
			root.left=null;
		}
		flatten(temp);
		if(root.right==null) last=root;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
