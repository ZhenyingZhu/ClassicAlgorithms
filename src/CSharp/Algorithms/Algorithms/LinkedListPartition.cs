using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Give a number, partition a list so that nodes smaller than it comes first. Nodes equal or larger comes later.
    /// Uncertainties:
    /// 1. does order matter?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.4
    /// </remarks>
    public class LinkedListPartition
    {
        // Solution 1: store the list as two.
        public static SinglyLinkedListNode PartitionTwoLists(SinglyLinkedListNode head, int val)
        {
            if (head == null)
            {
                return null;
            }

            SinglyLinkedListNode head1 = new SinglyLinkedListNode(0), head2 = new SinglyLinkedListNode(0);
            SinglyLinkedListNode ptr1 = head1, ptr2 = head2;
            SinglyLinkedListNode cur = head;
            while (cur != null)
            {
                if (cur.Data < val)
                {
                    ptr1.Next = cur;
                    ptr1 = ptr1.Next;
                }
                else
                {
                    ptr2.Next = cur;
                    ptr2 = ptr2.Next;
                }

                cur = cur.Next;
            }

            ptr1.Next = head2.Next;
            return head1.Next;
        }

        // Solution 2: use two ptrs but not create two list. One points to head, one points to tail. Then both 
        // start from the first node. Moving forward 
    }
}
