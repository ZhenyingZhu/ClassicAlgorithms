using System;
using System.Collections.Generic;
using System.Text;

namespace Algorithms.Utils
{
    public class SinglyLinkedListNode
    {
        public int Data { get; set; }
        public SinglyLinkedListNode Next { get; set; }

        public SinglyLinkedListNode(int d)
        {
            this.Data = d;
            this.Next = null;
        }

        public static SinglyLinkedListNode CreateLinkedList(List<int> nodeData)
        {
            SinglyLinkedListNode preHead = new SinglyLinkedListNode(0);
            SinglyLinkedListNode cur = preHead;
            foreach (int d in nodeData)
            {
                SinglyLinkedListNode newNode = new SinglyLinkedListNode(d);
                cur.Next = newNode;
                cur = cur.Next;
            }

            return preHead.Next;
        }
    }
}
