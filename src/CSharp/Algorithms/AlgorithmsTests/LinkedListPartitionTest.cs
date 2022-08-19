using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListPartitionTest
    {
        [TestMethod]
        public void TestPartitionTwoLists()
        {
            List<int> nodes = new List<int>{ 3, 4, 2, 5, 2 };
            SinglyLinkedListNode head = SinglyLinkedListNode.CreateLinkedList(nodes);
            SinglyLinkedListNode res = LinkedListPartition.PartitionTwoLists(head, 2);
            CheckPartition(res, nodes, 2);
        }

        private static void CheckPartition(SinglyLinkedListNode head, List<int> nodes, int val)
        {
            bool largerOrEqual = false;
            while (head != null)
            {
                nodes.Remove(head.Data);
                if (head.Data >= val)
                {
                    largerOrEqual = true;
                }
                else
                {
                    Assert.IsFalse(largerOrEqual);
                }

                head = head.Next;
            }

            Assert.AreEqual(0, nodes.Count);
        }
    }
}
