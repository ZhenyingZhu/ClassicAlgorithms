using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Return the kth to last node.
    /// Uncertainties:
    /// 1. If k is longer than the list?
    /// 2. If the length is known?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.2
    /// </remarks>
    public class LinkedListReturnKthToLast
    {
        // Solution 1: two pointers.
        public static SinglyLinkedListNode ReturnKthToLast(SinglyLinkedListNode head, int k)
        {
            SinglyLinkedListNode fast = head;
            for (int i = 0; i < k && fast != null; i++)
            {
                fast = fast.Next;
            }

            SinglyLinkedListNode slow = head;
            while (fast != null)
            {
                slow = slow.Next;
                fast = fast.Next;
            }

            return slow;
        }

        // Solution 2: use recursive way.

        // Solution 3: traverse the list twice. One count the total length.
    }
}
