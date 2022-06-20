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
            int[][] m4 = TestUtils.CraftMatrix(4, 4);
            int[][] res1 = RotateMatrix.RotateMatrixBruteForce(m4);
            RotateMatrix.RotateMatrixInPlace(m4);
            TestUtils.CompareMatrix(m4, res1);

            int[][] m5 = TestUtils.CraftMatrix(5, 5);
            int[][] res2 = RotateMatrix.RotateMatrixBruteForce(m5);
            RotateMatrix.RotateMatrixInPlace(m5);
            TestUtils.CompareMatrix(m5, res2);
        }

    }
}
