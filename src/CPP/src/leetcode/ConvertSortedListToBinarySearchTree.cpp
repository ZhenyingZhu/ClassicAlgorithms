/*
 * [Source] https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
 * [Difficulty]: Medium
 * [Tag]: Depth-first Search
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: Count the length of the list first, then do it as array
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/treeandgraph/ConvertSortedListToBST.java
 */

/* Java solution
public class Solution {
    public TreeNode sortedListToBST(ListNode head) {
		if(head==null) return null;
		if(head.next==null){
			TreeNode root=new TreeNode(head.val);
			return root;
		}
		if(head.next.next==null){
			TreeNode root=new TreeNode(head.val);
			TreeNode right=new TreeNode(head.next.val);
			root.right=right;
			return root;
		}
		ListNode cur=null;
		ListNode mid=head;
		ListNode end=head;
		while(end!=null && end.next!=null){
			cur=mid;
			mid=mid.next;
			end=end.next.next;
		}
		cur.next=null;
		ListNode start=mid.next;
		mid.next=null;
		TreeNode root=new TreeNode(mid.val);
		root.left=sortedListToBST(head);
		root.right=sortedListToBST(start);
		return root;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
