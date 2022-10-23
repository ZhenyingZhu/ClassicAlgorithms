/*
 * [Source] https://leetcode.com/problems/reorder-list/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: Use two pointers to break the list in half first. Then reverse the second list. Then merge them.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/ReorderListIterative.java
 */

// [Solution]: Recursive call
/* Java solution
public class Solution {
    public void reorderList(ListNode head) {
		if(head==null || head.next==null) return;
		ListNode fast=head;
		ListNode slow=head;
		while(fast!=null && fast.next!=null){
			fast=fast.next.next;
			slow=slow.next;
		}
		reorderList(head, slow);
    }
	
	public ListNode reorderList(ListNode head, ListNode tail){
		if(tail.next==null){
			ListNode temp=head.next;
			head.next=tail;
			if(tail==temp){ // Only two nodes. 
				temp.next=null;
				return null;
			}
			tail.next=temp;
			if(temp.next==tail){ // Only three nodes. 
				temp.next=null;
				return null;
			}
			return temp;
		}
		ListNode before=reorderList(head, tail.next);
		if(before==null) return null;
		ListNode temp=before.next;
		before.next=tail;
		if(tail==temp){ // Even nodes. 
			tail.next=null;
			return null;
		}
		tail.next=temp;
		if(temp.next==tail){ // Odd nodes
			temp.next=null;
			return null;
		}
		return temp;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
