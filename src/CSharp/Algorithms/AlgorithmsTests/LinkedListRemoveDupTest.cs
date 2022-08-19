using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListRemoveDupTest
    {
        [TestMethod]
        public void TestRemoveDup()
        {
            SinglyLinkedListNode head = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 1, 3, 2 });
            SinglyLinkedListNode expected = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 3 });
            SinglyLinkedListNode res = LinkedListRemoveDup.RemoveDupsWithBuffer(head);

            TestUtils.CompareSinglyLinkedLists(expected, res);
        }
    }
}
