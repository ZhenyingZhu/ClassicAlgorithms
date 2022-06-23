using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.Text;
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
    }
}
