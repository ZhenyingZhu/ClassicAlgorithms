/*
 * [Source] https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Breath-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Level order traverse, then reverse the whole result list.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreeLevelOrderTraversalBottomUp.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(root==null) return result;
		preOrderTraverse(root, 0, result);
		Collections.reverse(result);
		return result;
    }
	
	public void preOrderTraverse(TreeNode root, int level, List<List<Integer>> result){
		if(root==null) return;
		if(result.size()<=level){
			List<Integer> list=new ArrayList<Integer>();
			list.add(root.val);
			result.add(list);
		}
		else result.get(level).add(root.val);
		preOrderTraverse(root.left, level+1, result);
		preOrderTraverse(root.right, level+1, result);
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
