using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Given the reference to a node in the middle of a list, delete it.
    /// Uncertainties:
    /// 1. Can it be the first or the last node?
    /// 2. Is it singly linked list?
    /// 3. Do I have the node access?
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.3
    /// </remarks>
    public class LinkedListDeleteMiddleNode
    {
        // Not a solution. The head should not pass in.
        public static void DeleteMiddleNodeWithHeadAccess(SinglyLinkedListNode head, SinglyLinkedListNode nodeToDel)
        {
            SinglyLinkedListNode preHead = new SinglyLinkedListNode(0);
            preHead.Next = head;
            SinglyLinkedListNode pre = preHead, cur = head;
            while (cur != null)
            {
                if (cur == nodeToDel)
                {
                    pre.Next = cur.Next;
                    nodeToDel.Next = null;
                    preHead.Next = null;

                    return;
                }

                pre = cur;
                cur = cur.Next;
            }
        }

        // Solution: copy the data in the next node to the del node.
    }
}
