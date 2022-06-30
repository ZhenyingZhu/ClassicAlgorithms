using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListLoopDetectionTest
    {
        [TestMethod]
        public void TestLoopDetection()
        {
            SinglyLinkedListNode head = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 3, 4, 5 });
            head.Next.Next.Next.Next.Next = head.Next.Next;

            SinglyLinkedListNode loop = LinkedListLoopDetection.LoopDetection(head);
            Assert.AreEqual(loop, head.Next.Next);
        }
    }
}
