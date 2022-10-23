/*
 * [Source] https://leetcode.com/problems/validate-binary-search-tree/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Use a structure, return 1. tree valid, 2. smallest value, 3. largest value. Then use recursive call.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/ValidateBinarySearchTree.java
 */

// [Solution]: in-order traverse the tree, and check.
/* Java solution
public class Solution {
    public boolean isValidBST(TreeNode root) {
		if(root==null) return true;
		if(root.left==null && root.right==null) return true;
		int prev=Integer.MIN_VALUE; 
		TreeNode ptr=root;
		TreeNode tmp=null;
		while(ptr!=null){
			if(ptr.left==null){
				if(ptr.val<=prev) return false;
				prev=ptr.val;
			    ptr=ptr.right;
			}else{
				tmp=ptr.left;
				while(tmp.right!=null && tmp.right!=ptr){
					tmp=tmp.right;
				}
				if(tmp.right==ptr){
					if(ptr.val<=prev) return false;
					prev=ptr.val;
					tmp.right=null;
					ptr=ptr.right;
				}else{
					tmp.right=ptr;
					ptr=ptr.left;
				}
			}
		}
		return true;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
