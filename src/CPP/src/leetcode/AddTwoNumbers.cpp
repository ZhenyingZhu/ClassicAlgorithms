/*
 * [Source] https://leetcode.com/problems/add-two-numbers/
 * [Difficulty]: Medium
 * [Tag]: Linked list
 * [Tag]: Math
 */

#include <iostream>

using namespace std;

// [Solution]: Use a carry on
class Solution {
};

/* Java solution
public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2; 
        }
        if (l2 == null) {
            return l1; 
        }
        ListNode dummy = new ListNode(0); 
        ListNode pre = dummy; 
        int c = 0; 
        int v; 
        while (l1 != null && l2 != null) {
            v = l1.val + l2.val + c; 
            l1 = l1.next; 
            l2 = l2.next; 
            if (v >= 10) {
                c = v / 10; 
                v = v % 10; 
            } else {
                c = 0; 
            }
            ListNode cur = new ListNode(v); 
            pre.next = cur; 
            pre = cur; 
        }
        if (l2 != null) {
            l1 = l2; 
        }
        while (l1 != null) {
            v = l1.val + c; 
            l1 = l1.next; 
            if (v >= 10) {
                c = v / 10; 
                v = v % 10; 
            } else {
                c = 0; 
            }
            ListNode cur = new ListNode(v); 
            pre.next = cur; 
            pre = cur; 
        }
        if (c != 0) {
            ListNode cur = new ListNode(c); 
            pre.next = cur; 
        }
        return dummy.next; 
    }
}
 */

/*Java solution
https://github.com/ZhenyingZhu/ClassicAlgorithms/blob/master/src/algorithms/mathandprob/AddTwoNumbersFromReversedList.java
 */

int main() {
    Solution sol;

    return 0;
}
