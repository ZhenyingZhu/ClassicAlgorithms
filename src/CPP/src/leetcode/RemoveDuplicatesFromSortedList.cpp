/*
 * [Source] https://leetcode.com/problems/remove-duplicates-from-sorted-list/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 */

#include <iostream>

using namespace std;

// [Solution]: If find the next one is same as current one, skip.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/RemoveDuplicatesFromSortedList.java
 */

/* Java solution
public class Solution {
    public ListNode deleteDuplicates(ListNode head) {
		if(head==null || head.next==null) return head;
        HashSet<Integer> set=new HashSet<Integer>();
		ListNode dummy=new ListNode(0);
		ListNode cur=dummy;
		while(head!=null){
			if(!set.contains(head.val)){
				set.add(head.val);
				cur.next=head;
				cur=head;
			}else{
				cur.next=head.next; // Disconnect this node
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
