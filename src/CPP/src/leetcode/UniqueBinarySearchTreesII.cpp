/*
 * [Source] https://leetcode.com/problems/unique-binary-search-trees-ii/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Dynamic Programming
 */

#include <iostream>

using namespace std;

// [Solution]: Take each node as root. Recursively call the create left subtree and right subtree. To not repeatly create trees, use hash table.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/UniqueBinarySearchTrees.java
 */

/* Java solution
public class Solution {
    public List<TreeNode> generateTrees(int n) {
		if(n<=0){
			List<TreeNode> list=new ArrayList<TreeNode>();
			list.add(null);
			return list;
		}
        List<TreeNode> list=createTree(1, n);
		return list;
    }
	
	public List<TreeNode> createTree(int start, int end){
		List<TreeNode> list=new ArrayList<TreeNode>();
		if(start>end) return list;
		if(start==end){
			TreeNode root=new TreeNode(start);
			list.add(root);
			return list;
		}
		List<TreeNode> startRight=createTree(start+1, end);
		for(int i=0; i<startRight.size(); i++){
			TreeNode root=new TreeNode(start);
			root.right=startRight.get(i);
			list.add(root);
		}
		List<TreeNode> endLeft=createTree(start, end-1);
		for(int i=0; i<endLeft.size(); i++){
			TreeNode root=new TreeNode(end);
			root.left=endLeft.get(i);
			list.add(root);
		}
		for(int i=start+1; i<=end-1; i++){
			List<TreeNode> leftList=createTree(start, i-1);
			List<TreeNode> rightList=createTree(i+1, end);
			for(int l=0; l<leftList.size(); l++){
				for(int r=0; r<rightList.size(); r++){
					TreeNode root=new TreeNode(i);
					root.left=leftList.get(l);
					root.right=rightList.get(r);
					list.add(root);
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
