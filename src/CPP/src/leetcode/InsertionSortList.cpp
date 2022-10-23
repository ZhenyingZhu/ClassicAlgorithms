/*
 * [Source] https://leetcode.com/problems/insertion-sort-list/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 * [Tag]: Sort
 */

#include <iostream>

using namespace std;

// [Solution]: Keep a list with sorted nodes. When reach the new node, move it into the right place.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/InsertionSortList.java
 */

/* Java solution
public class Solution {
    public ListNode insertionSortList(ListNode head) {
		if(head==null || head.next==null) return head;
		ListNode current=head.next;
		ListNode prev=head;
		while(current!=null){
			ListNode run=new ListNode(0);
			run.next=head;
			boolean get=false;
			while(run.next!=current){
				if(run.next.val>current.val){
					if(run.next==head) head=current;
					prev.next=current.next; // sepearate current
					// insert current
					current.next=run.next;
					run.next=current;
					current=prev.next;
					get=true;
					break;
				}
				run=run.next;
			}
			if(!get){
				current=current.next;
				prev=prev.next;
			}
		}
		return head;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
