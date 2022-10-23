/*
 * [Source] https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * [Difficulty]: Medium
 * [Tag]: Tree
 * [Tag]: Depth-first Search
 */

#include <iostream>

using namespace std;

// [Solution]: Pick the middle element and use as root. Then construct the left and right subtree.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/ConvertSortedArrayToBinarySearchTree.java
 */

/* Java solution
public class Solution {
    public TreeNode sortedArrayToBST(int[] num) {
		return sortedArrayToBST(num, 0, num.length-1);
    }
	
	public TreeNode sortedArrayToBST(int[] num, int start, int end){
		if(start>end) return null;
		int mid=(start+end)/2;
		TreeNode root=new TreeNode(num[mid]);
		root.left=sortedArrayToBST(num, start, mid-1);
		root.right=sortedArrayToBST(num, mid+1, end);
		return root;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
