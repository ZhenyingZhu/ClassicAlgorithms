/*
 * [Source] https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Array
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Find the first element of preorder sequence in the inorder seq. Then part the inorder and preorder sequences into left subtree and right subtree part.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/ConstructBinaryTreeFromPreorderAndInorderTraversal.java
 */

/* Java solution
public class Solution {
    public TreeNode buildTree(int[] preorder, int[] inorder) {
		return buildTree(preorder, 0, preorder.length-1, inorder, 0, inorder.length-1);
    }
	
	public TreeNode buildTree(int[] preorder, int ps, int pe, int[] inorder, int is, int ie){
		if(pe>=preorder.length || ps>pe) return null;
		TreeNode root=new TreeNode(preorder[ps]);
		if(pe==ps) return root;
		int im=-1;
		for(int i=is; i<=ie; i++){
			if(inorder[i]==preorder[ps]) {
				im=i;
				break;
			}
		}
		root.left=buildTree(preorder, ps+1, ps+im-is, inorder, is, im-1);
		root.right=buildTree(preorder, ps+im-is+1, pe, inorder, im+1, ie);
		return root;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
