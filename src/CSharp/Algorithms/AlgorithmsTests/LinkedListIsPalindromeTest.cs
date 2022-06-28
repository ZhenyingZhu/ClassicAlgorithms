using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class LinkedListIsPalindromeTest
    {
        [TestMethod]
        public void TestPalindrome()
        {
            SinglyLinkedListNode head1 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 1 });
            Assert.IsTrue(LinkedListIsPalindrome.PalindromeReverse(head1));

            SinglyLinkedListNode head2 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 1 });
            Assert.IsTrue(LinkedListIsPalindrome.PalindromeReverse(head2));

            SinglyLinkedListNode head3 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 2, 1 });
            Assert.IsTrue(LinkedListIsPalindrome.PalindromeReverse(head3));

            SinglyLinkedListNode head4 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 3 });
            Assert.IsFalse(LinkedListIsPalindrome.PalindromeReverse(head4));

            SinglyLinkedListNode head5 = SinglyLinkedListNode.CreateLinkedList(new List<int> { 1, 2, 3, 1 });
            Assert.IsFalse(LinkedListIsPalindrome.PalindromeReverse(head5));
        }
    }
}
