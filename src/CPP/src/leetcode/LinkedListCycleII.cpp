/*
 * [Source] https://leetcode.com/problems/linked-list-cycle-ii/
 * [Difficulty]: Medium
 * [Tag]: Linked List
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: Slow and fast pointers. When slow and fast meet, move one back to the begining, and both of them move 1 at a time.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/LinkedListCycleStart.java
 */

/* Java solution
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode fast=head;
		ListNode slow=head;
		do{
			if(fast==null || fast.next==null) return null;
			fast=fast.next.next;
			slow=slow.next;
		}while(fast!=slow);
		ListNode start=head;
		while(start!=slow){
			start=start.next;
			slow=slow.next;
		}
		return start;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
