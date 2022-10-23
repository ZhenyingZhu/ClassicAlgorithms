/*
 * [Source] https://leetcode.com/problems/minimum-depth-of-binary-tree/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]:   Depth-first Search
 * [Tag]: Breadth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Use DFS. When find a leave without left or right child, return.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/MinimumDepthOfBinaryTreeIterative.java
 */

/* Java solution
public class Solution {
    public int minDepth(TreeNode root) {
		if(root==null) return 0;
		Queue<TreeNode> queue=new LinkedList<TreeNode>();
		queue.offer(root);
		int dept=0;
		int size=1;
		boolean findDept=false;
		while(!queue.isEmpty()){
			dept++;
			int cnt=0;
			for(int i=0; i<size; i++){
				TreeNode cur=queue.poll();
				if(cur.left==null && cur.right==null){
					findDept=true;
					break;
				}
				if(cur.left!=null){
					queue.offer(cur.left);
					cnt++;
				}
				if(cur.right!=null){
					queue.offer(cur.right);
					cnt++;
				}
			}
			if(findDept) break;
			size=cnt;
		}
		return dept;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
