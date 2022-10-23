/*
 * [Source] https://leetcode.com/problems/same-tree/
 * [Difficulty]: Easy
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Compare each node, its left and right child.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/SameTree.java
 */

/* Java solution
public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
		if(q==null && p==null) return true;
		if(q==null || p==null) return false;
		if(q.val!=p.val) return false;
		boolean lSub=isSameTree(p.left, q.left);
		boolean rSub=isSameTree(p.right, q.right);
		return lSub && rSub;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
