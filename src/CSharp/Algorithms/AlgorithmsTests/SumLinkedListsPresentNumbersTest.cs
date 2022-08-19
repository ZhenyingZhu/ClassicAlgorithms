using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class SumLinkedListsPresentNumbersTest
    {
        [TestMethod]
        public void TestSumListsReverse()

        {
            SinglyLinkedListNode head1 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 9, 1 });
            SinglyLinkedListNode head2 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 9, 1, 1 });
            SinglyLinkedListNode res = SumLinkedListsPresentNumbers.SumListsReverse(head1, head2);
            SinglyLinkedListNode expect = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 0, 0, 2 });
            TestUtils.CompareSinglyLinkedLists(res, expect);
        }
    }
}
