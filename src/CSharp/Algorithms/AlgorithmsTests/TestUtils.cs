using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Text;
using System.Linq;
using Algorithms.Utils;

namespace AlgorithmsTests
{
    internal class TestUtils
    {
        internal static int[][] CraftMatrix(int m, int n)
        {
            int[][] matrix = new int[m][];

            for (int i = 0; i < m; i++)
            {
                matrix[i] = new int[n];
                {
                    for (int j = 0; j < n; j++)
                    {
                        matrix[i][j] = i * n + j;
                    }
                }
            }

            return matrix;
        }

        internal static void CompareMatrix(int[][] matrix1, int[][] matrix2)
        {
            for (int i = 0; i < matrix1.Length; i++)
            {
                for (int j = 0; j < matrix1[i].Length; j++)
                {
                    Assert.AreEqual(matrix1[i][j], matrix2[i][j]);
                }
            }
        }

        internal static void CompareSinglyLinkedLists(SinglyLinkedListNode head1, SinglyLinkedListNode head2)
        {
            while (head1 != null && head2 != null)
            {
                Assert.AreEqual(head1.Data, head2.Data);
                head1 = head1.Next;
                head2 = head2.Next;
            }

            Assert.IsNull(head1);
            Assert.IsNull(head2);
        }

        internal static void CompareInOrderTraverse(BinaryTree binaryTree, List<int> result)
        {
            List<int> inOrder = new List<int>();
            InOrderTraverse(binaryTree.Root, inOrder);
            for (int i = 0; i < inOrder.Count; i++)
            {
                Assert.AreEqual(inOrder[i], result[i]);
            }
        }

        private static void InOrderTraverse(BinaryTreeNode node, List<int> res)
        {
            if (node.LeftChild != null)
            {
                InOrderTraverse(node.LeftChild, res);
            }

            res.Add(node.Id);

            if (node.RightChild != null)
            {
                InOrderTraverse(node.RightChild, res);
            }
        }

        internal static void ComparePreOrderTraverse(BinaryTree binaryTree, List<int> result)
        {
            List<int> preOrder = new List<int>();
            PreOrderTraverse(binaryTree.Root, preOrder);
            for (int i = 0; i < preOrder.Count; i++)
            {
                Assert.AreEqual(preOrder[i], result[i]);
            }
        }

        private static void PreOrderTraverse(BinaryTreeNode node, List<int> res)
        {
            res.Add(node.Id);

            if (node.LeftChild != null)
            {
                PreOrderTraverse(node.LeftChild, res);
            }

            if (node.RightChild != null)
            {
                PreOrderTraverse(node.RightChild, res);
            }
        }
    }
}
