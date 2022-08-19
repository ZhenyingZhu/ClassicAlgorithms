using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListReturnKthToLastTest
    {
        [TestMethod]
        public void TestReturnKthToLast()
        {
            SinglyLinkedListNode head = SinglyLinkedListNode.CreateLinkedList(new List<int> { 3, 2, 1 });
            SinglyLinkedListNode node1 = LinkedListReturnKthToLast.ReturnKthToLast(head, 1);
            Assert.AreEqual(node1.Data, 1);
            SinglyLinkedListNode node2 = LinkedListReturnKthToLast.ReturnKthToLast(head, 2);
            Assert.AreEqual(node2.Data, 2);
            SinglyLinkedListNode node3 = LinkedListReturnKthToLast.ReturnKthToLast(head, 3);
            Assert.AreEqual(node3.Data, 3);
            SinglyLinkedListNode node4 = LinkedListReturnKthToLast.ReturnKthToLast(head, 4);
            Assert.AreEqual(node4.Data, 3);
        }
    }
}
