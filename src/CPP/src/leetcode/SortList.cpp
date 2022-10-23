/*
 * [Source] https://leetcode.com/problems/sort-list/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 * [Tag]: Sort
 */

#include <iostream>

using namespace std;

// [Solution]: Count the length of the list first. Then break the list into half use this number. Run quick sort.
// [Corner Case]:
class Solution {
};

// [Solution]: Use two pointers
/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/SortList.java
 */

/* Java solution
public class Solution {
    public ListNode sortList(ListNode head) {
		if(head==null || head.next==null) return head;
		ListNode end=head;
		ListNode mid=head;
		ListNode current=head;
		while(end!=null && end.next!=null){
			end=end.next.next;
			current=mid;
			mid=mid.next;
		}
		current.next=null;
		ListNode first=sortList(head);
		ListNode second=sortList(mid);
		head=mergeList(first, second);
		return head;
    }
	public ListNode mergeList(ListNode first, ListNode second){
		ListNode dummy=new ListNode(0);
		ListNode current=dummy;
		while(first!=null && second!=null){
			if(first.val<second.val){
				current.next=first;
				current=first;
				first=first.next;
			}else{
				current.next=second;
				current=second;
				second=second.next;
			}
		}
		if(first==null) current.next=second;
		else current.next=first;
		return dummy.next;
	}
    
}
 */

int main() {
    Solution sol;

    return 0;
}
