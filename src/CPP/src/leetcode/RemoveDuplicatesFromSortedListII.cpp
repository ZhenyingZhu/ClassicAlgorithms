/*
 * [Source] https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: Keep a prev pointer. If Next several nodes are same, skip.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/RemoveAllDuplicatesFromSortedList.java
 */

/* Java solution
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
		if(head==null || head.next==null) return head;
		HashSet<Integer> set=new HashSet<Integer>();
		ListNode dummy=new ListNode(0);
		ListNode cur=dummy;
		ListNode fast=null;
		while(head!=null){
			if(!set.contains(head.val)){
				int key=head.val;
				set.add(key);
				fast=head.next;
				boolean get=false;
				while(fast!=null){
					if(fast.val==head.val){
						get=true;
						break;
					}
					fast=fast.next;
				}
				if(get){
					cur.next=head.next;
				}else{
					cur.next=head;
					cur=head;
				}
			}else{
				cur.next=head.next;
			}
			head=head.next;
		}
		return dummy.next;
    }
}
 */

int main() {
    Solution sol;

    return 0;
}
