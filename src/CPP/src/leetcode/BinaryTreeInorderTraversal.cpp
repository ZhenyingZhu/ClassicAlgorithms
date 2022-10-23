/*
 * [Source] https://leetcode.com/problems/binary-tree-inorder-traversal/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Hash Table
 * [Tag]: Stack
 */

#include <iostream>

using namespace std;

// [Solution]: Use a stack. Push left child. If the top doesn't have a left child, print it and push right child.
// [Corner Case]:
class Solution {
};

// [Solution]: Push all the left child into the stack in one time.
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreeInorderTraversal.java
 */

// [Solution]: Link parent to leaf right, so the running pointer actually goes back to its parent.
/* Java solution
public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> list=new ArrayList<Integer>();
		if(root==null) return list;
		TreeNode ptr=root;
		TreeNode tmp=null;
		while(ptr!=null){
			if(ptr.left==null){
				list.add(ptr.val);
				ptr=ptr.right;
			}else{
				tmp=ptr.left;
				while(tmp.right!=null && tmp.right!=ptr){
					tmp=tmp.right;
				}
				if(tmp.right==ptr){
					list.add(ptr.val);
					ptr=ptr.right;
					tmp.right=null;
				}else{
					tmp.right=ptr;
					ptr=ptr.left;
				}
			}
		}
		return list;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
