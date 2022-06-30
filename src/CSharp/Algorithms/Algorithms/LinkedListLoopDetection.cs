using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Give a circlar linked list, return the node that is the beginning of the loop.
    /// Uncertainties:
    /// 1. Does the loop must exist?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.8
    /// </remarks>
    public class LinkedListLoopDetection
    {
        // Solution 1: two pointers
        public static SinglyLinkedListNode LoopDetection(SinglyLinkedListNode head)
        {
            if (head == null)
            {
                return null;
            }

            SinglyLinkedListNode slow = head, fast = head;
            do
            {
                fast = fast.Next.Next;
                slow = slow.Next;
            }
            while (fast != null && fast.Next != null && fast != slow);

            if (fast.Next == null)
            {
                return null;
            }

            fast = head;

            while (fast != slow)
            {
                fast = fast.Next;
                slow = slow.Next;
            }

            return fast;
        }
    }
}
