using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Check if a linkd list is palindrome.
    /// Uncertainties:
    /// 1. Could the linked list have cycle?
    /// 2. Can the original list be changed?
    /// 3. Is empty list count as palindrome?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.6
    /// </remarks>
    public class LinkedListIsPalindrome
    {
        // Solution 1: break the list down in the middle, then reverse the second half and compare
        public static bool PalindromeReverse(SinglyLinkedListNode head)
        {
            if (head == null || head.Next == null)
            {
                return true;
            }

            SinglyLinkedListNode slow = head, fast = head, pre = null;
            while (fast != null && fast.Next != null)
            {
                pre = slow;
                slow = slow.Next;
                fast = fast.Next.Next;
            }

            // Break the list down into two half so it won't keep in loop.
            pre.Next = null;

            SinglyLinkedListNode second = Reverse(slow);
            SinglyLinkedListNode first = head;

            while (first != null && second != null)
            {
                if (first.Data != second.Data)
                {
                    return false;
                }

                first = first.Next;
                second = second.Next;
            }

            return true;
        }

        // Solution 2: recursive and use the stack to compare the nodes
        // Solution 3: use a stack and push the nodes to the stack while iterate through

        private static SinglyLinkedListNode Reverse(SinglyLinkedListNode head)
        {
            SinglyLinkedListNode pre = null, cur = head;
            while (cur != null)
            {
                SinglyLinkedListNode next = cur.Next;
                cur.Next = pre;
                pre = cur;
                cur = next;
            }

            return pre;
        }
    }
}
