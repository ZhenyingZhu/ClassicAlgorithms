/*
 * [Source] https://leetcode.com/problems/binary-tree-level-order-traversal/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Breadth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Recursive call with depth.
// [Corner Case]:
class Solution {
};

/* Java solution
public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(root==null) return result;
		levelOrder(root, 0, result);
		return result;
    }
	
	public void levelOrder(TreeNode root, int level, List<List<Integer>> result){
		if(root==null) return;
		if(result.size()<=level){
			List<Integer> list=new ArrayList<Integer>();
			list.add(root.val);
			result.add(list);
		}else{
			result.get(level).add(root.val);
		}
		levelOrder(root.left, level+1, result);
		levelOrder(root.right, level+1, result);
    }
}
 */

// [Solution]: Use a queue to do breadth first search. Use size to track the current level is end or not
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreeLevelOrderTraversal.java
 */

int main() {
    Solution sol;

    return 0;
}
