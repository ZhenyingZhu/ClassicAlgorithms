/*
 * [Source] https://leetcode.com/problems/reverse-linked-list-ii/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: Two pointers. Keep moving nodes to the front.
// [Corner Case]: Involve first or last node
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/ReverseLinkedListBetweenRange.java
 */

/* Java solution
public class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
		ListNode cur=head;
		ListNode bound=new ListNode(0);
        for(int i=1; i<m; i++){
			if(cur==null) return head;
			bound=cur;
			cur=cur.next;
		}
		if(cur==null) return head;
		ListNode first=cur;
		int s=(m<=1)?1:m;
		for(int i=s; i<n; i++){
			ListNode nxt=cur.next;
			if(nxt==null){
				if(m>1) return head;
				else return first;
			}
			cur.next=nxt.next;
			nxt.next=first;
			first=nxt;
			bound.next=first;
		}
		if(m>1) return head;
		return first;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
