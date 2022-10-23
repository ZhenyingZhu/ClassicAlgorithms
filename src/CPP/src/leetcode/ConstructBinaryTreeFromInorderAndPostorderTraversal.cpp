/*
 * [Source] https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Array
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: The last element in postorder is the root and use it to seperate inorder and postorder seq.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/ConstructBinaryTreeFromInorderAndPostorderTraversal.java
 */

/* Java solution
public class Solution {
    public TreeNode buildTree(int[] inorder, int[] postorder) {
		return buildTree(inorder, 0, inorder.length-1, postorder, 0, postorder.length-1);
    }
	
	public TreeNode buildTree(int[] inorder, int is, int ie, int[] postorder, int ps, int pe){
		if(ps>pe) return null;
		TreeNode root=new TreeNode(postorder[pe]);
		if(ps==pe) return root;
		int im=-1; // The root position in inorder. 
		for(int i=is; i<=ie; i++){
			if(inorder[i]==postorder[pe]) im=i;
		}
		int pm=ps+(im-is); // The left sub tree. 
		root.left=buildTree(inorder, is, im-1, postorder, ps, pm-1);
		root.right=buildTree(inorder, im+1, ie, postorder, pm, pe-1);
		return root;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
