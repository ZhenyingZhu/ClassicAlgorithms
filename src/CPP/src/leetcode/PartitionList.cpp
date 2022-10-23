/*
 * [Source] https://leetcode.com/problems/partition-list/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Use two lists to put nodes, and then concate them
// [Corner Case]: Don't forget put the null at the end of last node
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/PartitionList.java
 */

/* Java solution
public class Solution {
    public ListNode partition(ListNode head, int x) {
		if(head==null || head.next==null) return head;
        ListNode small=new ListNode(-1);
		ListNode s=small;
		ListNode large=new ListNode(1);
		ListNode l=large;
		while(head!=null){
			if(head.val<x){
				s.next=head;
				s=s.next;
			}else{
				l.next=head;
				l=l.next;
			}
			head=head.next;
		}
		l.next=null; // Important! 
		s.next=large.next;
		return small.next;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
