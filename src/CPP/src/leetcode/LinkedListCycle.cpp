/*
 * [Source] https://leetcode.com/problems/linked-list-cycle/
 * [Difficulty]: Easy
 * [Tag]: Linked List
 * [Tag]: Two Pointers
 */

#include <iostream>

using namespace std;

// [Solution]: One pointer move 1 each time, and the other move 2. If they meet, cycle detected.
// [Corner Case]:
class Solution {
};

/* Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/linkedlist/LinkedListCycle.java
 */

/* Java solution
public class Solution {
    public boolean hasCycle(ListNode head) {
       ListNode fast=head;
		ListNode slow=head;
		do{
			if(fast==null || fast.next==null) return false;
			fast=fast.next.next;
			slow=slow.next;
		}while(fast!=slow);
		return true;
	}
}
 */

int main() {
    Solution sol;

    return 0;
}
