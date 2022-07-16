﻿using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Linq;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Algorithms.Utils;

namespace AlgorithmsTests
{
    [TestClass]
    public class BinaryTreeFirstCommonAncestorTest
    {
        [TestMethod]
        public void TestCreateTree()
        {
            int[] preOder = { 1, 2, 4, 3, 5 }, inOrder = { 4, 2, 1, 5, 3 };
            BinaryTree tree = BinaryTree.GenerateBinaryTree(preOder, inOrder);
            TestUtils.ComparePreOrderTraverse(tree, preOder.ToList());
            TestUtils.CompareInOrderTraverse(tree, inOrder.ToList());

            preOder = new int[] { 1, 2, 4, 5, 3 };
            inOrder = new int[] { 4, 2, 5, 1, 3 };
            tree = BinaryTree.GenerateBinaryTree(preOder, inOrder);
            TestUtils.ComparePreOrderTraverse(tree, preOder.ToList());
            TestUtils.CompareInOrderTraverse(tree, inOrder.ToList());
        }
    }
}
