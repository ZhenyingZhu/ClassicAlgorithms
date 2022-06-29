using System;
using System.Collections.Generic;
using System.Text;
using Algorithms.Utils;

namespace Algorithms
{
    /// <summary>
    /// Find the intersection node for two linked lists.
    /// </summary>
    /// <remarks>
    /// CC189 6th 2.7
    /// </remarks>
    public class LinkedListsIntersectionNode
    {
        // Solution 1: traverse twice. First count the length. Then skip the first couple nodes of the longer list.
        public static SinglyLinkedListNode IntersectionCountLength(SinglyLinkedListNode head1, SinglyLinkedListNode head2)
        {
            int len1 = 0, len2 = 0;
            SinglyLinkedListNode ptr1 = head1, ptr2 = head2;
            while (ptr1.Next != null)
            {
                len1++;
                ptr1 = ptr1.Next;
            }

            while (ptr2.Next != null)
            {
                len2++;
                ptr2 = ptr2.Next;
            }

            if (ptr1 != ptr2)
            {
                return null;
            }

            ptr1 = head1;
            ptr2 = head2;
            if (len1 > len2)
            {
                for (int i = 0; i < len1 - len2; i++)
                {
                    ptr1 = ptr1.Next;
                }
            }
            else
            {
                for (int i = 0; i < len2 - len1; i++)
                {
                    ptr2 = ptr2.Next;
                }
            }

            while (ptr1 != ptr2 && ptr1 != null && ptr2 != null)
            {
                ptr1 = ptr1.Next;
                ptr2 = ptr2.Next;
            }

            return ptr1;
        }
    }
}
