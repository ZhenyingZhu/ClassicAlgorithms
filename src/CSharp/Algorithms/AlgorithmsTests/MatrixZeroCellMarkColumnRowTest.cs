using System;
using System.Collections.Generic;
using System.Text;
using Algorithms;
using Microsoft.VisualStudio.TestTools.UnitTesting;

namespace AlgorithmsTests
{
    [TestClass]
    public class MatrixZeroCellMarkColumnRowTest
    {
        [TestMethod]
        public void TestZeroMatrixInPlace()
        {
            int[][] matrix1 = TestUtils.CraftMatrix(3, 4);
            matrix1[0][1] = 0;
            matrix1[1][2] = 0;
            int[][] matrix2 = TestUtils.CraftMatrix(3, 4);
            matrix2[0][1] = 0;
            matrix2[1][2] = 0;

            MatrixZeroCellMarkColumnRow.ZeroMatrixTwoIndicators(matrix1);
            MatrixZeroCellMarkColumnRow.ZeroMatrixInPlace(matrix2);

            TestUtils.CompareMatrix(matrix1, matrix2);
        }
    }
}
