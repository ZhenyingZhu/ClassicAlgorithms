using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class RotateMatrixTest
    {
        [TestMethod]
        public void TestRotateMatrixInPlace()
        {
            int[][] m4 = CraftMatrix(4);
            int[][] res1 = RotateMatrix.RotateMatrixBruteForce(m4);
            RotateMatrix.RotateMatrixInPlace(m4);
            CompareMatrix(m4, res1);

            int[][] m5 = CraftMatrix(5);
            int[][] res2 = RotateMatrix.RotateMatrixBruteForce(m5);
            RotateMatrix.RotateMatrixInPlace(m5);
            CompareMatrix(m5, res2);
        }

        private static int[][] CraftMatrix(int n)
        {
            int[][] matrix = new int[n][];

            for (int i = 0; i < n; i++)
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

        private static void CompareMatrix(int[][] matrix1, int[][] matrix2)
        {
            for (int i = 0; i < matrix1.Length; i++)
            {
                for (int j = 0; j < matrix1.Length; j++)
                {
                    Assert.AreEqual(matrix1[i][j], matrix2[i][j]);
                }
            }
        }
    }
}
