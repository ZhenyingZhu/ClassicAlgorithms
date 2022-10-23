/*
 * [Source] https://leetcode.com/problems/merge-two-sorted-lists/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: Keep pointers point to the first unadded nodes in lists, and compare them. Use a dummy header
// [Corner Case]: If one list reach the end first.
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/MergeTwoSortedLists.java
 */

/* Java solution
public class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
		if(l1==null) return l2;
		if(l2==null) return l1;
        ListNode dummy=new ListNode(0);
		ListNode pt1=l1;
		ListNode pt2=l2;
		ListNode cur=dummy;
		while(pt1!=null && pt2!=null){
			if(pt1.val<=pt2.val){
				cur.next=pt1;
				pt1=pt1.next;
			}else{
				cur.next=pt2;
				pt2=pt2.next;
			}
			cur=cur.next;
		}
		if(pt1==null){
			cur.next=pt2;
		}else{
			cur.next=pt1;
		}
		return dummy.next;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
