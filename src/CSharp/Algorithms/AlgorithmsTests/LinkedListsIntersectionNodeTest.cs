using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListsIntersectionNodeTest
    {
        [TestMethod]
        public void TestIntersectionCountLength()
        {
            SinglyLinkedListNode head1 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 3, 4, 5 });
            SinglyLinkedListNode head2 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 6, 7, 8, 9 });

            SinglyLinkedListNode res = LinkedListsIntersectionNode.IntersectionCountLength(head1, head2);
            Assert.IsNull(res);

            SinglyLinkedListNode intersect = head1.Next.Next;
            head2.Next.Next.Next.Next = intersect;
            res = LinkedListsIntersectionNode.IntersectionCountLength(head1, head2);
            Assert.AreEqual(res, intersect);
        }
    }
}
