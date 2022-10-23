/*
 * [Source] https://leetcode.com/problems/rotate-list/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Slow pointer points to the place need to break, and fast pointer points to the end. Don't forget to place Null at the new end.
// [Corner Case]: k >= length
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/RotateList.java
 */

/* Java solution
public class Solution {
    public ListNode rotateRight(ListNode head, int n) {
		if(head==null) return head;
		if(n<=0) return head;
        ListNode point=head;
		ListNode fast=head;
		while(n>0){
			fast=fast.next;
			if(fast==null) fast=head;
			n--;
		}
		ListNode slow=head;
		while(fast.next!=null){
			fast=fast.next;
			slow=slow.next;
		}
		if(fast==slow) return head;
		head=slow.next;
		slow.next=null;
		fast.next=point;
		return head;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
