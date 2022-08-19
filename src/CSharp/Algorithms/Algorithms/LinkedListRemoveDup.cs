using Algorithms.Utils;
using System.Collections.Generic;

namespace Algorithms
{
    /// <summary>
    /// Remove dups from unsorted linked list, without using a buffer.
    /// Uncertainties:
    /// 1.singly or doubly linked list?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.1
    /// </remarks>
    public class LinkedListRemoveDup
    {
        // Solution 1: Use a hashset to record, and go over all the nodes.
        public static SinglyLinkedListNode RemoveDupsWithBuffer(SinglyLinkedListNode head)
        {
            HashSet<int> appearedNodes = new HashSet<int>();

            SinglyLinkedListNode preHead = new SinglyLinkedListNode(0);
            preHead.Next = head;
            SinglyLinkedListNode pre = preHead, cur = head;
            while (cur != null)
            {
                if (appearedNodes.Contains(cur.Data))
                {
                    pre.Next = cur.Next;
                }
                else
                {
                    appearedNodes.Add(cur.Data);
                    pre = pre.Next;
                }

                cur = cur.Next;
            }

            return preHead.Next;
        }

        // Solution 2: use two pointers with O(n^2) time complexity.
    }
}
