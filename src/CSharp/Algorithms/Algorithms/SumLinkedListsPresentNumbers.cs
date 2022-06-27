using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Sum two lists that present numbers.
    /// Uncertainties:
    /// 1. link direction?
    /// 2. number exceed int max?
    /// 3. Can the original lists get destroyed?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.5
    /// </remarks>
    public class SumLinkedListsPresentNumbers
    {
        // Solution 1: reverse the lists, then add them and reverse again.
        public static SinglyLinkedListNode SumListsReverse(SinglyLinkedListNode head1, SinglyLinkedListNode head2)
        {
            if (head1 == null)
            {
                return head2;
            }

            if (head2 == null)
            {
                return head1;
            }

            SinglyLinkedListNode head1Rev = Reverse(head1), head2Rev = Reverse(head2);

            int overflow = 0;
            SinglyLinkedListNode preHead = new SinglyLinkedListNode(0), cur = preHead;
            while (head1Rev != null && head2Rev != null)
            {
                int val = head1Rev.Data + head2Rev.Data + overflow;
                SinglyLinkedListNode node = new SinglyLinkedListNode(val % 10);
                cur.Next = node;
                cur = node;

                overflow = val / 10;
                head1Rev = head1Rev.Next;
                head2Rev = head2Rev.Next;
            }

            SinglyLinkedListNode remain = head1Rev == null ? head2Rev : head1Rev;
            while (overflow > 0 && remain != null)
            {
                int val = overflow + remain.Data;
                SinglyLinkedListNode node = new SinglyLinkedListNode(val % 10);
                cur.Next = node;
                cur = node;

                overflow = val / 10;

                remain = remain.Next;
            }

            if (overflow > 0)
            {
                SinglyLinkedListNode node = new SinglyLinkedListNode(overflow);
                cur.Next = node;
            }
            else
            {
                // overflow == 0
                cur.Next = remain;
            }

            return Reverse(preHead.Next);
        }

        // Solution 2: create a recurvise addList(node1, node2, carryover) -> node
        // Solution 3: padding 0s until two lists are same length, then sum each pair of nodes recrusively

        private static SinglyLinkedListNode Reverse(SinglyLinkedListNode head)
        {
            if (head == null)
            {
                return null;
            }

            SinglyLinkedListNode pre = head, cur = head.Next;

            // otherwise a cycle will be created
            pre.Next = null;

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
