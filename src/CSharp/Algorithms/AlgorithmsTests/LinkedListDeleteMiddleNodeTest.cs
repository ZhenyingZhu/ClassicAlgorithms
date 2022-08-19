using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListDeleteMiddleNodeTest
    {
        [TestMethod]
        public void TestDeleteMiddleNode()
        {
            SinglyLinkedListNode head1 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 3 });
            SinglyLinkedListNode node2 = head1.Next;

            SinglyLinkedListNode res = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 3 });

            LinkedListDeleteMiddleNode.DeleteMiddleNodeWithHeadAccess(head1, node2);
            TestUtils.CompareSinglyLinkedLists(head1, res);
        }
    }
}
