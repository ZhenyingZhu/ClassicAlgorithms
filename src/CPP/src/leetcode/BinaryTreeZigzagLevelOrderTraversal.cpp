/*
 * [Source] https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Breadth-first Search
 * [Tag]: Stack
 */

#include <iostream>

using namespace std;

// [Solution]: Level order traverse with odd level lists reversed.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/BinaryTreeZigzagLevelOrderTraversal.java
 */

/* Java solution
public class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		List<List<Integer>> result=new ArrayList<List<Integer>>();
		if(root==null) return result;
		levelOrder(root, 0, result);
		int i=1;
		while(i<result.size()){
			Collections.reverse(result.get(i));
			i=i+2;
		}
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

int main() {
    Solution sol;

    return 0;
}
